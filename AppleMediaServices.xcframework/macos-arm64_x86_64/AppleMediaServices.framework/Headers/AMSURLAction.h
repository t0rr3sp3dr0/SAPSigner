//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSURLAction_h
#define _AMSURLAction_h

@import Foundation;

#include "AMSAuthenticateResult.h"
#include "AMSDialogResult.h"

@interface AMSURLAction : NSObject <NSSecureCoding>

@property (retain) AMSAuthenticateResult *authenticateResult;
@property (retain) AMSDialogResult *dialogResult;
@property (retain) NSDictionary *updatedHeaders;
@property (retain) NSData *updatedBody;
@property (retain) NSString *updatedMethod;
@property (readonly) long long actionType;
@property (retain) NSString *updatedBuyParams;
@property (readonly) NSError *error;
@property (retain) NSString *reason;
@property (readonly) NSURL *redirectURL;
@property (retain) NSString *retryIdentifier;

/* class methods */
+ (signed char)supportsSecureCoding;
+ (id)actionWithError:(id)error;
+ (id)proceedAction;
+ (id)redirectActionWithURL:(id)url;
+ (id)retryAction;

/* instance methods */
- (id)description;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)initWithType:(long long)type;
- (id)initWithType:(long long)type error:(id)error reason:(id)reason redirectURL:(id)url;

@end

#endif /* _AMSURLAction_h */
