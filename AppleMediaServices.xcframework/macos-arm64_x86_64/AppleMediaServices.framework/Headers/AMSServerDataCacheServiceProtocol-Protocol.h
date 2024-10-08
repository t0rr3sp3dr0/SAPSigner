//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSServerDataCacheServiceProtocol_Protocol_h
#define _AMSServerDataCacheServiceProtocol_Protocol_h

@import Foundation;

@protocol AMSServerDataCacheServiceProtocol

@required

/* required instance methods */
- (void)dataForAccountDSID:(id)dsid cacheTypeID:(id)id networkPolicy:(long long)policy completion:(id /* block */)completion;
- (void)granularNotificationSettingsForAccountDSID:(id)dsid bundleID:(id)id networkPolicy:(long long)policy completion:(id /* block */)completion;
- (void)reminderEventsForAccountDSID:(id)dsid service:(id)service eventType:(id)type networkPolicy:(long long)policy completion:(id /* block */)completion;
- (void)setUpCacheForAccount:(id)account completion:(id /* block */)completion;
- (void)setUpCacheForAccountDSID:(id)dsid completion:(id /* block */)completion;
- (void)tearDownCacheForAccountDSID:(id)dsid completion:(id /* block */)completion;
- (void)updateCacheForAccountDSID:(id)dsid withCachePayload:(id)payload completion:(id /* block */)completion;
- (void)updateCacheForAccountDSID:(id)dsid withCacheTypeIDs:(id)ids completion:(id /* block */)completion;

@optional

@end

#endif /* _AMSServerDataCacheServiceProtocol_Protocol_h */
