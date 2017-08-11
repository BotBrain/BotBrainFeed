//
//  BOTContentViewController.m
//  BotBrainFeed
//
//  Created by ZHAN on 2017/8/11.
//  Copyright © 2017年 zhangzhanzg. All rights reserved.
//

#import "BOTContentViewController.h"
#import <BotBrainPods/BotBrainManager.h>

@interface BOTContentViewController ()

@end

@implementation BOTContentViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [[BotBrainManager defaultManager] addBotBrainFeedOnView:self.view inViewController:self];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"关闭" style:UIBarButtonItemStylePlain target:self action:@selector(dismiss)];
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"切换主题" style:UIBarButtonItemStylePlain target:self action:@selector(change)];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - event response

- (void)dismiss {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)change {
    static BOOL night = NO;
    if (!night) {
        [BotBrainManager changeFeedThemeForType:BOTFeedThemeType_Night];
    } else {
        [BotBrainManager changeFeedThemeForType:BOTFeedThemeType_Normal];
    }
    night = !night;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
