//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSSetItem_h
#define _AMSSetItem_h

@import Foundation;

@interface AMSSetItem : NSObject

@property (readonly) id object;
@property (readonly) NSString *hashKey;

/* class methods */
+ (id)setItemWithObject:(id)object hashKey:(id)key;

/* instance methods */
- (unsigned long long)hash;
- (signed char)isEqual:(id)equal;
- (id)initWithObject:(id)object hashKey:(id)key;

@end

#endif /* _AMSSetItem_h */
