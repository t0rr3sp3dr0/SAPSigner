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

#endif /* mescal_h */
