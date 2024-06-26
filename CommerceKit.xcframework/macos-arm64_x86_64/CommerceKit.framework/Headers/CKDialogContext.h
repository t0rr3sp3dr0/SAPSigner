//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tool: ld (951.9)
//    - LC_SOURCE_VERSION: 714.4.9.0.0
//
#ifndef CKDialogContext_h
#define CKDialogContext_h

@import AppKit;
@import Foundation;

@protocol AMSRequestPresentationDelegate; // @import AppleMediaServices;

@interface CKDialogContext : NSObject <NSCopying, AMSRequestPresentationDelegate>

@property int proxyPID;
@property (copy) NSURL *proxyBundleURL;
@property (weak) NSWindow *hostWindow;
@property (retain) NSImage *icon;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* instance methods */
- (id)copyWithZone:(struct _NSZone *)_zone;
- (id)_viewController;
- (void)handleDialogRequest:(id)_dialogRequest completion:(id /* block */)_completion;
- (void)handleAuthenticateRequest:(id)_authenticateRequest completion:(id /* block */)_completion;
- (signed char)_clickedButtonForModalResponse:(long long)_buttonForModalResponse;
- (id)_alertForDialog:(id)_forDialog;
- (void)displayDialog:(id)_dialog withCompletionHandler:(id /* block */)_completionHandler;

@end

#endif /* CKDialogContext_h */
