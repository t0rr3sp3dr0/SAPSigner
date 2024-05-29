//
//  base64.c
//  SAPSigner
//
//  Created by Pedro Tôrres on 2024-05-28.
//

#include <assert.h>
#include <limits.h>

#include <sasl/saslutil.h>

#include "base64.h"

int base64_encode(const char *in_buf, unsigned long in_len, char *out_buf, unsigned long out_cap, unsigned long *out_len) {
    assert(in_len <= UINT_MAX);
    assert(out_cap <= UINT_MAX);
    *out_len = 0;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    return sasl_encode64(in_buf, (unsigned int) in_len, out_buf, (unsigned int) out_cap, (unsigned int *) out_len);
#pragma clang diagnostic pop
}

int base64_decode(const char *in_buf, unsigned long in_len, char *out_buf, unsigned long out_cap, unsigned long *out_len) {
    assert(in_len <= UINT_MAX);
    assert(out_cap <= UINT_MAX);
    *out_len = 0;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    return sasl_decode64(in_buf, (unsigned int) in_len, out_buf, (unsigned int) out_cap, (unsigned int *) out_len);
#pragma clang diagnostic pop
}
