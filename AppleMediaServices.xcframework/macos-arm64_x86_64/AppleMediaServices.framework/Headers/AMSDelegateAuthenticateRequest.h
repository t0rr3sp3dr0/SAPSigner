//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSDelegateAuthenticateRequest_h
#define _AMSDelegateAuthenticateRequest_h

@import Foundation;

@interface AMSDelegateAuthenticateRequest : NSObject <NSSecureCoding>

@property (copy) NSString *challenge;
@property (copy) NSString *userAgent;

/* class methods */
+ (signed char)supportsSecureCoding;
+ (id)preferredUserAgent;

/* instance methods */
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)initWithChallenge:(id)challenge userAgent:(id)agent;

@end

#endif /* _AMSDelegateAuthenticateRequest_h */
