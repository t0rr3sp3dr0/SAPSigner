//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMetricsFigaroBagConfguration_h
#define _AMSMetricsFigaroBagConfguration_h

@import Foundation;

#include "AMSMetricsFigaroEventModifier.h"

@protocol OS_dispatch_queue;

@interface AMSMetricsFigaroBagConfguration : NSObject

@property (readonly) NSDictionary *metricsDictionary;
@property (readonly) NSArray *overrides;
@property (readonly) AMSMetricsFigaroEventModifier *defaultModifier;
@property (readonly) NSObject<OS_dispatch_queue> *queue;

/* class methods */
+ (id)configurationPromiseWithBag:(id)bag;

/* instance methods */
- (void)prepareForFlush;
- (id)_generateModifiersIfNeeded;
- (id)initWithMetricsDictionary:(id)dictionary;
- (id)modifierForEvent:(id)event;

@end

#endif /* _AMSMetricsFigaroBagConfguration_h */
