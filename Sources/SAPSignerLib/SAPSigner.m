//
//  SAPSigner.m
//
//
//  Created by Pedro Tôrres on 2024-05-24.
//

#import <AppleMediaServices/AMSMescalFairPlay.h>
#import <CommerceKit/CommerceKit.h>

#import "include/SAPSigner.h"

@implementation SAPSigner

+ (NSData *)primeData:(NSData *)data returningError:(NSError **)error {
    unsigned long mescalType = 2;
    AMSMescalFairPlay *mescalFairPlay = [[NSClassFromString(@"AMSMescalFairPlay") alloc] initWithMescalType:mescalType error:error];
    if (!mescalFairPlay) {
        return nil;
    }

    NSData *cert = [self getSignSAPSetupCertReturningError:error];
    if (!cert) {
        return nil;
    }

    NSData *oBuffer = [mescalFairPlay exchangeData:cert error:error];
    if (!oBuffer) {
        return nil;
    }

    NSData *iBuffer = [self postSignSAPSetupCertBuffer:oBuffer returningError:error];
    if (!iBuffer) {
        return nil;
    }

    NSData *_Buffer = [mescalFairPlay exchangeData:iBuffer error:error];
    if (!_Buffer) {
        return nil;
    }

    return [mescalFairPlay primingSignatureForData:data error:error];
}

+ (NSData *)getSignSAPSetupCertReturningError:(NSError **)error {
    NSURL *url = [NSURL URLWithString:@"https://init.itunes.apple.com/WebObjects/MZInit.woa/wa/signSapSetupCert"];
    NSURLRequest *request = [NSURLRequest requestWithURL:url];

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    NSData *body = [NSURLConnection sendSynchronousRequest:request returningResponse:nil error:error];
#pragma clang diagnostic pop
    if (!body) {
        return nil;
    }

    NSDictionary *propertyList = [NSPropertyListSerialization propertyListWithData:body options:NSPropertyListImmutable format:nil error:error];
    if (!propertyList) {
        return nil;
    }

    NSData *cert = propertyList[@"sign-sap-setup-cert"];
    return cert;
}

+ (NSData *)postSignSAPSetupCertBuffer:(NSData *)buffer returningError:(NSError **)error {
    NSDictionary *iPropertyList = @{
        @"sign-sap-setup-buffer": buffer,
    };
    NSData *iBody = [NSPropertyListSerialization dataWithPropertyList:iPropertyList format:NSPropertyListXMLFormat_v1_0 options:kNilOptions error:error];
    if (!iBody) {
        return nil;
    }

    NSURL *url = [NSURL URLWithString:@"https://play.itunes.apple.com/WebObjects/MZPlay.woa/wa/signSapSetup"];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    request.HTTPBody = iBody;
    request.HTTPMethod = @"POST";

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    NSData *oBody = [NSURLConnection sendSynchronousRequest:request returningResponse:nil error:error];
#pragma clang diagnostic pop
    if (!oBody) {
        return nil;
    }

    NSDictionary *propertyList = [NSPropertyListSerialization propertyListWithData:oBody options:NSPropertyListImmutable format:nil error:error];
    if (!propertyList) {
        return nil;
    }

    return propertyList[@"sign-sap-setup-buffer"];
}

+ (NSData *)signData:(NSData *)data returningError:(NSError **)error {
    CKSigningSession *signingSession = [[CKSigningSession alloc] initWithStoreClient:nil];

    [self openSessionWithSigningSession:signingSession];
    @try {
        return [signingSession signData:data error:error];
    } @finally {
        [signingSession closeSession];
    }
}

+ (void)openSessionWithSigningSession:(CKSigningSession *)signingSession {
    dispatch_group_t dg = dispatch_group_create();

    dispatch_group_enter(dg);
    [signingSession openSessionWithCompletionHandler:^{
        dispatch_group_leave(dg);
    }];

    dispatch_group_wait(dg, DISPATCH_TIME_FOREVER);
}

@end
