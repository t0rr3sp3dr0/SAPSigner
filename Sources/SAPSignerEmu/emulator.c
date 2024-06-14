//
//  emulator.c
//  SAPSigner
//
//  Created by Pedro Tôrres on 2024-06-13.
//

#include <stddef.h>
#include <string.h>

#include <unicorn/unicorn.h>

#include "emulator.h"
#include "libinterposer.dylib.__DATA.__data.h"
#include "libinterposer.dylib.__TEXT.__text.h"
#include "libmescal.dylib.__DATA.__const.h"
#include "libmescal.dylib.__DATA.__got.h"
#include "libmescal.dylib.__DATA.__la_symbol_ptr.h"
#include "libmescal.dylib.__TEXT.__const.h"
#include "libmescal.dylib.__TEXT.__stubs.h"
#include "libmescal.dylib.__TEXT.__text.h"

#define uc_do(function, ...)                                                                                           \
    do {                                                                                                               \
        uc_err err = UC_ERR_OK;                                                                                        \
        if ((err = function(__VA_ARGS__)) != UC_ERR_OK) {                                                              \
            fprintf(stderr, "%s(%s): %s\n", #function, #__VA_ARGS__, uc_strerror(err));                                \
            return -1;                                                                                                 \
        }                                                                                                              \
    } while (false)

#define uc_mem_write_literal(uc, address, bytes) uc_mem_write(uc, address, bytes, sizeof bytes)

int emulator_new(struct emulator *emu) {
    uc_engine *uc = NULL;
    uc_do(uc_open, UC_ARCH_X86, UC_MODE_64, &uc);

    emu->uc = uc;

    uint64_t rsp = 0x00007ff7bff00000;
    uc_do(uc_reg_write, uc, UC_X86_REG_RSP, &rsp);

    static unsigned char text[4096] = {
        0xFF, 0xD0, // callq  *%rax
        0xFF, 0xE5, // jmpq   *%rbp
    };
    uc_do(uc_mem_map_ptr, uc, 0x0000000100000000, sizeof text, UC_PROT_READ | UC_PROT_EXEC, text);

    // map libinterposer.dylib.__TEXT.__text
    uc_do(uc_mem_map, uc, 0x0000000100e45000, 0x0000000100e46000 - 0x0000000100e45000, UC_PROT_READ | UC_PROT_EXEC);
    uc_do(uc_mem_write_literal, uc, 0x0000000100e458f0, libinterposer$dylib$__TEXT$__text);

    // map libinterposer.dylib.__DATA.__data
    uc_do(uc_mem_map, uc, 0x0000000100e47000, 0x0000000100e48000 - 0x0000000100e47000, UC_PROT_READ | UC_PROT_WRITE);
    uc_do(uc_mem_write_literal, uc, 0x0000000100e47000, libinterposer$dylib$__DATA$__data);

    // map libinterposer.dylib.__DATA_HEAP.__data
    uc_do(uc_mem_map, uc, 0x0000000100e48000, 0x0000000101648000 - 0x0000000100e48000, UC_PROT_READ | UC_PROT_WRITE);

    // map libmescal.dylib.__TEXT.__text and libmescal.dylib.__TEXT.__stubs
    uc_do(uc_mem_map, uc, 0x0000000100966000, 0x0000000100b35000 - 0x0000000100966000, UC_PROT_READ | UC_PROT_EXEC);
    uc_do(uc_mem_write_literal, uc, 0x0000000100966330, libmescal$dylib$__TEXT$__text);
    uc_do(uc_mem_write_literal, uc, 0x0000000100b34a2e, libmescal$dylib$__TEXT$__stubs);

    // map libmescal.dylib.__TEXT.__const
    uc_do(uc_mem_map, uc, 0x0000000100b58000, 0x0000000100beb000 - 0x0000000100b58000, UC_PROT_READ | UC_PROT_EXEC);
    uc_do(uc_mem_write_literal, uc, 0x0000000100b58870, libmescal$dylib$__TEXT$__const);

    // map libmescal.dylib.__DATA.__got and libmescal.dylib.__DATA.__la_symbol_ptr
    uc_do(uc_mem_map, uc, 0x0000000100bee000, 0x0000000100bef000 - 0x0000000100bee000, UC_PROT_READ | UC_PROT_WRITE);
    uc_do(uc_mem_write_literal, uc, 0x0000000100bee010, libmescal$dylib$__DATA$__got);
    uc_do(uc_mem_write_literal, uc, 0x0000000100bee278, libmescal$dylib$__DATA$__la_symbol_ptr);

    // map libmescal.dylib.__DATA.__const
    uc_do(uc_mem_map, uc, 0x0000000100c11000, 0x0000000100c14000 - 0x0000000100c11000, UC_PROT_READ | UC_PROT_WRITE);
    uc_do(uc_mem_write_literal, uc, 0x0000000100c11170, libmescal$dylib$__DATA$__const);

    // map libmescal.dylib.__DATA.__common
    uc_do(uc_mem_map, uc, 0x0000000100c22000, 0x0000000100c23000 - 0x0000000100c22000, UC_PROT_READ | UC_PROT_WRITE);

    // map Stack
    uc_do(uc_mem_map, uc, 0x00007ff7bf700000, 0x00007ff7bff00000 - 0x00007ff7bf700000, UC_PROT_READ | UC_PROT_WRITE);

    // map kIOMasterPortDefault
    uc_do(uc_mem_map, uc, 0x00007ff81f3eb000, 0x00007ff81f3ec000 - 0x00007ff81f3eb000, UC_PROT_READ);

    // map __stack_chk_guard
    uc_do(uc_mem_map, uc, 0x00007ff85f292000, 0x00007ff85f293000 - 0x00007ff85f292000, UC_PROT_READ);

    return 0;
}

int emulator_delete(struct emulator *emu) {
    uc_engine *uc = emu->uc;

    uc_do(uc_close, uc);

    emu->uc = NULL;

    return 0;
}

long emulator_FairPlaySAPInit(const struct emulator *emu, struct FPSAPContextOpaque_ **ctx, struct FairPlayHWInfo_ *hw_info) {
    uc_engine *uc = emu->uc;

    struct data {
        struct FPSAPContextOpaque_ *ctx;
        struct FairPlayHWInfo_ hw_info;
    } __attribute__((aligned(4096))) data = {
        .ctx = *ctx,
        .hw_info = *hw_info,
    };

    uint64_t func_addr = 0x0000000100a099b0;
    uc_do(uc_reg_write, uc, UC_X86_REG_RAX, &func_addr);

    uint64_t base_addr = 0x00007ff7bff00000;
    uc_do(uc_mem_map_ptr, uc, base_addr, sizeof data, UC_PROT_ALL, &data);

    uint64_t arg0_addr = base_addr + offsetof(struct data, ctx);
    uc_do(uc_reg_write, uc, UC_X86_REG_RDI, &arg0_addr);

    uint64_t arg1_addr = base_addr + offsetof(struct data, hw_info);
    uc_do(uc_reg_write, uc, UC_X86_REG_RSI, &arg1_addr);

    uc_do(uc_emu_start, uc, 0x0000000100000000, 0x0000000000000000, 0, 0);

    uc_do(uc_mem_unmap, uc, base_addr, sizeof(struct data));

    uint64_t rax = 0;
    uc_do(uc_reg_read, uc, UC_X86_REG_RAX, &rax);

    *ctx = data.ctx;
    *hw_info = data.hw_info;

    return rax;
}

long emulator_FairPlaySAPExchange(const struct emulator *emu, unsigned int version, struct FairPlayHWInfo_ *hw_info, struct FPSAPContextOpaque_ *ctx, const char *in_buf, unsigned long in_len, char **out_buf, unsigned long *out_len, long *return_code) {
    uc_engine *uc = emu->uc;

    struct data {
        struct FairPlayHWInfo_ hw_info;
        char in_buf[8192];
        char *out_buf;
        unsigned long out_len;
        long return_code;
    } __attribute__((aligned(4096))) data = {
        .hw_info = *hw_info,
        .out_buf = *out_buf,
        .out_len = *out_len,
        .return_code = *return_code,
    };
    memcpy(data.in_buf, in_buf, in_len);

    uint64_t rsp = 0;
    uc_do(uc_reg_read, uc, UC_X86_REG_RSP, &rsp);

    rsp -= 2 * sizeof(uint64_t);
    uc_do(uc_reg_write, uc, UC_X86_REG_RSP, &rsp);

    uint64_t func_addr = 0x00000001009ee5d0;
    uc_do(uc_reg_write, uc, UC_X86_REG_RAX, &func_addr);

    uint64_t base_addr = 0x00007ff7bff00000;
    uc_do(uc_mem_map_ptr, uc, base_addr, sizeof data, UC_PROT_ALL, &data);

    uint64_t arg0_addr = version;
    uc_do(uc_reg_write, uc, UC_X86_REG_RDI, &arg0_addr);

    uint64_t arg1_addr = base_addr + offsetof(struct data, hw_info);
    uc_do(uc_reg_write, uc, UC_X86_REG_RSI, &arg1_addr);

    uint64_t arg2_addr = (uint64_t) ctx;
    uc_do(uc_reg_write, uc, UC_X86_REG_RDX, &arg2_addr);

    uint64_t arg3_addr = base_addr + offsetof(struct data, in_buf);
    uc_do(uc_reg_write, uc, UC_X86_REG_RCX, &arg3_addr);

    uint64_t arg4_addr = in_len;
    uc_do(uc_reg_write, uc, UC_X86_REG_R8, &arg4_addr);

    uint64_t arg5_addr = base_addr + offsetof(struct data, out_buf);
    uc_do(uc_reg_write, uc, UC_X86_REG_R9, &arg5_addr);

    uint64_t arg6_addr = base_addr + offsetof(struct data, out_len);
    uc_do(uc_mem_write, uc, rsp + 0 * sizeof(uint64_t), &arg6_addr, sizeof(uint64_t));

    uint64_t arg7_addr = base_addr + offsetof(struct data, return_code);
    uc_do(uc_mem_write, uc, rsp + 1 * sizeof(uint64_t), &arg7_addr, sizeof(uint64_t));

    uc_do(uc_emu_start, uc, 0x0000000100000000, 0x0000000000000000, 0, 0);

    uc_do(uc_mem_unmap, uc, base_addr, sizeof(struct data));

    rsp += 2 * sizeof(uint64_t);
    uc_do(uc_reg_write, uc, UC_X86_REG_RSP, &rsp);

    uint64_t rax = 0;
    uc_do(uc_reg_read, uc, UC_X86_REG_RAX, &rax);

    uc_do(uc_mem_read, uc, (uint64_t) data.out_buf, *out_buf, data.out_len);
    *out_len = data.out_len;
    *return_code = data.return_code;

    return rax;
}

long emulator_FairPlaySAPSign(const struct emulator *emu, struct FPSAPContextOpaque_ *ctx, const char *in_buf, unsigned long in_len, char **out_buf, unsigned long *out_len) {
    uc_engine *uc = emu->uc;

    struct data {
        char in_buf[8192];
        char *out_buf;
        unsigned long out_len;
    } __attribute__((aligned(4096))) data = {
        .out_buf = *out_buf,
        .out_len = *out_len,
    };
    memcpy(data.in_buf, in_buf, in_len);

    uint64_t func_addr = 0x0000000100a893f0;
    uc_do(uc_reg_write, uc, UC_X86_REG_RAX, &func_addr);

    uint64_t base_addr = 0x00007ff7bff00000;
    uc_do(uc_mem_map_ptr, uc, base_addr, sizeof data, UC_PROT_ALL, &data);

    uint64_t arg0_addr = (uint64_t) ctx;
    uc_do(uc_reg_write, uc, UC_X86_REG_RDI, &arg0_addr);

    uint64_t arg1_addr = base_addr + offsetof(struct data, in_buf);
    uc_do(uc_reg_write, uc, UC_X86_REG_RSI, &arg1_addr);

    uint64_t arg2_addr = in_len;
    uc_do(uc_reg_write, uc, UC_X86_REG_RDX, &arg2_addr);

    uint64_t arg3_addr = base_addr + offsetof(struct data, out_buf);
    uc_do(uc_reg_write, uc, UC_X86_REG_RCX, &arg3_addr);

    uint64_t arg4_addr = base_addr + offsetof(struct data, out_len);
    uc_do(uc_reg_write, uc, UC_X86_REG_R8, &arg4_addr);

    uc_do(uc_emu_start, uc, 0x0000000100000000, 0x0000000000000000, 0, 0);

    uc_do(uc_mem_unmap, uc, base_addr, sizeof(struct data));

    uint64_t rax = 0;
    uc_do(uc_reg_read, uc, UC_X86_REG_RAX, &rax);

    uc_do(uc_mem_read, uc, (uint64_t) data.out_buf, *out_buf, data.out_len);
    *out_len = data.out_len;

    return rax;
}
