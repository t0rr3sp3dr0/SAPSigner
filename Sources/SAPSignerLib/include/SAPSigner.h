//
//  SAPSigner.h
//
//
//  Created by Pedro Tôrres on 2024-05-24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SAPSigner : NSObject

+ (nullable NSData *)primeData:(NSData *)data returningError:(NSError **)error __attribute__((swift_name("prime(_:)")));

+ (nullable NSData *)signData:(NSData *)data returningError:(NSError **)error __attribute__((swift_name("sign(_:)")));

@end

NS_ASSUME_NONNULL_END
