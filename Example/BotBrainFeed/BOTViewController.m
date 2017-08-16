//
//  BOTViewController.m
//  BotBrainFeed
//
//  Created by zhangzhanzg on 07/12/2017.
//  Copyright (c) 2017 zhangzhanzg. All rights reserved.
//

#import "BOTViewController.h"
#import <BotBrainPods/BotBrainManager.h>

#import "BOTContentViewController.h"
#import "BOTDragViewController.h"

@interface BOTViewController ()<BotBrainFeedDetailDelegate>

@end

@implementation BOTViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [BotBrainManager startWithAppKey:@"S4EBUTASGJ" appSecret:@"aaa" channelID:@"AppStore"];
    [[BotBrainManager defaultManager] addFeedDetailDelegate:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - BotBrainFeedDetailDelegate

/**
 分享 - 点击右上角
 
 @param shareModel 当前Model
 */
- (void)botBrainDidShareWithShareModel:(BotBrainFeedShareModel *)shareModel {
    NSLog(@"分享：%@", shareModel);
}
/**
 分享 - 点击底部分享按钮
 
 @param shareModel 当前Model
 */
- (void)botBrainDidTapBottomShareWithShareModel:(BotBrainFeedShareModel *)shareModel {
    NSLog(@"分享：%@", shareModel);
}

/**
 发布评论 - 将要回复评论时（可实现此方法来提示用户登录）
 
 @param shareModel 当前Model
 */
- (void)botBrainWillCommentWithShareModel:(BotBrainFeedShareModel *)shareModel {
    if ([BotBrainManager defaultManager].isLoggedIn) {
        return;
    }
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"评论前请先登录" message:nil preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *ensureAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self logInCommentSystem];
    }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }];
    [alert addAction:ensureAction];
    [alert addAction:cancelAction];
    
    // 注意：此处请使用 [BotBrainManager currentShowViewController] 来模态出登录VC
    // 因为评论二级页面也是模态弹出
    [[BotBrainManager currentShowViewController] presentViewController:alert animated:YES completion:nil];
}

- (void)logInCommentSystem {
    BotBrainUserInfoModel *model = [BotBrainUserInfoModel new];
    model.userID = @"ca06423f8fe046399b3d65bdc2956075";
    model.userIcon = @"http://image-1252904967.costj.myqcloud.com/user_info/S4EBUTASGJ/1501476770200.jpg";
    model.userNickName = @"BotBrain007";
    [[BotBrainManager defaultManager] loginWithUserInfo:model success:^(BotBrainUserInfoModel *userInfo) {
        
    } failure:^(NSError *error) {
        
    }];
}

#pragma mark - event response
// 直接Push出图文列表
- (IBAction)tapPushButton:(UIButton *)sender {
    [[BotBrainManager defaultManager] showBotBrainFeedOnViewController:self animated:YES];
}
// 模态出图文列表。建议使用这种方式来模态，方便自定义导航栏
// 此种方式，图文列表是以 Chile VC 添加到 BOTContentViewController 中的
- (IBAction)tapPresentButton:(UIButton *)sender {
    BOTContentViewController *contentVC = [BOTContentViewController new];
    UINavigationController *navigation = [[UINavigationController alloc] initWithRootViewController:contentVC];
    [self presentViewController:navigation animated:YES completion:nil];
    
}
// 模仿UC浏览器拖拽效果
- (IBAction)tapDragButton:(UIButton *)sender {
    BOTDragViewController *dragVC = [BOTDragViewController new];
    [self presentViewController:dragVC animated:YES completion:nil];
}

@end
