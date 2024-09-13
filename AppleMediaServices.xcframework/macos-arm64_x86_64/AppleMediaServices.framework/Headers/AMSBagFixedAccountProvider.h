//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBagFixedAccountProvider_h
#define _AMSBagFixedAccountProvider_h

@import Foundation;

#include "ACAccount.h"
#include "AMSBagAccountProvider-Protocol.h"

@interface AMSBagFixedAccountProvider : NSObject <AMSBagAccountProvider>

@property (retain) ACAccount *account;
@property (readonly) NSString *identity;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* instance methods */
- (id)initWithAccount:(id)account;
- (signed char)associatedAccountIsEqualToAccount:(id)account forMediaType:(id)type;
- (id)bagAccountForAccountMediaType:(id)type;
- (id)bagAccountPromiseForAccountMediaType:(id)type;
- (id)bagStorefrontForAccountMediaType:(id)type;
- (id)bagStorefrontPromiseForAccountMediaType:(id)type;

@end

#endif /* _AMSBagFixedAccountProvider_h */