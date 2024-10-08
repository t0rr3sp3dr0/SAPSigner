//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSPurchaseSIWAResult_h
#define _AMSPurchaseSIWAResult_h

@import Foundation;

#include "AMSPurchaseResult.h"
#include "AMSPurchaseSIWAAuthorizationResult.h"

@interface AMSPurchaseSIWAResult : NSObject <NSCopying, NSSecureCoding>

@property (readonly) AMSPurchaseResult *purchaseResult;
@property (readonly) AMSPurchaseSIWAAuthorizationResult *authorizationResult;

/* class methods */
+ (signed char)supportsSecureCoding;

/* instance methods */
- (id)copyWithZone:(struct _NSZone *)zone;
- (unsigned long long)hash;
- (signed char)isEqual:(id)equal;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)initWithPurchaseResult:(id)result authorizationResult:(id)result;
- (signed char)isEqualToPurchaseSIWAResult:(id)siwaresult;

@end

#endif /* _AMSPurchaseSIWAResult_h */
