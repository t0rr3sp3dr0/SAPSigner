//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _NSError_AppleMediaServices_h
#define _NSError_AppleMediaServices_h

@import Foundation;

@interface NSError (AppleMediaServices) <AMSSecureCodingSanitizable>

/* instance methods */
- (id)_ams_firstUnderlyingErrorPassingTest:(id /* block */)test;
- (id)ams_errorByAddingToMultipleUnderlyingErrors:(id)errors;
- (id)ams_errorByAddingUnderlyingError:(id)error;
- (id)ams_errorByAddingUserInfo:(id)info;
- (id)ams_errorByCombiningWithUnderlyingError:(id)error;
- (id)ams_errorWithMultipleUnderlyingErrors:(id)errors;
- (id)ams_errorWithUnderlyingError:(id)error;
- (signed char)ams_hasDomain:(id)domain;
- (signed char)ams_hasDomain:(id)domain code:(unsigned long long)code;
- (signed char)ams_isBagValueMissingError;
- (signed char)ams_isTimeoutError;
- (signed char)ams_isUserCancelledError;
- (id)ams_message;
- (id)ams_multipleUnderlyingErrors;
- (signed char)ams_recursiveHasDomain:(id)domain code:(unsigned long long)code;
- (id)ams_sanitizedForSecureCoding;
- (id)ams_title;
- (id)ams_underlyingError;
- (id)ams_underlyingErrorWithDomain:(id)domain;
- (id)ams_underlyingErrorWithDomain:(id)domain code:(unsigned long long)code;

@end

#endif /* _NSError_AppleMediaServices_h */