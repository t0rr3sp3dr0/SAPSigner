//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMediaProtocolHandler_h
#define _AMSMediaProtocolHandler_h

@import Foundation;

#include "AMSMediaTokenServiceProtocol-Protocol.h"
#include "AMSURLProtocolHandler.h"

@interface AMSMediaProtocolHandler : AMSURLProtocolHandler

@property (readonly) id <AMSMediaTokenServiceProtocol> tokenService;

/* instance methods */
- (void)handleResponse:(id)response task:(id)task completionHandler:(id /* block */)handler;
- (id)initWithTokenService:(id)service;
- (void)reconfigureNewRequest:(id)request originalTask:(id)task redirect:(signed char)redirect error:(id *)error;

@end

#endif /* _AMSMediaProtocolHandler_h */