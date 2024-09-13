//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSDialogResult_h
#define _AMSDialogResult_h

@import Foundation;

#include "AMSDialogRequest.h"

@interface AMSDialogResult : NSObject <NSSecureCoding>

@property (readonly) AMSDialogRequest *originalRequest;
@property (copy) NSString *selectedActionIdentifier;
@property (copy) NSArray *textfieldValues;
@property (retain) NSMutableDictionary *userInfo;

/* class methods */
+ (signed char)supportsSecureCoding;

/* instance methods */
- (id)description;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)initWithOriginalRequest:(id)request selectedActionIdentifier:(id)identifier;

@end

#endif /* _AMSDialogResult_h */