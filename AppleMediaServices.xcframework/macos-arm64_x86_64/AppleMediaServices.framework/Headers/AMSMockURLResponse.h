//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSMockURLResponse_h
#define _AMSMockURLResponse_h

@import Foundation;

@interface AMSMockURLResponse : NSObject

@property (retain) NSMutableArray *responseHandlerBlocks;
@property (retain) NSURLSessionTask *runningTask;
@property (retain) NSError *error;
@property unsigned long long statusCode;
@property (retain) NSDictionary *headers;
@property (retain) NSData *body;
@property signed char performActualRequest;
@property (readonly) NSURLRequest *originalRequest;

/* class methods */
+ (id)responseWithError:(id)error;
+ (id)responseFromActualResponse;
+ (id)responseWithHARFile:(id)harfile;
+ (id)responseWithStatus:(unsigned long long)status headers:(id)headers body:(id)body;

/* instance methods */
- (id)init;
- (void)addResponseHandler:(id /* block */)handler;
- (struct { id x0; id x1; id x2; })handleReceivedRequest:(id)request;
- (void)stopRunningTasks;

@end

#endif /* _AMSMockURLResponse_h */