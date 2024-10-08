//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBagActiveAccountProvider_h
#define _AMSBagActiveAccountProvider_h

@import Foundation;

#include "ACAccount.h"
#include "AMSBagAccountProvider-Protocol.h"
#include "os_unfair_lock_s.h"

@interface AMSBagActiveAccountProvider : NSObject <AMSBagAccountProvider>

@property (nonatomic) struct os_unfair_lock_s accountLock;
@property (retain, nonatomic) ACAccount *previouslyAccessedAccount;
@property (retain) ACAccount *account;
@property (readonly) NSString *identity;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (id)_bagStorefrontForAccountMediaType:(id)type account:(id)account;

/* instance methods */
- (id)init;
- (id)_bagAccountPromiseForAccountMediaType:(id)type mustContainStorefront:(signed char)storefront;
- (signed char)associatedAccountIsEqualToAccount:(id)account forMediaType:(id)type;
- (id)bagAccountForAccountMediaType:(id)type;
- (id)bagAccountPromiseForAccountMediaType:(id)type;
- (id)bagStorefrontForAccountMediaType:(id)type;
- (id)bagStorefrontPromiseForAccountMediaType:(id)type;

@end

#endif /* _AMSBagActiveAccountProvider_h */
