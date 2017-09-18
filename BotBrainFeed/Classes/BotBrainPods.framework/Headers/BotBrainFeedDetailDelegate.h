//
//  BotBrainFeedDetailProtocol.h
//  BotBrainLib
//
//  Created by ZHAN on 2017/5/10.
//  Copyright © 2017年 ZHAN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>

@class BotBrainFeedColumnModel;
@class BotBrainFeedShareModel;

@protocol BotBrainFeedDetailDelegate <NSObject>

@optional

/**
 分享 - 点击详情右上角时
 
 @param shareModel 当前Model
 */
- (void)botBrainDidShareWithShareModel:(BotBrainFeedShareModel *)shareModel;
/**
 分享 - 点击底部分享按钮时
 
 @param shareModel 当前Model
 */
- (void)botBrainDidTapBottomShareWithShareModel:(BotBrainFeedShareModel *)shareModel;

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
- (id)objectForFeedDetailRightBarButtonItem DEPRECATED_MSG_ATTRIBUTE("Use BotBrainConfig feedDetailConfig detailRightItemContent");


/**
 注意：此设置仅在以view方式添加图文列表，并且详情页以模态展示时有效
 自定义返回详情left item显示内容，只接受NSString类型或者UIImage类型，默认显示关闭
 
 @return NSString or UIImage
 */
- (id)objectForFeedDetailLeftBarButtonItem DEPRECATED_MSG_ATTRIBUTE("Use BotBrainConfig feedDetailConfig detailLeftItemContent");;
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
- (BOOL)feedShouldForbidRoll DEPRECATED_MSG_ATTRIBUTE("Use BotBrainConfig feedListConfig forbidHorizontalScroll");


/**
 当没有数据时显示的View
 
 @param index 当前列表下标，对应栏目，从0开始
 @return UIView
 */
- (UIView *)viewForNoResultTableViewAtIndex:(NSInteger)index;

/**
 动态返回配置的theme name

 @param themeName theme name
 */
- (void)didLoadThemeName:(NSString *)themeName;

/**
 宿主自定义的view，会被作为header的一部分，插入在搜索或者Banner和Feed之间。
 自定View的时候请设置view的frame。
 @param index 栏目下标，针对不同的栏目可定义不同的Header
 @return UIView
 */
- (UIView *)viewForFeedListHeaderAtIndex:(NSInteger)index;

/**
 栏目加载成功的回调

 @param columnssArray 栏目数据
 */
- (void)didLoadFeedColumnssArray:(NSArray <BotBrainFeedColumnModel *>*)columnssArray;

/**
 宿主可自定义显示部分栏目

 @param array 原始栏目数组
 @return 返回过滤后的栏目数组
 */
- (NSArray<BotBrainFeedColumnModel *> *)filterFeedListColumnWithOriginArray:(NSArray <BotBrainFeedColumnModel *>*)array;

@end
