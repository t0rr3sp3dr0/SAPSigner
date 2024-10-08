//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSURLMetricsLoadURLHandler_h
#define _AMSURLMetricsLoadURLHandler_h

@import Foundation;

#include "AMSURLProtocolDelegate-Protocol.h"

@interface AMSURLMetricsLoadURLHandler : NSObject <AMSURLProtocolDelegate>

@property (readonly) Class metricsClass;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* instance methods */
- (id)init;
- (id)initWithMetrics:(Class)metrics;
- (void)_enqueueLoadURLEvent:(id)urlevent forContext:(id)context;
- (id)_reportMetricsForContext:(id)context;
- (void)reportMetricsForContext:(id)context;

@end

#endif /* _AMSURLMetricsLoadURLHandler_h */
