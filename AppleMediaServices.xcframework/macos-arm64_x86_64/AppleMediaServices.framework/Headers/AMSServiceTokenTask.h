//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSServiceTokenTask_h
#define _AMSServiceTokenTask_h

@import Foundation;

#include "ACAccount.h"
#include "ACAccountStore.h"
#include "AMSTask.h"

@interface AMSServiceTokenTask : AMSTask

@property (retain) Class authKitUpdateTaskClass;
@property (readonly) ACAccount *account;
@property (readonly) ACAccountStore *accountStore;
@property (readonly, copy) NSString *serviceIdentifier;
@property (readonly) signed char useCachedServiceToken;

/* instance methods */
- (id)perform;
- (id)_authKitUpdateTask;
- (id)initWithAccount:(id)account accountStore:(id)store serviceIdentifier:(id)identifier useCachedServiceToken:(signed char)token;
- (id)initWithAccount:(id)account serviceIdentifier:(id)identifier;
- (id)initWithAccount:(id)account serviceIdentifier:(id)identifier useCachedServiceToken:(signed char)token;
- (id)performAuthKitUpdate;

@end

#endif /* _AMSServiceTokenTask_h */
