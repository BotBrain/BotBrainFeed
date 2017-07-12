//
//  BOTViewController.m
//  BotBrainFeed
//
//  Created by zhangzhanzg on 07/12/2017.
//  Copyright (c) 2017 zhangzhanzg. All rights reserved.
//

#import "BOTViewController.h"
#import <BotBrainPods/BotBrainManager.h>

@interface BOTViewController ()

@end

@implementation BOTViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [BotBrainManager startWithAppKey:@"S4EBUTASGJ" appSecret:@"aaa" channelID:@"AppStore"];
    [[BotBrainManager defaultManager] addBotBrainFeedOnView:self.view inViewController:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
