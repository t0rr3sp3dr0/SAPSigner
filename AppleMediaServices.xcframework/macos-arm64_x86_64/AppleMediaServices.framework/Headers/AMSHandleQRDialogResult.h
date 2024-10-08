//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSHandleQRDialogResult_h
#define _AMSHandleQRDialogResult_h

@import Foundation;

@interface AMSHandleQRDialogResult : NSObject

/* class methods */
+ (id)_dismissalIdentifierFromDialogResult:(id)result;
+ (signed char)_isDismissQRDialogEnabled;
+ (void)_observeQRDialogDismissalNotificationForIdentifier:(id)identifier dialog:(id)dialog;
+ (void)_removeQRDialogDismissalObserverForIdentifier:(id)identifier;
+ (void)handleQRDialogPresentationForRequest:(id)request result:(id)result logKey:(id)key;

@end

#endif /* _AMSHandleQRDialogResult_h */
