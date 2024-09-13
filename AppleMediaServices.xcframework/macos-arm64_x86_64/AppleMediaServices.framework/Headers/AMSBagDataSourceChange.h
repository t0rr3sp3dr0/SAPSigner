//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBagDataSourceChange_h
#define _AMSBagDataSourceChange_h

@import Foundation;

@interface AMSBagDataSourceChange : NSObject

@property (readonly) NSString *accountIdentifier;
@property (readonly) NSString *loadedBagIdentifier;
@property (readonly) NSString *loadedBagPartialIdentifier;
@property (readonly) NSDictionary *originalData;
@property (readonly) NSDate *originalExpirationDate;
@property (readonly) NSString *profile;
@property (readonly) NSString *profileVersion;
@property (readonly) NSDictionary *updatedData;
@property (readonly) NSDate *updatedExpirationDate;
@property (readonly) NSSet *changedKeys;

/* instance methods */
- (id)initWithProfile:(id)profile profileVersion:(id)version originalData:(id)data originalExpirationDate:(id)date updatedData:(id)data updatedExpirationDate:(id)date changedKeys:(id)keys loadedBagIdentifier:(id)identifier loadedBagPartialIdentifier:(id)identifier accountIdentifier:(id)identifier;

@end

#endif /* _AMSBagDataSourceChange_h */