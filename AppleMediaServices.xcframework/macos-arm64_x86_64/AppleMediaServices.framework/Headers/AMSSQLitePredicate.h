//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSSQLitePredicate_h
#define _AMSSQLitePredicate_h

@import Foundation;

@interface AMSSQLitePredicate : NSObject <NSCopying>

/* instance methods */
- (id)copyWithZone:(struct _NSZone *)zone;
- (unsigned long long)hash;
- (signed char)isEqual:(id)equal;
- (id)SQLForEntityClass:(Class)_class;
- (id)SQLJoinClausesForEntityClass:(Class)_class;
- (void)applyBinding:(id)binding atIndex:(inout int *)index;

@end

#endif /* _AMSSQLitePredicate_h */