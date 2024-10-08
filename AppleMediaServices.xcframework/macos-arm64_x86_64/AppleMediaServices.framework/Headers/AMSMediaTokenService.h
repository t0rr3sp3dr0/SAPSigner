//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMediaTokenService_h
#define _AMSMediaTokenService_h

@import Foundation;

#include "ACAccount.h"
#include "AMSBagConsumer-Protocol.h"
#include "AMSBagProtocol-Protocol.h"
#include "AMSMediaToken.h"
#include "AMSMediaTokenServiceProtocol-Protocol.h"
#include "AMSMediaTokenServiceStore.h"
#include "AMSMediaTokenServiceThrottler.h"
#include "AMSProcessInfo.h"
#include "AMSURLSession.h"

@protocol OS_dispatch_queue;

@interface AMSMediaTokenService : NSObject <AMSBagConsumer, AMSMediaTokenServiceProtocol>

@property (retain) AMSMediaToken *cachedMediaToken;
@property (readonly) AMSMediaTokenServiceThrottler *throttler;
@property (readonly) NSObject<OS_dispatch_queue> *tokenFetchQueue;
@property (readonly) AMSMediaTokenServiceStore *tokenStore;
@property _Bool enabled;
@property double refreshPercentage;
@property double refreshTime;
@property signed char URLKnownToBeTrusted;
@property (retain) ACAccount *account;
@property (retain) id <AMSBagProtocol> bag;
@property long long clientType;
@property (readonly) NSString *clientIdentifier;
@property (retain) AMSProcessInfo *clientInfo;
@property (retain) NSString *keychainAccessGroup;
@property (weak) AMSURLSession *session;
@property (readonly) NSString *clientVersion;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (id)bagSubProfile;
+ (id)bagSubProfileVersion;
+ (id)_overrideOrClientIdentifier:(id)identifier;
+ (id)bagKeySet;
+ (id)createBagForSubProfile;

/* instance methods */
- (_Bool)isEnabled;
- (id)fetchMediaToken;
- (id)_fetchBagProperties;
- (id)_fetchToken;
- (void)_refreshMediaTokenIfNeeded:(id)needed;
- (signed char)_shouldRefreshMediaToken:(id)token;
- (signed char)_shouldReturnMediaToken:(id)token;
- (id)_tokenRequestWithError:(id *)error;
- (id)initWithClientIdentifier:(id)identifier bag:(id)bag;
- (id)initWithClientIdentifier:(id)identifier clientVersion:(id)version bag:(id)bag;
- (id)initWithClientIdentifier:(id)identifier keychainAccessGroup:(id)group bag:(id)bag;
- (id)initWithClientIdentifier:(id)identifier tokenStore:(id)store bag:(id)bag;
- (void)invalidateMediaToken;

@end

#endif /* _AMSMediaTokenService_h */
