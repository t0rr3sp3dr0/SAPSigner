//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSEngagementServiceProtocol_Protocol_h
#define _AMSEngagementServiceProtocol_Protocol_h

@import Foundation;

@protocol AMSEngagementServiceProtocol

@required

/* required instance methods */
- (void)treatmentStoreServiceWithReply:(id /* block */)reply;
- (void)beginObservingMessages;
- (void)contentInfoForApp:(id)app cacheKey:(id)key version:(id)version reply:(id /* block */)reply;
- (void)enqueueWithRequest:(id)request completion:(id /* block */)completion;
- (void)notifyBlockedMessages:(id)messages;
- (void)syncWithRequest:(id)request completion:(id /* block */)completion;

@optional

/* optional instance methods */
- (oneway void)syncMetricsIdentifiers;

@end

#endif /* _AMSEngagementServiceProtocol_Protocol_h */
