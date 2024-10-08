//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSPurchaseInfo_h
#define _AMSPurchaseInfo_h

@import Foundation;

#include "ACAccount.h"
#include "AMSBuyParams.h"
#include "AMSProcessInfo.h"
#include "AMSPurchase.h"
#include "AMSPurchaseDelegate-Protocol.h"
#include "AMSPurchaseTask.h"

@class LAContext;

@interface AMSPurchaseInfo : NSObject

@property (retain) NSNumber *paymentMethodType;
@property (retain) ACAccount *account;
@property (weak) AMSPurchaseTask *activePurchaseTask;
@property (retain) NSMutableDictionary *additionalHeaders;
@property signed char addKBSync;
@property (retain) AMSBuyParams *buyParams;
@property (readonly) NSString *clientCorrelationKey;
@property (readonly) AMSProcessInfo *clientInfo;
@property (weak) id <AMSPurchaseDelegate> delegate;
@property (retain) NSDictionary *dialog;
@property (retain) NSString *dialogId;
@property (retain) NSNumber *expressCheckoutMode;
@property signed char hasBeenAuthedForBuy;
@property signed char hasRetriedOriginalOwnerAccount;
@property (retain) NSDictionary *idmsTokens;
@property (retain) LAContext *localAuthContext;
@property (retain) NSURL *paymentServicesURL;
@property (retain) NSString *paymentToken;
@property (readonly) AMSPurchase *purchase;

/* instance methods */
- (id)description;
- (id)_purchaseStringForType:(long long)type;
- (id)initWithPurchase:(id)purchase;

@end

#endif /* _AMSPurchaseInfo_h */
