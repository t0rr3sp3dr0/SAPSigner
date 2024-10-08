//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSOperation_h
#define _AMSOperation_h

@import Foundation;

#include "AMSBinaryPromise.h"

@interface AMSOperation : NSOperation {
    /* instance variables */
    NSLock *_lock;
    NSMutableSet *_subOperations;
    signed char _cancelled;
}

@property (weak) AMSOperation *parentOperation;
@property (readonly) AMSBinaryPromise *promise;
@property signed char success;
@property (retain) NSError *error;

/* instance methods */
- (id)init;
- (void)run;
- (void)lock;
- (void)unlock;
- (void)cancel;
- (signed char)isCancelled;
- (void)main;
- (void)runSubOperation:(id)operation;
- (void)runSubOperation:(id)operation onQueue:(id)queue;

@end

#endif /* _AMSOperation_h */
