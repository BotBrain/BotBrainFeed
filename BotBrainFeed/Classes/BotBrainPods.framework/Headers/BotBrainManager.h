//
//  BotBrainManager.h
//  BotBrainManager
//
//  Created by BotBrain on 17/4/7.
//  Copyright © 2017年 BotBrain. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BotBrainFeedDetailDelegate.h"

/// 分享回调模型
@interface BotBrainFeedShareModel : NSObject
/** 文章标题 */
@property (nonatomic, copy) NSString *feedItemTitle;
/** 文章摘要，可能为空 */
@property (nonatomic, copy) NSString *feedItemSummary;
/** 文章URL */
@property (nonatomic, copy) NSString *feedItemURL;
/** 文章ID */
@property (nonatomic, copy) NSString *feedItemID;
/** 分享图片URL */
@property (nonatomic, copy) NSString *shareImageURL;
/** 分享、点赞、评论出错信息，为nil，则正常 */
@property (nonatomic, strong) NSError *error;

@end

/// 用户基本信息，评论时需要调用登录接口传入此信息
@interface BotBrainUserInfoModel : NSObject

/** 登录用户ID，必填 */
@property (nonatomic, copy) NSString *userID;
/** 用户头像URL，选填 */
@property (nonatomic, copy) NSString *userIcon;
/** 用户昵称，选填，默认BotBrain */
@property (nonatomic, copy) NSString *userNickName;

@end

typedef NS_ENUM(NSUInteger, BOTFeedThemeType) {
    BOTFeedThemeType_Normal,    // 正常模式
    BOTFeedThemeType_Night,     // 夜间模式
};

/// Feed流管理类
@interface BotBrainManager : NSObject

/** 用户AppKey */
@property (nonatomic, copy, readonly) NSString *appKey;
/** 用户是否登录 */
@property (nonatomic, assign, readonly) BOOL isLoggedIn;
/** 用户登录信息 */
@property (nonatomic, strong, readonly) BotBrainUserInfoModel *userInfo;
/** Feed流代理 */
@property (nonatomic, weak, readonly) id <BotBrainFeedDelegate> feedDelegate;
/** 详情代理 */
@property (nonatomic, weak, readonly) id <BotBrainFeedDetailDelegate> detailDelegate;

+ (instancetype)defaultManager;

/**
 初始化SDK

 @param appKey 用户AppKey
 @param appSecret 用户AppSecret
 @param channelID App渠道，默认AppStore
 */
+ (void)startWithAppKey:(NSString *)appKey
              appSecret:(NSString *)appSecret
              channelID:(NSString *)channelID;

/**
 是否输出Log，默认NO

 @param enable YES or NO
 */
+ (void)setBotBrainLogEnable:(BOOL)enable;

/**
 显示Feed流Controller

 @param viewController 当前显示的 ViewController 或者传入 navigationController
 优先选择Push方式，如果无法 push，则选择 模态显示
 不建议使用此方法模态展示， 可以使用 “- (void)addBotBrainFeedOnView:(id)view inViewController:(id)viewController”
 将Feed流 VC 添加到你自定义的 VC 上面，然后模态出你自定义的 VC，方便你定制导航栏
 
 @param animated       是否动画  YES/NO
 */
- (void)showBotBrainFeedOnViewController:(id)viewController animated:(BOOL)animated;


/**
 显示Feed列表

 @param view 要添加到哪个view上
 @param viewController 要显示在哪个ViewController里面
 （如果viewController包含在导航栏中，详情页以push方式展示，否则以模态方式）
 */
- (void)addBotBrainFeedOnView:(id)view inViewController:(id)viewController;

/**
 登录评论系统

 @param userInfo 登录用户信息
 @param success 登录成功
 @param failure 登录失败
 */
- (void)loginWithUserInfo:(BotBrainUserInfoModel *)userInfo
                  success:(void(^)(BotBrainUserInfoModel *userInfo))success
                  failure:(void(^)(NSError *error))failure;

/**
 退出登录

 @param callBack error为nil时退出成功。
 */
- (void)logoutWithCallBack:(void(^)(NSError *error))callBack;

/**
 添加回调代理，响应详情相关事件

 @param delegate 代理
 */
- (void)addFeedDetailDelegate:(id<BotBrainFeedDetailDelegate>)delegate;


/**
 添加回调代理，控制列表相关

 @param delegate 代理
 */
- (void)addFeedDelegate:(id<BotBrainFeedDelegate>)delegate;

/**
 图文分享成功后请调用此方法。
 */
- (void)shareBotBrainFeedSuccess;


/**
 刷新列表数据

 @param index 要刷新栏目的下标，从0开始。
 */
- (void)reloadBotBrainFeedDataAtIndex:(NSInteger)index;

/**
 刷新当前展示列表数据
 */
- (void)reloadCurrentShowFeedListData;

/// 通过禁止竖直方向滑动，可做浏览器拖拽效果（UC浏览器）
/// NO: 竖直方向Feed流不可滑动，顶部栏目隐藏
/// YES: 竖直方向Feed流可滑动，顶部栏目显示
/** 设置Feed流竖直方向可否滑动 */
- (void)setBotBrainFeedVerticalScrollEnable:(BOOL)enable;

/**
 是否能处理OpenURL
 @param openURL openURL
 @return BOOL
 */
+ (BOOL)handleOpenURL:(NSURL *)openURL;

/**
 显示详情页（此方法请在 "+ (BOOL)handleOpenURL:(NSURL *)openURL" 返回YES的情况下调用）
 
 @param URL openURL
 @param controller 用来展示详情页的controller，优先选择push方式，可为nil
 */
- (void)showBotBrainDetaiControllerWithURL:(NSURL *)URL onController:(id)controller;

- (void)showBotDetailControllerWithItemID:(NSString *)itemID;

+ (void)changeFeedThemeForType:(BOTFeedThemeType)type;

/** 当前显示的ViewController */
+ (UIViewController *)currentShowViewController;

@end
