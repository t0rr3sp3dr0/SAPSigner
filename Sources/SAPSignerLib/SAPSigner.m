//
//  SAPSigner.m
//
//
//  Created by Pedro Tôrres on 2024-05-24.
//

#import <CommerceKit/CommerceKit.h>

#import "include/SAPSigner.h"

@implementation SAPSigner

+ (NSData *)signData:(NSData *)data error:(NSError **)error {
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
