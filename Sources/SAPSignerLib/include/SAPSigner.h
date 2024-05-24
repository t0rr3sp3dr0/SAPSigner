//
//  SAPSigner.h
//
//
//  Created by Pedro Tôrres on 2024-05-24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SAPSigner : NSObject

+ (nullable NSData *)signData:(NSData *)data error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
