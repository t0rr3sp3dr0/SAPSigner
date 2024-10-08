//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSNSUserNotificationStrategy_h
#define _AMSNSUserNotificationStrategy_h

@import Foundation;

#include "AMSUserNotificationStrategy-Protocol.h"

@interface AMSNSUserNotificationStrategy : NSObject <NSUserNotificationCenterDelegate, AMSUserNotificationStrategy>

@property (retain) NSUserNotificationCenter *center;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (signed char)_badgeBundleId:(id)id increment:(signed char)increment error:(id *)error;
+ (id)_activeNotificationsWithCenterBundleId:(id)id;
+ (id)_centerForBundleId:(id)id;
+ (id)_postNotification:(id)notification bag:(id)bag centerBundleId:(id)id;
+ (id)_removeNotification:(id)notification centerBundleId:(id)id;
+ (id)_removeNotificationWithIdentifier:(id)identifier centerBundleId:(id)id logKey:(id)key scheduledOnly:(signed char)only;

/* instance methods */

@end

#endif /* _AMSNSUserNotificationStrategy_h */
