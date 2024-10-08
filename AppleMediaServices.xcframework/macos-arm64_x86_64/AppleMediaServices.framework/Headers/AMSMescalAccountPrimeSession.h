//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMescalAccountPrimeSession_h
#define _AMSMescalAccountPrimeSession_h

@import Foundation;

#include "AMSBagProtocol-Protocol.h"
#include "AMSMescalSession.h"

@interface AMSMescalAccountPrimeSession : NSObject

@property (retain) id <AMSBagProtocol> bag;
@property (retain) AMSMescalSession *session;

/* instance methods */
- (id)initWithBag:(id)bag;
- (id)primeSignatureForData:(id)data;
- (id)signData:(id)data;
- (id)verifyPrimeSignature:(id)signature;

@end

#endif /* _AMSMescalAccountPrimeSession_h */
