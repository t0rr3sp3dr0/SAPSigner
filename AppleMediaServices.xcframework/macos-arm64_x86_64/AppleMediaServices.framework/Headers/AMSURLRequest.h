//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSURLRequest_h
#define _AMSURLRequest_h

@import Foundation;

#include "AMSURLRequestProperties.h"

@interface AMSURLRequest : NSMutableURLRequest <NSCopying, NSMutableCopying>

@property (retain) AMSURLRequestProperties *properties;

/* class methods */
+ (id)logableDescriptionForRequest:(id)request;

/* instance methods */
- (id)copyWithZone:(struct _NSZone *)zone;
- (id)description;
- (id)mutableCopyWithZone:(struct _NSZone *)zone;
- (id)initWithURL:(id)url cachePolicy:(unsigned long long)policy timeoutInterval:(double)interval;
- (id)_initWithCFURLRequest:(struct _CFURLRequest *)cfurlrequest;
- (id)initWithRequest:(id)request;
- (id)initWithRequest:(id)request bag:(id)bag;
- (id)initWithRequest:(id)request properties:(id)properties;

@end

#endif /* _AMSURLRequest_h */