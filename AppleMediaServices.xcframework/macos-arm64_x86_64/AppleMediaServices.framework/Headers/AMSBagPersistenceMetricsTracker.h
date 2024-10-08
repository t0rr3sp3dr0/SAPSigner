//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBagPersistenceMetricsTracker_h
#define _AMSBagPersistenceMetricsTracker_h

@import Foundation;

@interface AMSBagPersistenceMetricsTracker : NSObject { // (Swift)
    /* instance variables */
    //  eventSender;
    //  initialState;
}

/* class methods */
+ (void)trackCachedValuesUnavailableWithRequestedValueCount:(long long)count;
+ (id)trackerForCachedValuesCallWithRequestedValueCount:(long long)count cachedValueCount:(long long)count cachedBagWasExpired:(signed char)expired;

/* instance methods */
- (id)init;

@end

#endif /* _AMSBagPersistenceMetricsTracker_h */
