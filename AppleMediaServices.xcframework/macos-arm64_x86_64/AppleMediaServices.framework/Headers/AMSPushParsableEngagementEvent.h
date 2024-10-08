//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSPushParsableEngagementEvent_h
#define _AMSPushParsableEngagementEvent_h

@import Foundation;

#include "AMSPushParsable-Protocol.h"

@interface AMSPushParsableEngagementEvent : NSObject <AMSPushParsable>

@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (id)_eventForMapiPayload:(id)payload account:(id)account bag:(id)bag;
+ (id)_eventForStaticAssetPayload:(id)payload bag:(id)bag;
+ (void)_waitForPromises:(id)promises completion:(id /* block */)completion;
+ (void)handleNotificationPayload:(id)payload config:(id)config bag:(id)bag;
+ (signed char)shouldSkipAccountCheck;

@end

#endif /* _AMSPushParsableEngagementEvent_h */
