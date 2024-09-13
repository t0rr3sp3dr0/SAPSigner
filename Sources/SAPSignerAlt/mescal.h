//
//  mescal.h
//  SAPSigner
//
//  Created by Pedro Tôrres on 2024-05-28.
//

#ifndef mescal_h
#define mescal_h

struct FPSAPContextOpaque_;

struct FairPlayHWInfo_ {
    unsigned int IDLength;
    unsigned char ID[20];
};

enum {
    FairPlaySAPExchangeVersionNotPrimed = 200,
    FairPlaySAPExchangeVersionPrimed = 210,
};

#define FairPlaySAPInit cp2g1b9ro
extern long FairPlaySAPInit(struct FPSAPContextOpaque_ **ctx, struct FairPlayHWInfo_ *hw_info);

#define FairPlaySAPExchange Mib5yocT
extern long FairPlaySAPExchange(unsigned int version, struct FairPlayHWInfo_ *hw_info, struct FPSAPContextOpaque_ *ctx, const char *in_buf, unsigned long in_len, char **out_buf, unsigned long *out_len, long *return_code);

#define FairPlayDisposeStorage jEHf8Xzsv8K
extern long FairPlayDisposeStorage(void *ptr);

#define FairPlaySAPSign Fc3vhtJDvr
extern long FairPlaySAPSign(struct FPSAPContextOpaque_ *ctx, const char *in_buf, unsigned long in_len, char **out_buf, unsigned long *out_len);

#define FairPlaySAPPrime jfkdDAjba3jd
extern long FairPlaySAPPrime(struct FPSAPContextOpaque_ *ctx, unsigned long _100 /* 0x64 */, const char *in_buf, unsigned long in_len, char **out_buf, unsigned long *out_len);

#define FairPlaySAPVerify gLg1CWr7p
extern long FairPlaySAPVerify(struct FPSAPContextOpaque_ *ctx, const char *in_buf, unsigned long in_len, char **out_buf /* NULL */, unsigned long *out_len /* NULL */);

#define FairPlaySAPTeardown IPaI1oem5iL
extern long FairPlaySAPTeardown(struct FPSAPContextOpaque_ *ctx);

#endif /* mescal_h */
