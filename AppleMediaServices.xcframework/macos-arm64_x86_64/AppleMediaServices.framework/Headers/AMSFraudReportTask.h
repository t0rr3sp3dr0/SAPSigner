//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSFraudReportTask_h
#define _AMSFraudReportTask_h

@import Foundation;

#include "AMSTask.h"

@interface AMSFraudReportTask : AMSTask

/* class methods */
+ (id)ams_performFraudReportRefreshWithAccount:(id)account transactionID:(id)id nameSpace:(id)space fsrData:(id)data keyID:(id)id;
+ (id)performFraudReportRefreshWithAccount:(id)account transactionID:(id)id nameSpace:(id)space fsrData:(id)data keyID:(id)id;

@end

#endif /* _AMSFraudReportTask_h */