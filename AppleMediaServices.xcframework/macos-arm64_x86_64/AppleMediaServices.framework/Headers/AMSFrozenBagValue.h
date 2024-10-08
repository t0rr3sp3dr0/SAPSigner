//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSFrozenBagValue_h
#define _AMSFrozenBagValue_h

@import Foundation;

#include "AMSBagDataSourceProtocol-Protocol.h"
#include "AMSBagValue.h"

@interface AMSFrozenBagValue : AMSBagValue

@property (retain) id <AMSBagDataSourceProtocol> dataSource;

/* instance methods */
- (id)initWithKey:(id)key value:(id)value valueType:(unsigned long long)type;

@end

#endif /* _AMSFrozenBagValue_h */
