//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBagNetworkDataSource_h
#define _AMSBagNetworkDataSource_h

@import Foundation;

#include "AMSBagAccountProvider-Protocol.h"
#include "AMSBagDataSourceProtocol-Protocol.h"
#include "AMSBagNetworkTask.h"
#include "AMSBagNetworkTaskResult.h"
#include "AMSObserver.h"
#include "AMSProcessInfo.h"
#include "os_unfair_recursive_lock_s.h"

@protocol OS_dispatch_queue;

@interface AMSBagNetworkDataSource : NSObject <AMSBagDataSourceProtocol>

@property (retain) AMSObserver *accountsChangedObserver;
@property (readonly) id <AMSBagAccountProvider> accountProvider;
@property (retain) AMSBagNetworkTaskResult *cachedResult;
@property (readonly) struct os_unfair_recursive_lock_s cachedDataAccessLock;
@property (retain, nonatomic) NSString *cachedStorefront;
@property (retain) NSObject<OS_dispatch_queue> *completionQueue;
@property (retain) AMSBagNetworkTask *currentLoadTask;
@property (retain) NSMutableDictionary *defaultValues;
@property (readonly) NSObject<OS_dispatch_queue> *processAccountStoreDidChangeNotificationQueue;
@property (readonly) NSDate *expirationDate;
@property (readonly) signed char loaded;
@property (readonly, copy) NSString *bagLoadingPartialIdentifier;
@property (readonly, copy) AMSProcessInfo *processInfo;
@property (readonly, copy) NSString *profile;
@property (readonly, copy) NSString *profileVersion;
@property (retain) NSString *descriptionExtended;
@property (copy) id /* block */ dataSourceChangedHandler;
@property (copy) id /* block */ dataSourceDataInvalidatedHandler;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)_valueForURLVariable:(id)urlvariable account:(id)account clientInfo:(id)info sync:(signed char)sync completion:(id /* block */)completion;
+ (id)requestPartialIdentifierForClientInfo:(id)info profile:(id)profile profileVersion:(id)version;
+ (id)valueForURLVariable:(id)urlvariable account:(id)account clientInfo:(id)info;
+ (void)valueForURLVariable:(id)urlvariable account:(id)account clientInfo:(id)info completion:(id /* block */)completion;

/* instance methods */
- (void)dealloc;
- (signed char)isLoaded;
- (id)defaultValueForKey:(id)key;
- (void)_accountStoreDidChange;
- (id)_fetchBag;
- (void)_invalidateCacheNotification:(id)notification;
- (id)_newCompletionQueue;
- (void)_updateCachedResult:(id)result;
- (id)initWithProfile:(id)profile profileVersion:(id)version processInfo:(id)info;
- (id)initWithProfile:(id)profile profileVersion:(id)version processInfo:(id)info accountProvider:(id)provider;
- (void)loadWithCompletion:(id /* block */)completion;
- (id)loadedValuesForKeys:(id)keys outExpirationDate:(id *)date;
- (void)setDefaultValue:(id)value forKey:(id)key;
- (id)valueForURLVariable:(id)urlvariable account:(id)account;
- (void)valueForURLVariable:(id)urlvariable account:(id)account completion:(id /* block */)completion;

@end

#endif /* _AMSBagNetworkDataSource_h */
