//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBagDataSourceProtocol_Protocol_h
#define _AMSBagDataSourceProtocol_Protocol_h

@import Foundation;

#include "AMSProcessInfo.h"

@protocol AMSBagDataSourceProtocol <NSObject>

@required

@property (readonly) NSDate *expirationDate;
@property (readonly) signed char loaded;
@property (readonly, copy) NSString *bagLoadingPartialIdentifier;
@property (readonly, copy) AMSProcessInfo *processInfo;
@property (readonly, copy) NSString *profile;
@property (readonly, copy) NSString *profileVersion;

/* required instance methods */
- (signed char)isLoaded;
- (id)defaultValueForKey:(id)key;
- (void)loadWithCompletion:(id /* block */)completion;
- (void)setDefaultValue:(id)value forKey:(id)key;
- (id)valueForURLVariable:(id)urlvariable account:(id)account;
- (void)valueForURLVariable:(id)urlvariable account:(id)account completion:(id /* block */)completion;

@optional

@property (retain) NSString *descriptionExtended;
@property (copy) id /* block */ dataSourceChangedHandler;
@property (copy) id /* block */ dataSourceDataInvalidatedHandler;

/* optional instance methods */
- (id)loadedValuesForKeys:(id)keys outExpirationDate:(id *)date;

@end

#endif /* _AMSBagDataSourceProtocol_Protocol_h */
