//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSPurchaseSIWA_h
#define _AMSPurchaseSIWA_h

@import Foundation;

#include "AMSPurchase.h"

@class AKAppleIDAuthenticationContext;

@interface AMSPurchaseSIWA : AMSPurchase <NSCopying, NSSecureCoding>

@property (retain) AKAppleIDAuthenticationContext *authenticationContext;
@property (copy) NSString *bundleID;
@property (copy) NSString *serviceID;
@property (copy) NSString *teamID;

/* class methods */
+ (signed char)supportsSecureCoding;

/* instance methods */
- (id)copyWithZone:(struct _NSZone *)zone;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)appProvidedData;
- (id)initWithPurchaseType:(long long)type buyParams:(id)params;
- (id)authenticationContextForRequest:(id)request;

@end

#endif /* _AMSPurchaseSIWA_h */