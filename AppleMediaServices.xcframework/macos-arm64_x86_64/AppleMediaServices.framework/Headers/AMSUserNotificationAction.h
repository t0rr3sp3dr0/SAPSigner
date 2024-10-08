//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSUserNotificationAction_h
#define _AMSUserNotificationAction_h

@import Foundation;

#include "AMSMetricsEvent.h"

@interface AMSUserNotificationAction : NSObject

@property (readonly) unsigned long long un_ActionOptions;
@property (retain) NSString *identifier;
@property (retain) NSURL *defaultURL;
@property (retain) NSString *title;
@property (retain) NSURLRequest *request;
@property (retain) NSString *systemImageName;
@property (copy) AMSMetricsEvent *metricsEvent;
@property (retain) NSDictionary *userInfo;
@property long long style;

/* instance methods */
- (id)init;
- (id)initWithTitle:(id)title;
- (id)generateUserInfoAction;
- (id)initWithTitle:(id)title style:(long long)style;
- (id)initWithUserInfoAction:(id)action;

@end

#endif /* _AMSUserNotificationAction_h */
