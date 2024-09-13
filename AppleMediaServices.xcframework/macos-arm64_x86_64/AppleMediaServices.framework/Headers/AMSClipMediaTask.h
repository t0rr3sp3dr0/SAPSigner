//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSClipMediaTask_h
#define _AMSClipMediaTask_h

@import Foundation;

#include "AMSBagConsumer-Protocol.h"
#include "AMSBagProtocol-Protocol.h"
#include "AMSProcessInfo.h"
#include "AMSTask.h"

@interface AMSClipMediaTask : AMSTask <AMSBagConsumer>

@property (retain) id <AMSBagProtocol> bag;
@property (retain) NSString *bundleID;
@property (retain) NSString *clientID;
@property (retain) AMSProcessInfo *clientInfo;
@property (retain) NSNumber *externalVersionID;
@property (retain) NSURL *URL;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (id)bagSubProfile;
+ (id)bagSubProfileVersion;
+ (id)bagKeySet;
+ (id)createBagForSubProfile;

/* instance methods */
- (id)perform;
- (id)_componentsPromise;
- (id)_performJourneysLookup;
- (id)_performNetworkLookup;
- (id)initWithClientID:(id)id bundleID:(id)id URL:(id)url bag:(id)bag;

@end

#endif /* _AMSClipMediaTask_h */