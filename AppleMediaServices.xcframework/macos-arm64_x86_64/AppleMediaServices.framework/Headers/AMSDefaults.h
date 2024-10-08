//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSDefaults_h
#define _AMSDefaults_h

@import Foundation;

@interface AMSDefaults : NSObject

/* class methods */
+ (id)allKeys;
+ (void)_setBool:(signed char)_bool forKey:(id)key;
+ (void)_setValue:(id)value forKey:(id)key;
+ (signed char)_boolForKey:(id)key defaultValue:(signed char)value;
+ (signed char)devMode;
+ (void)setDevMode:(signed char)mode;
+ (id)_valueForKey:(id)key;
+ (signed char)_boolForKey:(id)key defaultValue:(signed char)value domain:(struct __CFString *)domain;
+ (long long)_integerForKey:(id)key defaultValue:(long long)value;
+ (long long)_integerForKey:(id)key defaultValue:(long long)value domain:(struct __CFString *)domain;
+ (void)_setBool:(signed char)_bool forKey:(id)key domain:(struct __CFString *)domain;
+ (void)_setInteger:(long long)integer forKey:(id)key;
+ (void)_setValue:(id)value forKey:(id)key domain:(struct __CFString *)domain;
+ (id)_valueForKey:(id)key domain:(struct __CFString *)domain;
+ (signed char)QAMode;
+ (signed char)includeFullResponseInHARLogging;
+ (signed char)migratedPrivacyAcknowledgements;
+ (long long)pushEnvironment;
+ (void)setEnableRemoteSecuritySigning:(signed char)signing;
+ (void)setIgnoreServerTrustEvaluation:(signed char)evaluation;
+ (id)sourceOverrides;
+ (long long)applePayClassic;
+ (id)debugUI;
+ (id)regulatoryEligibilityAttributes;
+ (void)setDemoAccount:(id)account;
+ (signed char)streamHARToDisk;
+ (id)_allKeysForDomain:(struct __CFString *)domain;
+ (void)_cleanupSampleSessions;
+ (signed char)_resultFromSampleSession:(id)session isActive:(char *)active;
+ (id)accountFlagOverrides;
+ (long long)acknowledgePrivacyOverride;
+ (signed char)allowDuplicateAccounts;
+ (signed char)allowUpsellEnrollmentForAppliedAccounts;
+ (signed char)alwaysSendCacheBuster;
+ (signed char)alwaysSendGUID;
+ (id)authenticationStarted;
+ (signed char)automationMode;
+ (id)bagOverrideIgnoredKeys;
+ (id)bagOverrides;
+ (id)bagURLCookies;
+ (long long)cardEnrollmentAutomatic;
+ (long long)cardEnrollmentManual;
+ (long long)cardEnrollmentSilent;
+ (long long)cardEnrollmentUpsell;
+ (signed char)cleanedUpUserDefaultsDataAfterMigrationToStorage;
+ (signed char)debugUIDynamicUIEnabled;
+ (signed char)debugUIMessagingUIEnabled;
+ (id)defaultPaymentPassIdentifier;
+ (id)demoAccount;
+ (id)deviceBiometricIdentities;
+ (long long)deviceBiometricsState;
+ (id)deviceGroups;
+ (signed char)deviceIsBundleOverride;
+ (id)deviceOfferEligibility;
+ (id)deviceOffersSerialNumber;
+ (id)deviceRegistrationDenyList;
+ (signed char)didFetchBundleOwnerStatus;
+ (signed char)didRetrieveDeviceOffers;
+ (signed char)didRetrieveDeviceOffersEligibility;
+ (signed char)didRetrieveTVOffers;
+ (signed char)didSetUpServerDataCache;
+ (signed char)disableHARLogging;
+ (signed char)disablePrivacyAcknowledgement;
+ (signed char)disableStubbedMarketingItems;
+ (signed char)enableCameraRedeem;
+ (signed char)enablePurchaseQueue;
+ (signed char)enableRemoteSecuritySigning;
+ (signed char)engagementExtendTimeouts;
+ (signed char)forceEngagementPurchaseSuccess;
+ (long long)forceLoadUrlMetrics;
+ (id)forwardedForIPAddress;
+ (id)harURLFilters;
+ (signed char)ignoreServerTrustEvaluation;
+ (signed char)includeFullRequestInHARLogging;
+ (id)journeysURLOverride;
+ (id)journeysURLOverrides;
+ (id)jsSourceOverrides;
+ (id)jsVersionMap;
+ (id)lastCarrierOfferRegistrationDate;
+ (id)lastMigratedBuildVersion;
+ (signed char)logHARData;
+ (id)marketingItemOverrides;
+ (id)mediaClientIdOverrides;
+ (id)mediaTokenOverride;
+ (id)mescalCertExpiration;
+ (id)metricsCanaryIdentifier;
+ (id)metricsTimingWindowStartTime;
+ (signed char)migratedDeviceOffers;
+ (signed char)migratedDeviceOffersForWatch;
+ (signed char)migratedStorageToDefaultsForNonAMSInternal;
+ (signed char)migratedToNewAccountStore;
+ (signed char)migratedToNewCookieStorage;
+ (id)multiUserContainerID;
+ (signed char)perfomedDeviceOfferSetup;
+ (long long)reversePushEnabled;
+ (void)setAccountFlagOverrides:(id)overrides;
+ (void)setAcknowledgePrivacyOverride:(long long)override;
+ (void)setAllowDuplicateAccounts:(signed char)accounts;
+ (void)setAllowUpsellEnrollmentForAppliedAccounts:(signed char)accounts;
+ (void)setAlwaysSendCacheBuster:(signed char)buster;
+ (void)setAlwaysSendGUID:(signed char)guid;
+ (void)setApplePayClassic:(long long)classic;
+ (void)setAuthenticationStarted:(id)started;
+ (void)setAutomationMode:(signed char)mode;
+ (void)setBagOverrideIgnoredKeys:(id)keys;
+ (void)setBagOverrides:(id)overrides;
+ (void)setBagURLCookies:(id)urlcookies;
+ (void)setCardEnrollmentAutomatic:(long long)automatic;
+ (void)setCardEnrollmentManual:(long long)manual;
+ (void)setCardEnrollmentSilent:(long long)silent;
+ (void)setCardEnrollmentUpsell:(long long)upsell;
+ (void)setCleanedUpUserDefaultsDataAfterMigrationToStorage:(signed char)storage;
+ (void)setDebugUI:(id)ui;
+ (void)setDefaultPaymentPassIdentifier:(id)identifier;
+ (void)setDeviceBiometricIdentities:(id)identities;
+ (void)setDeviceBiometricsState:(long long)state;
+ (void)setDeviceGroups:(id)groups;
+ (void)setDeviceIsBundleOverride:(signed char)override;
+ (void)setDeviceOfferEligibility:(id)eligibility;
+ (void)setDeviceRegistrationDenyList:(id)list;
+ (void)setDidFetchBundleOwnerStatus:(signed char)status;
+ (void)setDidRetrieveDeviceOffers:(signed char)offers;
+ (void)setDidRetrieveDeviceOffersEligibility:(signed char)eligibility;
+ (void)setDidRetrieveTVOffers:(signed char)tvoffers;
+ (void)setDidSetUpServerDataCache:(signed char)cache;
+ (void)setDisableHARLogging:(signed char)harlogging;
+ (void)setDisablePrivacyAcknowledgement:(signed char)acknowledgement;
+ (void)setDisableStubbedMarketingItems:(signed char)items;
+ (void)setEnableCameraRedeem:(signed char)redeem;
+ (void)setEnablePurchaseQueue:(signed char)queue;
+ (void)setEngagementExtendTimeouts:(signed char)timeouts;
+ (void)setForceEngagementPurchaseSuccess:(signed char)success;
+ (void)setForceLoadUrlMetrics:(long long)metrics;
+ (void)setForwardedForIPAddress:(id)ipaddress;
+ (void)setHarURLFilters:(id)urlfilters;
+ (void)setIncludeFullRequestInHARLogging:(signed char)harlogging;
+ (void)setIncludeFullResponseInHARLogging:(signed char)harlogging;
+ (void)setJourneysURLOverride:(id)urloverride;
+ (void)setJourneysURLOverrides:(id)urloverrides;
+ (void)setJsSourceOverrides:(id)overrides;
+ (void)setJsVersionMap:(id)map;
+ (void)setLastCarrierOfferRegistrationDate:(id)date;
+ (void)setLastMigratedBuildVersion:(id)version;
+ (void)setLogHARData:(signed char)hardata;
+ (void)setMarketingItemOverrides:(id)overrides;
+ (void)setMediaClientIdOverrides:(id)overrides;
+ (void)setMediaTokenOverride:(id)override;
+ (void)setMescalCertExpiration:(id)expiration;
+ (void)setMetricsCanaryIdentifier:(id)identifier;
+ (void)setMetricsTimingWindowStartTime:(id)time;
+ (void)setMigratedDeviceOffers:(signed char)offers;
+ (void)setMigratedDeviceOffersForWatch:(signed char)watch;
+ (void)setMigratedPrivacyAcknowledgements:(signed char)acknowledgements;
+ (void)setMigratedStorageToDefaultsForNonAMSInternal:(signed char)amsinternal;
+ (void)setMigratedToNewAccountStore:(signed char)store;
+ (void)setMigratedToNewCookieStorage:(signed char)storage;
+ (void)setPerfomedDeviceOfferSetup:(signed char)setup;
+ (void)setPushEnvironment:(long long)environment;
+ (void)setQAMode:(signed char)qamode;
+ (void)setRegulatoryEligibilityAttributes:(id)attributes;
+ (void)setReversePushEnabled:(long long)enabled;
+ (void)setSharedStoreReviewMetrics:(id)metrics forProcess:(id)process;
+ (void)setShowSandboxAccountUI:(signed char)ui;
+ (void)setShowSpyglassPurchases:(signed char)purchases;
+ (void)setSourceOverrides:(id)overrides;
+ (void)setStorefrontSuffixes:(id)suffixes;
+ (void)setStreamHARToDisk:(signed char)disk;
+ (void)setTreatmentOverrides:(id)overrides;
+ (id)sharedStoreReviewMetricsForProcess:(id)process;
+ (signed char)shouldSampleWithPercentage:(double)percentage sessionDuration:(double)duration identifier:(id)identifier;
+ (void)shouldSampleWithPercentageValue:(id)value sessionDurationValue:(id)value identifier:(id)identifier completion:(id /* block */)completion;
+ (signed char)showSandboxAccountUI;
+ (signed char)showSpyglassPurchases;
+ (signed char)ss_ignoreServerTrustEvaluation;
+ (id)storefrontSuffixes;
+ (id)treatmentOverrides;
+ (void)updateBadgeIdsForBundle:(id)bundle block:(id /* block */)block;
+ (signed char)useNewAccountStore;
+ (signed char)useNewCookieStorage;

@end

#endif /* _AMSDefaults_h */
