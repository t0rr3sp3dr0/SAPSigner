//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSCookieDatabase_h
#define _AMSCookieDatabase_h

@import Foundation;

#include "AMSSQLiteConnection.h"
#include "AMSSQLiteConnectionDelegate-Protocol.h"

@interface AMSCookieDatabase : NSObject <AMSSQLiteConnectionDelegate>

@property (readonly) AMSSQLiteConnection *connection;
@property (readonly, copy) NSString *dbPath;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)_cleanUpProtectionClassAtPath:(id)path fileManager:(id)manager;
+ (id)_dataVaultPathForIdentifier:(id)identifier error:(id *)error;
+ (id)_databasePathForIdentifier:(id)identifier error:(id *)error;
+ (id)_databasePathForIdentifiers:(id)identifiers fileManager:(id)manager error:(id *)error;
+ (id)_rootDataVaultPathWithError:(id *)error;
+ (id)cleanUpCookieDatabasesWithValidIdentifiers:(id)identifiers fileManager:(id)manager;
+ (id)cookieDatabaseForIdentifier:(id)identifier error:(id *)error;
+ (id)cookieDatabaseForIdentifiers:(id)identifiers error:(id *)error;
+ (id)cookieDatabaseForIdentifiers:(id)identifiers error:(id *)error fileManager:(id)manager;
+ (id)databasePathForIdentifiers:(id)identifiers error:(id *)error;

/* instance methods */
- (void)dealloc;
- (void)close;
- (signed char)_addCookieProperties:(id)properties error:(id *)error;
- (void)_bindCookieProperties:(id)properties column:(unsigned long long)column position:(int)position using:(id)_using;
- (id)_cookieDictionaryForCursor:(id)cursor;
- (signed char)_executeStatement:(id)statement columns:(id)columns forCookieProperties:(id)properties error:(id *)error;
- (signed char)_removeCookieProperties:(id)properties error:(id *)error;
- (signed char)connectionNeedsResetForCorruption:(id)corruption;
- (id)cookiePropertiesWithError:(id *)error;
- (id)initWithConnection:(id)connection path:(id)path;
- (signed char)updateCookiesWithCookiePropertiesToAdd:(id)add cookiePropertiesToRemove:(id)remove error:(id *)error;

@end

#endif /* _AMSCookieDatabase_h */
