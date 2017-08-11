//
//  BOTDragContentViewController.m
//  BotBrainFeed
//
//  Created by ZHAN on 2017/8/11.
//  Copyright © 2017年 zhangzhanzg. All rights reserved.
//

#import "BOTDragContentViewController.h"
#import <BotBrainPods/BotBrainManager.h>
@interface BOTDragContentViewController ()

@end

@implementation BOTDragContentViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [[BotBrainManager defaultManager] addBotBrainFeedOnView:self.view inViewController:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
