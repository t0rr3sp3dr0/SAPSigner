//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSAutomaticDownloadKindsResult_h
#define _AMSAutomaticDownloadKindsResult_h

@import Foundation;

#include "ACAccount.h"

@interface AMSAutomaticDownloadKindsResult : NSObject

@property (readonly) ACAccount *account;
@property (readonly) NSArray *enabledMediaKinds;

/* instance methods */
- (id)initWithAccount:(id)account andEnabledMediaKinds:(id)kinds;

@end

#endif /* _AMSAutomaticDownloadKindsResult_h */
