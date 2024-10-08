//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSDelegateAuthenticateRequestTask_h
#define _AMSDelegateAuthenticateRequestTask_h

@import Foundation;

#include "ACAccount.h"
#include "AMSBagConsumer-Protocol.h"
#include "AMSTask.h"
#include "AMSURLProtocolDelegate-Protocol.h"

@interface AMSDelegateAuthenticateRequestTask : AMSTask <AMSURLProtocolDelegate, NSURLSessionDelegate, AMSBagConsumer>

@property (readonly) ACAccount *account;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (id)bagSubProfile;
+ (id)bagSubProfileVersion;
+ (id)createBagForSubProfile;

/* instance methods */
- (id)perform;
- (id)initWithAccount:(id)account;
- (id)_encodedURLRequest;

@end

#endif /* _AMSDelegateAuthenticateRequestTask_h */
