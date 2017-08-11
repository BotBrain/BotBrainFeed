//
//  BOTDragViewController.m
//  BotBrainFeed
//
//  Created by ZHAN on 2017/8/11.
//  Copyright © 2017年 zhangzhanzg. All rights reserved.
//

#import "BOTDragViewController.h"
#import "BOTDragContentViewController.h"
#import <BotBrainPods/BotBrainManager.h>

static CGFloat const BotBrainFeedDefaultOffsetY = 300;
static CGFloat const BotBrainFeedNavigationHeight = 64.;

#define BOTSCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define BOTSCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

@interface BOTDragViewController ()<UIScrollViewDelegate>

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UILabel *topLabel;

@end

@implementation BOTDragViewController

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [self.navigationController setNavigationBarHidden:NO animated:YES];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self.navigationController setNavigationBarHidden:YES animated:YES];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    UIView *tmpView = [UIView new];
    tmpView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:tmpView];
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, BOTSCREEN_WIDTH, BOTSCREEN_HEIGHT)];
    _scrollView.backgroundColor = [UIColor cyanColor];
    [self.view addSubview:_scrollView];
    _scrollView.contentSize = CGSizeMake(BOTSCREEN_WIDTH, 1000);
    _scrollView.delegate = self;
    
    self.topLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, BotBrainFeedDefaultOffsetY + BotBrainFeedNavigationHeight, BOTSCREEN_WIDTH, BotBrainFeedNavigationHeight)];
    _topLabel.backgroundColor = [UIColor lightGrayColor];
    _topLabel.text = @"布本头条";
    _topLabel.textAlignment = NSTextAlignmentCenter;
    [_scrollView addSubview:_topLabel];

    
    BOTDragContentViewController *contentVC = [[BOTDragContentViewController alloc] init];
    [self addChildViewController:contentVC];
    [contentVC didMoveToParentViewController:self];
    [self.scrollView addSubview:contentVC.view];
    contentVC.view.frame = CGRectMake(0, BotBrainFeedDefaultOffsetY, BOTSCREEN_WIDTH, BOTSCREEN_HEIGHT - BotBrainFeedNavigationHeight - 44);
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeSystem];
    [button1 setTitle:@"返回" forState:UIControlStateNormal];
    button1.titleLabel.textAlignment = NSTextAlignmentCenter;
    button1.backgroundColor = [UIColor lightGrayColor];
    button1.frame = CGRectMake(0, BOTSCREEN_HEIGHT - 44, BOTSCREEN_WIDTH / 2., 44.);
    [self.view addSubview:button1];
    [button1 addTarget:self action:@selector(tapBackButton:) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:@"主页" forState:UIControlStateNormal];
    button.titleLabel.textAlignment = NSTextAlignmentCenter;
    button.backgroundColor = [UIColor lightGrayColor];
    button.frame = CGRectMake(BOTSCREEN_WIDTH / 2., BOTSCREEN_HEIGHT - 44, BOTSCREEN_WIDTH / 2., 44.);
    [self.view addSubview:button];
    [button addTarget:self action:@selector(tapHomeButton:) forControlEvents:UIControlEventTouchUpInside];
    
    [[BotBrainManager defaultManager] setBotBrainFeedVerticalScrollEnable:NO];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)tapBackButton:(UIButton *)button {
    [self dismissViewControllerAnimated:YES completion:nil];
}
- (void)tapHomeButton:(UIButton *)button {
    [self reload];
}

- (void)reload {
    
    _topLabel.frame = CGRectMake(0, BotBrainFeedDefaultOffsetY + BotBrainFeedNavigationHeight, BOTSCREEN_WIDTH, BotBrainFeedNavigationHeight);
    [[BotBrainManager defaultManager] setBotBrainFeedVerticalScrollEnable:NO];
    [_scrollView setContentOffset:CGPointMake(0., 0.) animated:YES];
    _scrollView.scrollEnabled = YES;
}

#pragma mark - UIScrollViewDelegated

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    if (scrollView.contentOffset.y >= BotBrainFeedDefaultOffsetY - BotBrainFeedNavigationHeight) {
        [_scrollView setContentOffset:CGPointMake(0, BotBrainFeedDefaultOffsetY - BotBrainFeedNavigationHeight) animated:NO];
        scrollView.scrollEnabled = NO;
        [[BotBrainManager defaultManager] setBotBrainFeedVerticalScrollEnable:YES];
        _topLabel.frame = CGRectMake(0, BotBrainFeedDefaultOffsetY - 50, BOTSCREEN_WIDTH, BotBrainFeedNavigationHeight);
        [UIView animateWithDuration:0.25 animations:^{
            _topLabel.frame = CGRectMake(0, BotBrainFeedDefaultOffsetY - BotBrainFeedNavigationHeight, BOTSCREEN_WIDTH, BotBrainFeedNavigationHeight);
        }];
        return;
    }
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
