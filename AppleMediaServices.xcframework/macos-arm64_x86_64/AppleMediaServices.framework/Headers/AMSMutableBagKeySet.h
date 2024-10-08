//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMutableBagKeySet_h
#define _AMSMutableBagKeySet_h

@import Foundation;

#include "AMSBagKeySet.h"

@interface AMSMutableBagKeySet : AMSBagKeySet

/* instance methods */
- (void)unionBagKeySet:(id)set;
- (void)addBagKey:(id)key valueType:(unsigned long long)type;
- (void)addBagKey:(id)key valueType:(unsigned long long)type defaultValue:(id)value;

@end

#endif /* _AMSMutableBagKeySet_h */
