//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSURLDelegateProxy_h
#define _AMSURLDelegateProxy_h

@import Foundation;

@class AMSURLSession;

@interface AMSURLDelegateProxy : NSObject

@property (weak, nonatomic) AMSURLSession *session;
@property (weak) id delegate;

/* instance methods */
- (void)forwardInvocation:(id)invocation;
- (id)forwardingTargetForSelector:(SEL)selector;
- (id)methodSignatureForSelector:(SEL)selector;
- (signed char)respondsToSelector:(SEL)selector;
- (void)invalidate;
- (id)initWithSession:(id)session delegate:(id)delegate;

@end

#endif /* _AMSURLDelegateProxy_h */
