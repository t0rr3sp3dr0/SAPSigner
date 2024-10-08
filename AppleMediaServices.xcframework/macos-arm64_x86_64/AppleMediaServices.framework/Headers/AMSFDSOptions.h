//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSFDSOptions_h
#define _AMSFDSOptions_h

@import Foundation;

#include "AMSProcessInfo.h"

@interface AMSFDSOptions : NSObject <NSCopying, NSSecureCoding>

@property unsigned long long action;
@property (readonly) NSString *bundleIdentifier;
@property (retain) AMSProcessInfo *clientInfo;

/* class methods */
+ (signed char)supportsSecureCoding;

/* instance methods */
- (id)copyWithZone:(struct _NSZone *)zone;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;

@end

#endif /* _AMSFDSOptions_h */
