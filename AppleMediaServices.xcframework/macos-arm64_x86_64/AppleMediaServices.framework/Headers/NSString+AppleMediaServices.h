//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _NSString_AppleMediaServices_h
#define _NSString_AppleMediaServices_h

@import Foundation;

@interface NSString (AppleMediaServices)

/* class methods */
+ (id)_replaceBreakingSpaceMarkupForMutableAttributedString:(id)string;
+ (id)_replaceMarkupForMutableAttributedString:(id)string markupType:(long long)type;

/* instance methods */
- (signed char)ams_caseInsensitiveEquals:(id)equals;
- (void)ams_enumerateRangesOfString:(id)string options:(unsigned long long)options usingBlock:(id /* block */)block;
- (signed char)ams_isPercentEncodedForAllowedCharacters:(id)characters;
- (signed char)ams_matchesRegex:(id)regex;
- (id)ams_replaceAccountPatternWithUsername:(id)username;
- (id)ams_replacingMarkupUsingAccount:(id)account shouldUppercase:(signed char)uppercase;
- (id)ams_sha256HashStringUsingEncoding:(unsigned long long)encoding error:(id *)error;
- (id)ams_sha512HashStringUsingEncoding:(unsigned long long)encoding error:(id *)error;
- (id)ams_stringByRemovingCharactersInSet:(id)set;

@end

#endif /* _NSString_AppleMediaServices_h */
