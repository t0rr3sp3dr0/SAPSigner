//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _NSCoder_AppleMediaServices_h
#define _NSCoder_AppleMediaServices_h

@import Foundation;

@interface NSCoder (AppleMediaServices)

/* instance methods */
- (id)ams_decodeJSONDictionaryForKey:(id)key;
- (id)_ams_decodeJSONObjectForKey:(id)key error:(id *)error;
- (id)_ams_decodePropertyListObjectForKey:(id)key error:(id *)error;
- (signed char)_ams_encodeJSONObject:(id)jsonobject forKey:(id)key error:(id *)error;
- (signed char)_ams_encodePropertyListObject:(id)object forKey:(id)key format:(unsigned long long)format error:(id *)error;
- (id)ams_decodeJSONArrayForKey:(id)key;
- (id)ams_decodePropertyListArrayForKey:(id)key;
- (id)ams_decodePropertyListDictionaryForKey:(id)key;
- (void)ams_encodeJSONArray:(id)jsonarray forKey:(id)key;
- (void)ams_encodeJSONDictionary:(id)jsondictionary forKey:(id)key;
- (void)ams_encodePropertyListArray:(id)array format:(unsigned long long)format forKey:(id)key;
- (void)ams_encodePropertyListDictionary:(id)dictionary format:(unsigned long long)format forKey:(id)key;

@end

#endif /* _NSCoder_AppleMediaServices_h */
