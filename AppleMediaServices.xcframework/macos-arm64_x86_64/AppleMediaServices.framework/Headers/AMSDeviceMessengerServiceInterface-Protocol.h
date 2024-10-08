//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSDeviceMessengerServiceInterface_Protocol_h
#define _AMSDeviceMessengerServiceInterface_Protocol_h

@import Foundation;

@protocol AMSDeviceMessengerServiceInterface <NSObject>

@required

/* required instance methods */
- (void)getMessagesWithPurpose:(long long)purpose completion:(id /* block */)completion;
- (void)sendMessage:(id)message completion:(id /* block */)completion;

@optional

@end

#endif /* _AMSDeviceMessengerServiceInterface_Protocol_h */
