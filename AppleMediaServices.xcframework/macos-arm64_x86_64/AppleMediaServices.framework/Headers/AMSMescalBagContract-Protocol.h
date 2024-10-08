//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMescalBagContract_Protocol_h
#define _AMSMescalBagContract_Protocol_h

@import Foundation;

#include "AMSBagValue.h"
#include "AMSURLBagContract-Protocol.h"

@protocol AMSMescalBagContract <AMSURLBagContract>

@required

@property (readonly) AMSBagValue *mescalCertificateURL;
@property (readonly) AMSBagValue *mescalSetupURL;

@optional

@property (readonly) AMSBagValue *mescalPrimingURL;
@property (readonly) AMSBagValue *mescalSignedActions;
@property (readonly) AMSBagValue *mescalSignSapRequests;
@property (readonly) AMSBagValue *mescalSignSapResponses;

@end

#endif /* _AMSMescalBagContract_Protocol_h */
