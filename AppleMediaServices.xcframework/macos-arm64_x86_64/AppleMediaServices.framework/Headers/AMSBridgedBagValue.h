//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBridgedBagValue_h
#define _AMSBridgedBagValue_h

@import Foundation;

#include "AMSFrozenBagValue.h"
#include "AMSPromise.h"

@interface AMSBridgedBagValue : AMSFrozenBagValue

@property (retain) AMSPromise *valuePromise;

/* instance methods */
- (id)initWithKey:(id)key valueType:(unsigned long long)type valuePromise:(id)promise;
- (void)valueWithCompletion:(id /* block */)completion;

@end

#endif /* _AMSBridgedBagValue_h */
