//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef __AMSMescalFairPlay_h
#define __AMSMescalFairPlay_h

@import Foundation;

@interface AMSMescalFairPlay : NSObject {
    /* instance variables */
    struct FPSAPContextOpaque_ * _context;
    struct FairPlayHWInfo_ { unsigned int IDLength; unsigned char ID[20]; } _hardwareInfo;
    long long _mescalType;
}

@property (readonly, nonatomic) signed char complete;

/* instance methods */
- (void)dealloc;
- (signed char)isComplete;
- (id)signData:(id)data error:(id *)error;
- (id)_dataWithFairPlayBytes:(const char *)bytes length:(unsigned int)length;
- (void)_teardownSession;
- (id)exchangeData:(id)data error:(id *)error;
- (id)initWithMescalType:(long long)type error:(id *)error;
- (id)primingSignatureForData:(id)data error:(id *)error;
- (signed char)verifyPrimeSignature:(id)signature error:(id *)error;
- (signed char)verifySignature:(id)signature forData:(id)data error:(id *)error;

@end

#endif /* __AMSMescalFairPlay_h */
