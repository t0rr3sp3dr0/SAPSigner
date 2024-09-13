//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSEngagementRequest_h
#define _AMSEngagementRequest_h

@import Foundation;

#include "ACAccount.h"

@interface AMSEngagementRequest : NSObject <NSSecureCoding>

@property (retain) NSData *modelData;
@property (retain) ACAccount *account;
@property signed char anonymousMetrics;
@property (retain) NSDictionary *clientData;
@property (retain) NSString *logKey;
@property signed char failOnDismiss;
@property (retain) NSDictionary *metricsOverlay;
@property (retain) NSURL *originatingURL;
@property long long presentationStyle;
@property (retain) NSURL *URL;
@property signed char silentlyCheckURL;
@property long long destinationStyle;
@property signed char suppressInteractiveModalDismissal;

/* class methods */
+ (signed char)supportsSecureCoding;

/* instance methods */
- (id)init;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)initWithModel:(id)model;
- (id)initWithJSONDictionary:(id)jsondictionary;
- (id)initWithModel:(id)model destinationStyle:(long long)style;
- (id)_accountFromDictionary:(id)dictionary;
- (long long)_engagementPresentationStyleFromDictionary:(id)dictionary;
- (id)initWithRequestDictionary:(id)dictionary;
- (id)modelForClass:(Class)_class error:(id *)error;

@end

#endif /* _AMSEngagementRequest_h */