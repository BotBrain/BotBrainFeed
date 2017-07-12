//
//  TourHeader.h
//  BuBenTour
//
//  Created by BotBrain on 17/4/7.
//  Copyright © 2017年 Languang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BotBrainUserInfoModel.h"
#import "BotBrainFeedShareModel.h"
#import "BotBrainFeedDetailDelegate.h"

@interface BotBrainManager : NSObject

/** 用户AppKey */
@property (nonatomic, copy, readonly) NSString *appKey;
/** 用户是否登录 */
@property (nonatomic, assign, readonly) BOOL isLoggedIn;
/** 用户登录信息 */
@property (nonatomic, strong, readonly) BotBrainUserInfoModel *userInfo;

@property (nonatomic, weak, readonly) id <BotBrainFeedDelegate> feedDelegate;
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
 显示Feed流Controller，显示前配置相关属性
 UINavigationController push 显示
 UIViewController presentViewController

 @param viewController 当前屏幕显示 主控制器
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

/** 当前显示的ViewController */
+ (UIViewController *)currentShowViewController;

@end
