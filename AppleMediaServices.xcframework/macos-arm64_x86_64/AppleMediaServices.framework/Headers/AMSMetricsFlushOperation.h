//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMetricsFlushOperation_h
#define _AMSMetricsFlushOperation_h

@import Foundation;

#include "AMSMetricsFlushStrategy-Protocol.h"
#include "AMSMetricsOperation.h"
#include "AMSMutablePromise.h"

@interface AMSMetricsFlushOperation : AMSMetricsOperation

@property (readonly) id <AMSMetricsFlushStrategy> strategy;
@property (readonly) AMSMutablePromise *promise;

/* instance methods */
- (id)initWithStrategy:(id)strategy promise:(id)promise;

@end

#endif /* _AMSMetricsFlushOperation_h */
