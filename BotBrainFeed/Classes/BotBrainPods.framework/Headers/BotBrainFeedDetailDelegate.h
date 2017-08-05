//
//  BotBrainFeedDetailProtocol.h
//  BotBrainLib
//
//  Created by ZHAN on 2017/5/10.
//  Copyright © 2017年 ZHAN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>

@class BotBrainFeedShareModel;

@protocol BotBrainFeedDetailDelegate <NSObject>

@optional

/**
 分享 - 点击分享按钮时
 
 @param shareModel 当前Model
 */
- (void)botBrainDidShareWithShareModel:(BotBrainFeedShareModel *)shareModel;

/**
 点赞 - 点赞时
 
 @param shareModel 当前Model
 */
- (void)botBrainDidLikeWithShareModel:(BotBrainFeedShareModel *)shareModel;

/**
 发布评论 - 将要回复评论时（可实现此方法来提示用户登录）
 
 @param shareModel 当前Model
 */
- (void)botBrainWillCommentWithShareModel:(BotBrainFeedShareModel *)shareModel;

/**
 发布评论 - 评论发送结束 成功或者失败
 
 @param shareModel 当前Model
 */
- (void)botBrainDidCommentWithShareModel:(BotBrainFeedShareModel *)shareModel;


/**
 自定义返回详情right item显示内容，只接受NSString类型或者UIImage类型，返回nil则不显示
 
 @return NSString or UIImage
 */
- (id)objectForFeedDetailRightBarButtonItem;


/**
 注意：此设置仅在以view方式添加图文列表，并且详情页以模态展示时有效
 自定义返回详情left item显示内容，只接受NSString类型或者UIImage类型，默认显示关闭
 
 @return NSString or UIImage
 */
- (id)objectForFeedDetailLeftBarButtonItem;
/**
 注意：此设置仅在以view方式添加图文列表，并且详情页以模态展示时有效
 详情NavigationBar背景色默认 whiteColor
 
 @return UIColor
 */
- (UIColor *)backgroundColorForDetailNavigationBar;
/**
 注意：此设置仅在以view方式添加图文列表，并且详情页以模态展示时有效
 详情NavigationBar文字颜色,默认 blackColor
 
 @return UIColor
 */
- (UIColor *)tintColorForDetailNavigationBar;


@end


@protocol BotBrainFeedDelegate <NSObject>

@optional
/**
 控制左右滑动
 
 @return 返回YES时禁止左右滑动
 */
- (BOOL)feedShouldForbidRoll;


/**
 当没有数据时显示的View
 
 @param index 当前列表下标，对应栏目，从0开始
 @return UIView
 */
- (UIView *)viewForNoResultTableViewAtIndex:(NSInteger)index;

- (void)didLoadThemeName:(NSString *)themeName;

@end
