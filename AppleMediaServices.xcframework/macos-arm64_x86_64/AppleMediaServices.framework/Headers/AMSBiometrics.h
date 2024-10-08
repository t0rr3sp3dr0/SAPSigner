//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSBiometrics_h
#define _AMSBiometrics_h

@import Foundation;

@interface AMSBiometrics : NSObject

/* class methods */
+ (long long)type;
+ (long long)deviceState;
+ (void)setDeviceState:(long long)state;
+ (id)ACLVersionForAccessControl:(struct __SecAccessControl *)control;
+ (id)ACLVersionForConstraints:(id)constraints;
+ (id)ACLVersionForAccount:(id)account options:(id)options error:(id *)error;
+ (void)saveIdentityMap;
+ (signed char)_deleteKeysWithOptions:(id)options error:(id *)error;
+ (signed char)_shouldAddBiometricHeader;
+ (id)_stateHeaderValueForAccount:(id)account;
+ (signed char)deleteAllKeysWithError:(id *)error;
+ (signed char)deleteKeysWithError:(id *)error;
+ (id)disableForAccount:(id)account;
+ (id)handleResponse:(id)response session:(id)session taskInfo:(id)info;
+ (id)headersWithAccount:(id)account options:(id)options signatureResult:(id)result;
+ (id)identityMap;
+ (signed char)isActionSupported:(long long)supported withAccessControl:(struct __SecAccessControl *)control;
+ (signed char)isActionSupported:(long long)supported withConstraints:(id)constraints;
+ (signed char)isActionSupportedForType:(long long)type account:(id)account options:(id)options error:(id *)error;
+ (signed char)isAvailableForAccount:(id)account;
+ (signed char)isIdentityMapValid;
+ (id)minimumACLVersionForAction:(long long)action;
+ (signed char)proxyDeleteAllKeysWithError:(id *)error;
+ (id)resumptionHeadersFromRequest:(id)request;
+ (id)setState:(long long)state forAccount:(id)account;
+ (id)signAndReturnChallenge:(id)challenge withAccount:(id)account clientInfo:(id)info options:(id)options;
+ (id)signChallenge:(id)challenge withAccount:(id)account clientInfo:(id)info options:(id)options;
+ (long long)stateForAccount:(id)account;

@end

#endif /* _AMSBiometrics_h */
