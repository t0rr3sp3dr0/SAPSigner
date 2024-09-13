//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSFDSResult_h
#define _AMSFDSResult_h

@import Foundation;

@interface AMSFDSResult : NSObject <NSCopying, NSSecureCoding>

@property (readonly) unsigned long long action;
@property (copy) NSString *sessionIdentifier;
@property (readonly, copy) NSString *value;

/* class methods */
+ (signed char)supportsSecureCoding;

/* instance methods */
- (id)copyWithZone:(struct _NSZone *)zone;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)initWithValue:(id)value action:(unsigned long long)action;

@end

#endif /* _AMSFDSResult_h */