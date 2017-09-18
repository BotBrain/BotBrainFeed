//
//  BotBrainConfig.h
//  Pods
//
//  Created by ZHAN on 2017/9/11.
//
//

#import <Foundation/Foundation.h>

/// 全局配置相关类

@class BotBrainFeedListConfig;
@class BotBrainFeedDetailConfig;
@class BotBrainUIDayThemeConfig;
@class BotBrainUINightThemeConfig;

@interface BotBrainConfig : NSObject

/** SDK默认配置，不要重复调用此方法 */
+ (BotBrainConfig *)botDefaultConfig;

/** 用户AppKey */
@property (nonatomic, copy) NSString *appKey;
/** 用户AppSecret */
@property (nonatomic, copy) NSString *appSecret;
/** 渠道，默认AppStore */
@property (nonatomic, copy) NSString *channel;
/** 是否输出Log，默认 NO */
@property (nonatomic, assign) BOOL logEnabled;
/** Feed流配置 */
@property (nonatomic, strong) BotBrainFeedListConfig *feedListConfig;
/** 详情配置 */
@property (nonatomic, strong) BotBrainFeedDetailConfig *feedDetailConfig;

@end

/// Feed流相关配置
@interface BotBrainFeedListConfig : NSObject

/** 隐藏Feed流顶部栏目view， 默认NO，即显示栏目view */
@property (nonatomic, assign) BOOL hideColumnView;
/** 是否禁止左右滑动切换不同的栏目，默认NO */
@property (nonatomic, assign) BOOL forbidHorizontalScroll;

@end

/// 详情相关配置
@interface BotBrainFeedDetailConfig : NSObject

/** 详情导航栏右侧显示内容，类型只能是 Title 或者 Image */
@property (nonatomic, strong) id detailRightItemContent;

/** 详情导航栏左侧显示内容，类型只能是 Title 或者 Image；注意：只在详情以模态形式显示的时候有效 */
@property (nonatomic, strong) id detailLeftItemContent;

@end
