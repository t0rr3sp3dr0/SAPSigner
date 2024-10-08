//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSAccountCachedServerDataServiceInterface_Protocol_h
#define _AMSAccountCachedServerDataServiceInterface_Protocol_h

@import Foundation;

@protocol AMSAccountCachedServerDataServiceInterface <NSObject>

@required

/* required instance methods */
- (void)getDataForAccountIDs:(id)ids reply:(id /* block */)reply;
- (void)queueMetricsEventNotingExpiry:(id)expiry appID:(id)id reply:(id /* block */)reply;
- (void)setAutoPlayState:(signed char)state forAccountID:(id)id reply:(id /* block */)reply;
- (void)setPersonalizationState:(signed char)state forAccountID:(id)id reply:(id /* block */)reply;

@optional

@end

#endif /* _AMSAccountCachedServerDataServiceInterface_Protocol_h */
