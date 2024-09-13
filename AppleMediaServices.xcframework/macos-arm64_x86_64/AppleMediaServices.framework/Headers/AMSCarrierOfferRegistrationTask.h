//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSCarrierOfferRegistrationTask_h
#define _AMSCarrierOfferRegistrationTask_h

@import Foundation;

#include "ACAccount.h"
#include "AMSBagConsumer-Protocol.h"
#include "AMSBagProtocol-Protocol.h"
#include "AMSProcessInfo.h"
#include "AMSPromise.h"
#include "AMSTask.h"
#include "AMSURLRequestEncoder.h"
#include "AMSURLSession.h"

@interface AMSCarrierOfferRegistrationTask : AMSTask <AMSBagConsumer>

@property (readonly) NSArray *carriers;
@property (readonly) AMSURLRequestEncoder *checkOfferRequestEncoder;
@property (readonly) NSString *deviceGUID;
@property (readonly) NSString *msisdn;
@property (readonly) AMSURLRequestEncoder *registrationRequestEncoder;
@property (readonly) AMSURLSession *urlSession;
@property (readonly) AMSPromise *pacTokenPromise;
@property (readonly) Class privacyMappingResolver;
@property (readonly) ACAccount *account;
@property (readonly) id <AMSBagProtocol> bag;
@property (retain) AMSProcessInfo *clientInfo;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (id)bagSubProfile;
+ (id)bagSubProfileVersion;
+ (id)bagKeySet;
+ (id)createBagForSubProfile;
+ (id)invalidParameterError:(id)error;
+ (id)pollingIntervalFromBag:(id)bag;

/* instance methods */
- (id)perform;
- (id)_allowedServiceIdentifiersFromPrivacyMapping:(id)mapping;
- (id)_checkOffersBodyLimitedByAllowedServiceIdentifiers:(id)identifiers;
- (id)_checkOffersRequestLimitedByAllowedServiceIdentifiers:(id)identifiers;
- (id)_evaluationRequiredPrivacyMappingPair;
- (id)_hasOffersLimitedByAllowedServiceIdentifiers:(id)identifiers;
- (id)_includesAllowedCarrier;
- (id)_pacToken;
- (id)_parseCheckOffersResult:(id)result;
- (id)_performRegistrationFlowLimitedByAllowedServiceIdentifiers:(id)identifiers;
- (id)_registerCarrierOffersToAccountLimitedByAllowedServiceIdentifiers:(id)identifiers;
- (id)_registrationBodyLimitedByAllowedServiceIdentifiers:(id)identifiers;
- (id)_registrationRequestLimitedByAllowedServiceIdentifiers:(id)identifiers;
- (id)initWithAccount:(id)account bag:(id)bag;
- (id)initWithAccount:(id)account bag:(id)bag carriers:(id)carriers checkOfferRequestEncoder:(id)encoder deviceGUID:(id)guid msisdn:(id)msisdn pacTokenPromise:(id)promise privacyMappingResolver:(Class)resolver registrationRequestEncoder:(id)encoder urlSession:(id)session;
- (id)initWithAccount:(id)account bag:(id)bag carriers:(id)carriers deviceGUID:(id)guid msisdn:(id)msisdn;

@end

#endif /* _AMSCarrierOfferRegistrationTask_h */