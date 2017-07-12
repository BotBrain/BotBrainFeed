//
//  BotBrainFeedShareModel.h
//  BotBrainLib
//
//  Created by ZHAN on 2017/5/10.
//  Copyright © 2017年 ZHAN. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BotBrainFeedShareModel : NSObject

/** 文章标题 */
@property (nonatomic, copy) NSString *feedItemTitle;
/** 文章URL */
@property (nonatomic, copy) NSString *feedItemURL;
/** 文章ID */
@property (nonatomic, copy) NSString *feedItemID;
/** 分享图片URL */
@property (nonatomic, copy) NSString *shareImageURL;
/** 分享、点赞、评论出错信息，为nil，则正常 */
@property (nonatomic, strong) NSError *error;

@end
