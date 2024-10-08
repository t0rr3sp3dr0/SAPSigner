//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSHTTPArchiveTaskInfo_h
#define _AMSHTTPArchiveTaskInfo_h

@import Foundation;

@interface AMSHTTPArchiveTaskInfo : NSObject <NSSecureCoding>

@property (readonly) NSURLSessionTaskMetrics *metrics;
@property (readonly) NSData *HTTPBody;
@property (readonly) NSData *responseData;

/* class methods */
+ (signed char)supportsSecureCoding;

/* instance methods */
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)initWithURLTaskInfo:(id)info;

@end

#endif /* _AMSHTTPArchiveTaskInfo_h */
