//
//  base64.h
//  SAPSigner
//
//  Created by Pedro Tôrres on 2024-05-28.
//

#ifndef base64_h
#define base64_h

int base64_encode(const char *in_buf, unsigned long in_len, char *out_buf, unsigned long out_cap, unsigned long *out_len);

int base64_decode(const char *in_buf, unsigned long in_len, char *out_buf, unsigned long out_cap, unsigned long *out_len);

#endif /* base64_h */
