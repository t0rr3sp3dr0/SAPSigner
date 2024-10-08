//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSKeychain_h
#define _AMSKeychain_h

@import Foundation;

@interface AMSKeychain : NSObject

/* class methods */
+ (id)_primaryConstraintsWithOptions:(id)options;
+ (signed char)deleteKeyPairWithOptions:(id)options error:(id *)error;
+ (id)_certificatePrivateKeyLabelForOptions:(id)options;
+ (SecKeyRef)_copyLegacyPrivateKeyForOptions:(id)options error:(id *)error;
+ (SecKeyRef)_copyLegacyPublicKeyForOptions:(id)options error:(id *)error;
+ (void)_deleteResumptionHeaders;
+ (id)_extendedConstraintsWithOptions:(id)options;
+ (signed char)_generateLegacyKeypairForOptions:(id)options error:(id *)error;
+ (id)_legacyAttestationForOptions:(id)options error:(id *)error;
+ (id)_primaryConstraints;
+ (id)_primaryConstraintsForMac;
+ (id)_primaryConstraintsForReality;
+ (id)_primaryConstraintsForWatch;
+ (id)_resumptionHeadersQuery;
+ (id)certificateChainStringsForOptions:(id)options error:(id *)error;
+ (id)certificateKeychainLabelsForOptions:(id)options;
+ (struct __SecAccessControl *)copyAccessControlRefWithAccount:(id)account options:(id)options error:(id *)error;
+ (SecKeyRef)copyCertificatePrivateKeyWithContext:(id)context account:(id)account options:(id)options error:(id *)error;
+ (SecKeyRef)copyPrivateKeyWithContext:(id)context account:(id)account options:(id)options error:(id *)error;
+ (SecKeyRef)copyPrivateKeyWithContext:(id)context options:(id)options error:(id *)error;
+ (SecKeyRef)copyPublicKeyForAccount:(id)account options:(id)options error:(id *)error;
+ (SecKeyRef)copyPublicKeyForOptions:(id)options error:(id *)error;
+ (struct __SecAccessControl *)createAccessControlRefWithOptions:(id)options error:(id *)error;
+ (signed char)deleteCertificateChainWithOptions:(id)options error:(id *)error;
+ (id)keychainLabelForOptions:(id)options;
+ (id)legacyAttestationForOptions:(id)options error:(id *)error;
+ (signed char)performForwardKeyMigrationForDSID:(id)dsid forceMigration:(signed char)migration;
+ (id)publicKeyHeaderWithAccount:(id)account options:(id)options signatureResult:(id)result;
+ (id)resumptionHeaders;
+ (void * /* function */)secItemAddFunc;
+ (void * /* function */)secItemCopyMatchingFunc;
+ (void)setSecItemAddFunc:(void * /* function */)func;
+ (void)setSecItemCopyMatchingFunc:(void * /* function */)func;
+ (void)stashResumptionHeaders:(id)headers;
+ (signed char)stashResumptionHeaders:(id)headers error:(id *)error;
+ (signed char)storePrimaryCert:(struct __SecCertificate *)cert intermediateCert:(struct __SecCertificate *)cert privateKey:(SecKeyRef)key options:(id)options error:(id *)error;

@end

#endif /* _AMSKeychain_h */
