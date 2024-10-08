//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSSystemAlertDialogTask_h
#define _AMSSystemAlertDialogTask_h

@import Foundation;

#include "AMSDialogRequest.h"
#include "AMSDialogResult.h"
#include "AMSTask.h"

@interface AMSSystemAlertDialogTask : AMSTask

@property (retain) AMSDialogResult *autoDismissResult;
@property long long defaultButtonIndex;
@property signed char dismissOnHomeButton;
@property signed char dismissOnLock;
@property signed char shouldDismissAfterUnlock;
@property signed char shouldDisplayAsTopMost;
@property signed char shouldPendInSetupIfNotAllowed;
@property signed char displaysOnLockscreen;
@property long long unlockActionButtonIndex;
@property struct __CFUserNotification * userNotification;
@property signed char isDialogDismissalEnabled;
@property (readonly) AMSDialogRequest *request;

/* instance methods */
- (id)present;
- (id)initWithRequest:(id)request;
- (struct __CFDictionary *)_createNoteDictionaryWithKeys:(struct ButtonKey { struct __CFString *x0; int x1; } *)keys buttonActions:(id)actions outOptions:(unsigned long long *)options;
- (void)_dismiss;
- (id)_handleResponseForNote:(struct __CFUserNotification *)note buttonActions:(id)actions keys:(struct ButtonKey { struct __CFString *x0; int x1; } *)keys;
- (id)_reorderButtonActions;
- (struct __CFUserNotification *)_showNotificationFromDictionary:(struct __CFDictionary *)dictionary options:(unsigned long long)options;

@end

#endif /* _AMSSystemAlertDialogTask_h */
