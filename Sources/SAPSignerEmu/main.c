//
//  main.c
//  SAPSigner
//
//  Created by Pedro Tôrres on 2024-05-27.
//

#include <stdio.h>
#include <string.h>

#include "base64.h"
#include "emulator.h"
#include "http.h"
#include "mescal.h"

static struct FairPlayHWInfo_ hw_info = {
    .IDLength = 6,
    .ID = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

int main(void) {
    long ret = 0;
    long err = 0;

    if ((ret = http_init())) {
        (void) fprintf(stderr, "http_init: ret=%ld", ret);
        return -1;
    }

    char *res_data = NULL;
    unsigned long res_size = 0;
    if ((ret = http_get("https://s.mzstatic.com/sap/setupCert.plist", &res_data, &res_size))) {
        (void) fprintf(stderr, "http_get: ret=%ld", ret);
        return -1;
    }

    char *data_b = NULL;
    if (!(data_b = strstr(res_data, "<data>"))) {
        (void) fprintf(stderr, "strstr 1: ret=0");
        return -1;
    }
    data_b += sizeof "<data>" - 1;

    char *data_e = NULL;
    if (!(data_e = strstr(res_data, "</data>"))) {
        (void) fprintf(stderr, "strstr 2: ret=0");
        return -1;
    }

    char sign_sap_setup_buffer_64data[4096] = { '\0' };
    unsigned long sign_sap_setup_buffer_64size = data_e - data_b;
    (void) strncpy(sign_sap_setup_buffer_64data, data_b, sign_sap_setup_buffer_64size);
    sign_sap_setup_buffer_64data[sign_sap_setup_buffer_64size] = '\0';

    char sign_sap_setup_buffer_idata[4096] = { '\0' };
    unsigned long sign_sap_setup_buffer_isize = 0;
    if ((ret = base64_decode(sign_sap_setup_buffer_64data, sign_sap_setup_buffer_64size, sign_sap_setup_buffer_idata, sizeof sign_sap_setup_buffer_idata, &sign_sap_setup_buffer_isize))) {
        (void) fprintf(stderr, "base64_decode: ret=%ld", ret);
        return -1;
    }
    sign_sap_setup_buffer_idata[sign_sap_setup_buffer_isize] = '\0';

    struct emulator emu = { NULL };
    if ((ret = emulator_new(&emu))) {
        (void) fprintf(stderr, "emulator_new: ret=%ld", ret);
        return -1;
    }

    // TODO(t0rr3sp3dr0): malloc internally
    size_t _ctx = 0;

    struct FPSAPContextOpaque_ *ctx = (struct FPSAPContextOpaque_ *) &_ctx;
    if ((ret = emulator_FairPlaySAPInit(&emu, &ctx, &hw_info))) {
        (void) fprintf(stderr, "emulator_FairPlaySAPInit: ret=%ld", ret);
        return -1;
    }

    // TODO(t0rr3sp3dr0): malloc internally
    char _sign_sap_setup_buffer_odata[8192] = "";

    char *sign_sap_setup_buffer_odata = _sign_sap_setup_buffer_odata;
    unsigned long sign_sap_setup_buffer_osize = 0;
    if ((ret = emulator_FairPlaySAPExchange(&emu, FairPlaySAPExchangeVersionNotPrimed, &hw_info, ctx, sign_sap_setup_buffer_idata, sign_sap_setup_buffer_isize, &sign_sap_setup_buffer_odata, &sign_sap_setup_buffer_osize, &err))) {
        (void) fprintf(stderr, "emulator_FairPlaySAPExchange 1: ret=%ld", ret);
        return -1;
    }
    if (err != 1) {
        (void) fprintf(stderr, "emulator_FairPlaySAPExchange 1: err=%ld", err);
        return -1;
    }

    if ((ret = base64_encode(sign_sap_setup_buffer_odata, sign_sap_setup_buffer_osize, sign_sap_setup_buffer_64data, sizeof sign_sap_setup_buffer_64data, &sign_sap_setup_buffer_64size))) {
        (void) fprintf(stderr, "base64_encode: ret=%ld", ret);
        return -1;
    }
    sign_sap_setup_buffer_64data[sign_sap_setup_buffer_64size] = '\0';

    // if (!emulator_FairPlayDisposeStorage(&emu, sign_sap_setup_buffer_odata)) {
    //     sign_sap_setup_buffer_odata = NULL;
    //     sign_sap_setup_buffer_osize = 0;
    // }

    char req_data[8192] = { '\0' };
    unsigned long req_size = 0;
    if ((ret = req_size = sprintf(req_data, "<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\"><plist version=\"1.0\"><dict><key>sign-sap-setup-buffer</key><data>%s</data></dict></plist>", sign_sap_setup_buffer_64data)) < 0) {
        (void) fprintf(stderr, "sprintf: ret=%ld", ret);
        return -1;
    }

    if ((ret = http_post("https://play.itunes.apple.com/WebObjects/MZPlay.woa/wa/signSapSetup", req_data, req_size, &res_data, &res_size))) {
        (void) fprintf(stderr, "http_post: ret=%ld", ret);
        return -1;
    }

    if (!(data_b = strstr(res_data, "<data>"))) {
        (void) fprintf(stderr, "strstr 1: ret=0");
        return -1;
    }
    data_b += sizeof "<data>" - 1;

    if (!(data_e = strstr(res_data, "</data>"))) {
        (void) fprintf(stderr, "strstr 2: ret=0");
        return -1;
    }

    sign_sap_setup_buffer_64size = data_e - data_b;
    (void) strncpy(sign_sap_setup_buffer_64data, data_b, sign_sap_setup_buffer_64size);
    sign_sap_setup_buffer_64data[sign_sap_setup_buffer_64size] = '\0';

    if ((ret = base64_decode(sign_sap_setup_buffer_64data, sign_sap_setup_buffer_64size, sign_sap_setup_buffer_idata, sizeof sign_sap_setup_buffer_idata, &sign_sap_setup_buffer_isize))) {
        (void) fprintf(stderr, "base64_decode: ret=%ld", ret);
        return -1;
    }
    sign_sap_setup_buffer_idata[sign_sap_setup_buffer_isize] = '\0';

    if ((ret = emulator_FairPlaySAPExchange(&emu, FairPlaySAPExchangeVersionNotPrimed, &hw_info, ctx, sign_sap_setup_buffer_idata, sign_sap_setup_buffer_isize, &sign_sap_setup_buffer_odata, &sign_sap_setup_buffer_osize, &err))) {
        (void) fprintf(stderr, "emulator_FairPlaySAPExchange 2: ret=%ld", ret);
        return -1;
    }
    if (err != 0) {
        (void) fprintf(stderr, "emulator_FairPlaySAPExchange 2: err=%ld", err);
        return -1;
    }

    (void) sign_sap_setup_buffer_odata;
    (void) sign_sap_setup_buffer_osize;

    // if (!emulator_FairPlayDisposeStorage(&emu, sign_sap_setup_buffer_odata)) {
    //     sign_sap_setup_buffer_odata = NULL;
    //     sign_sap_setup_buffer_osize = 0;
    // }

    char sign_sap_buffer_idata[8192] = { '\0' };
    unsigned long sign_sap_buffer_isize = fread(sign_sap_buffer_idata, sizeof(char), sizeof sign_sap_buffer_idata, stdin);
    if ((ret = ferror(stdin))) {
        (void) fprintf(stderr, "fread: ret=%ld", ret);
        return -1;
    }

    // TODO(t0rr3sp3dr0): malloc internally
    char _sign_sap_buffer_odata[8192] = "";

    char *sign_sap_buffer_odata = _sign_sap_buffer_odata;
    unsigned long sign_sap_buffer_osize = 0;
    if ((ret = emulator_FairPlaySAPSign(&emu, ctx, sign_sap_buffer_idata, sign_sap_buffer_isize, &sign_sap_buffer_odata, &sign_sap_buffer_osize))) {
        (void) fprintf(stderr, "emulator_FairPlaySAPSign: ret=%ld", ret);
        return -1;
    }

    (void) fwrite(sign_sap_buffer_odata, sizeof(char), sign_sap_buffer_osize, stdout);
    if ((ret = ferror(stdout))) {
        (void) fprintf(stderr, "fwrite: ret=%ld", ret);
        return -1;
    }

    // if (!emulator_FairPlayDisposeStorage(&emu, sign_sap_buffer_odata)) {
    //     sign_sap_buffer_odata = NULL;
    //     sign_sap_buffer_osize = 0;
    // }

    // if (!emulator_FairPlaySAPTeardown(&emu, ctx)) {
    //     ctx = NULL;
    // }

    // if ((ret = emulator_delete(&emu))) {
    //     (void) fprintf(stderr, "emulator_delete: ret=%ld", ret);
    //     return -1;
    // }

    // if ((ret = http_cleanup())) {
    //     (void) fprintf(stderr, "http_cleanup: ret=%ld", ret);
    //     return -1;
    // }

    return 0;
}
