//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBagDataSourceLoadResult_h
#define _AMSBagDataSourceLoadResult_h

@import Foundation;

@interface AMSBagDataSourceLoadResult : NSObject

@property (readonly) NSDictionary *data;
@property (readonly) NSDate *expirationDate;
@property (readonly) NSString *loadedBagIdentifier;
@property (readonly) NSString *loadedBagPartialIdentifier;

/* instance methods */
- (id)initWithData:(id)data expirationDate:(id)date loadedBagIdentifier:(id)identifier loadedBagPartialIdentifier:(id)identifier;

@end

#endif /* _AMSBagDataSourceLoadResult_h */