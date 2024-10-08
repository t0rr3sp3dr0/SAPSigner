//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSAcknowledgePrivacyTask_h
#define _AMSAcknowledgePrivacyTask_h

@import Foundation;

#include "ACAccount.h"
#include "AMSTask.h"

@interface AMSAcknowledgePrivacyTask : AMSTask

@property (copy) NSSet *privacyIdentifiers;
@property (retain) ACAccount *account;

/* class methods */
+ (id)_appleMusicAppPrivacyIdentifier;
+ (id)_accountStoreForPrivacyIdentifier:(id)identifier;
+ (id)_appleArcadePrivacyIdentifier;
+ (id)_appleIDPrivacyIdentifier;
+ (id)_appleTVAppPrivacyIdentifier;
+ (unsigned long long)_contentVersionForPrivacyIdentifier:(id)identifier;
+ (id)_multiplexPrivacyIdentifier:(id)identifier contentVersion:(unsigned long long)version;
+ (id)_storePrivacyIdentifiers;
+ (id)_valueForPreviouslyAcknowledgedPrivacyIdentifier:(id)identifier account:(id)account;
+ (signed char)acknowledgementNeededForPrivacyIdentifier:(id)identifier;
+ (signed char)acknowledgementNeededForPrivacyIdentifier:(id)identifier account:(id)account;
+ (signed char)hasPreviouslyAcknowledgedPrivacyIdentifier:(id)identifier;
+ (signed char)hasPreviouslyAcknowledgedPrivacyIdentifier:(id)identifier account:(id)account;
+ (signed char)hasPreviouslyAcknowledgedPrivacyIdentifier:(id)identifier account:(id)account minimumVersion:(id)version;
+ (signed char)hasPreviouslyAcknowledgedPrivacyIdentifier:(id)identifier minimumVersion:(id)version;
+ (signed char)hasRejectedPrivacyIdentifier:(id)identifier;
+ (signed char)hasRejectedPrivacyIdentifier:(id)identifier account:(id)account;

/* instance methods */
- (id)_updatePrivacyWithAcknowledgementVersions:(id)versions;
- (id)acknowledgePrivacy;
- (id)initWithPrivacyIdentifier:(id)identifier;
- (id)initWithPrivacyIdentifier:(id)identifier account:(id)account;
- (id)initWithPrivacyIdentifiers:(id)identifiers;
- (id)initWithPrivacyIdentifiers:(id)identifiers account:(id)account;
- (id)rejectPrivacy;

@end

#endif /* _AMSAcknowledgePrivacyTask_h */
