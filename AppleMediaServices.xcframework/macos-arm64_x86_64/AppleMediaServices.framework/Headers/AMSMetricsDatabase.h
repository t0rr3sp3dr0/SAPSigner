//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMetricsDatabase_h
#define _AMSMetricsDatabase_h

@import Foundation;

#include "AMSSQLiteConnection.h"
#include "AMSSQLiteConnectionDelegate-Protocol.h"

@protocol OS_dispatch_queue;

@interface AMSMetricsDatabase : NSObject <AMSSQLiteConnectionDelegate>

@property (retain) AMSSQLiteConnection *connection;
@property (retain) NSObject<OS_dispatch_queue> *internalQueue;
@property (retain) NSString *containerId;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (id)sharedDatabaseWithContainerId:(id)id;

/* instance methods */
- (void)dealloc;
- (void)close;
- (id)_cachePath;
- (id)initWithContainerId:(id)id;
- (signed char)dropAllEventsWithLockKey:(id)key error:(id *)error;
- (id)_lockedById;
- (void)_performTransaction:(id /* block */)transaction;
- (signed char)cleanupInvalidIdentifiersWithError:(id *)error;
- (signed char)clearIdentifierSyncStateWithError:(id *)error;
- (signed char)connectionNeedsResetForCorruption:(id)corruption;
- (long long)countAllEventsWithLockKey:(id)key error:(id *)error;
- (signed char)dropEvents:(id)events error:(id *)error;
- (void)enumerateEventsWithTopic:(id)topic lockKey:(id)key objectBlock:(id /* block */)block;
- (signed char)enumerateUnsyncedIdentifierStoresUsingBlock:(id /* block */)block error:(id *)error;
- (signed char)enumerateUnsyncedIdentifiersUsingBlock:(id /* block */)block error:(id *)error;
- (id)identifierForKey:(id)key updateMaybe:(id /* block */)maybe error:(id *)error;
- (id)identifierStoreForKey:(id)key updateMaybe:(id /* block */)maybe error:(id *)error;
- (signed char)insertEvents:(id)events error:(id *)error;
- (id)lockAllEventsWithError:(id *)error;
- (signed char)permanentlyRemoveIdentifierForKey:(id)key error:(id *)error;
- (signed char)removeCrossDeviceIdentifiersWithError:(id *)error;
- (signed char)removeIdentifiersForAccount:(id)account error:(id *)error;
- (signed char)unlockAllEventsWithKey:(id)key error:(id *)error;
- (signed char)unlockEvents:(id)events error:(id *)error;

@end

#endif /* _AMSMetricsDatabase_h */
