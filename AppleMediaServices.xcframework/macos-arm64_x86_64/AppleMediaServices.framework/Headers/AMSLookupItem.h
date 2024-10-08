//
//   Generated by https://github.com/blacktop/ipsw (Version: , BuildCommit: )
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 14.4, SDK: 14.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_BUILD_VERSION:  Platform: macCatalyst, MinOS: 17.4, SDK: 17.4, Tools: [ld (902.8), ld (854.1), ld (951.9)]
//    - LC_SOURCE_VERSION: 7.4.38.1.3
//
#ifndef _AMSLookupItem_h
#define _AMSLookupItem_h

@import Foundation;

@interface AMSLookupItem : NSObject <NSCopying, NSSecureCoding>

@property (readonly, copy) NSString *artistName;
@property (readonly, copy) NSArray *artwork;
@property (readonly, copy) NSString *bundleIdentifier;
@property (readonly, copy) NSArray *categoryNames;
@property (readonly, copy) NSString *displayName;
@property (readonly, copy) NSString *itemKind;
@property (readonly, copy) NSNumber *iTunesStoreIdentifier;
@property (readonly, copy) NSString *offerName;
@property (readonly, copy) NSArray *offers;
@property (readonly) signed char POIBased;
@property (readonly, copy) NSURL *productPageURL;
@property (readonly) long long numberOfUserRatings;
@property (readonly) float userRating;
@property (readonly) long long numberOfUserRatingsForCurrentVersion;
@property (readonly) float userRatingForCurrentVersion;
@property (readonly) NSDictionary *itemDictionary;

/* class methods */
+ (signed char)supportsSecureCoding;

/* instance methods */
- (id)copyWithZone:(struct _NSZone *)zone;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (id)initWithLookupDictionary:(id)dictionary;
- (signed char)isPOIBased;

@end

#endif /* _AMSLookupItem_h */
