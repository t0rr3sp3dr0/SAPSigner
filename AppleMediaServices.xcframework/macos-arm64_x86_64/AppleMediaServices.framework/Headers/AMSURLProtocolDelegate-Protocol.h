//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSURLProtocolDelegate_Protocol_h
#define _AMSURLProtocolDelegate_Protocol_h

@import Foundation;

@protocol AMSURLProtocolDelegate <NSObject>

@required

@optional

/* optional instance methods */
- (void)AMSURLSession:(id)amsurlsession handleDialogRequest:(id)request completion:(id /* block */)completion;
- (signed char)AMSURLSession:(id)amsurlsession shouldHandleAuthenticationForAccount:(id)account dialogDictionary:(id)dictionary;
- (void)AMSURLSession:(id)amsurlsession task:(id)task handleAuthenticateRequest:(id)request completion:(id /* block */)completion;
- (void)AMSURLSession:(id)amsurlsession task:(id)task handleEngagementRequest:(id)request completion:(id /* block */)completion;
- (id)presentingSceneBundleIdentifier;
- (void)AMSURLSession:(id)amsurlsession handleAuthenticateRequest:(id)request completion:(id /* block */)completion;
- (signed char)AMSURLSession:(id)amsurlsession shouldFailWithServerError:(id)error;
- (signed char)AMSURLSession:(id)amsurlsession shouldHandleDialogDictionary:(id)dictionary;
- (void)AMSURLSession:(id)amsurlsession task:(id)task handleDialogRequest:(id)request completion:(id /* block */)completion;
- (signed char)AMSURLSession:(id)amsurlsession task:(id)task shouldFailWithServerError:(id)error;
- (id)presentingSceneIdentifier;
- (void)reportMetricsForContext:(id)context;

@end

#endif /* _AMSURLProtocolDelegate_Protocol_h */
