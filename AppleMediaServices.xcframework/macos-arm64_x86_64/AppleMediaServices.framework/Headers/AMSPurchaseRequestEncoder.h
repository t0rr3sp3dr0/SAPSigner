//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSPurchaseRequestEncoder_h
#define _AMSPurchaseRequestEncoder_h

@import Foundation;

#include "AMSBagProtocol-Protocol.h"
#include "AMSPurchaseInfo.h"
#include "AMSURLRequestEncoder.h"

@protocol OS_dispatch_queue;

@interface AMSPurchaseRequestEncoder : AMSURLRequestEncoder {
    /* instance variables */
    id <AMSBagProtocol> _bag;
}

@property (readonly) AMSPurchaseInfo *purchaseInfo;
@property (retain) NSObject<OS_dispatch_queue> *purchaseRequestQueue;

/* class methods */
+ (signed char)isRedirectBagURLOverrideEnabled;
+ (long long)_anisetteTypeFromAccount:(id)account;
+ (id)_bagURLKeysForPurchaseType:(long long)type withProductType:(id)type purchase:(id)purchase prefix:(id)prefix;
+ (id)_bagURLKeysFromPurchaseInfo:(id)info;
+ (id)_buyProductURLKeysForProductType:(id)type prefix:(id)prefix;
+ (id)_parametersFromPurchaseInfo:(id)info error:(id *)error;
+ (id)bagURLFromPurchaseInfo:(id)info bag:(id)bag error:(id *)error;
+ (void)configureRequest:(id)request purchaseInfo:(id)info bag:(id)bag error:(id *)error;

/* instance methods */
- (id)bag;
- (void)setBag:(id)bag;
- (id)encodeRequest;
- (id)initWithPurchaseInfo:(id)info;
- (id)initWithPurchaseInfo:(id)info bag:(id)bag;

@end

#endif /* _AMSPurchaseRequestEncoder_h */
