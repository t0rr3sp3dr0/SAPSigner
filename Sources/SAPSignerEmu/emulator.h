//
//  emulator.h
//  SAPSigner
//
//  Created by Pedro Tôrres on 2024-06-13.
//

#ifndef emulator_h
#define emulator_h

#include "mescal.h"

struct emulator {
    void *uc;
};

int emulator_new(struct emulator *emu);

int emulator_delete(struct emulator *emu);

long emulator_FairPlaySAPInit(const struct emulator *emu, struct FPSAPContextOpaque_ **ctx, struct FairPlayHWInfo_ *hw_info);

long emulator_FairPlaySAPExchange(const struct emulator *emu, unsigned int version, struct FairPlayHWInfo_ *hw_info, struct FPSAPContextOpaque_ *ctx, const char *in_buf, unsigned long in_len, char **out_buf, unsigned long *out_len, long *return_code);

long emulator_FairPlaySAPSign(const struct emulator *emu, struct FPSAPContextOpaque_ *ctx, const char *in_buf, unsigned long in_len, char **out_buf, unsigned long *out_len);

#endif /* emulator_h */
