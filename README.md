# BotBrainFeed

[![Version](https://img.shields.io/cocoapods/v/BotBrainFeed.svg?style=flat)](http://cocoapods.org/pods/BotBrainFeed)
[![License](https://img.shields.io/cocoapods/l/BotBrainFeed.svg?style=flat)](http://cocoapods.org/pods/BotBrainFeed)
[![Platform](https://img.shields.io/cocoapods/p/BotBrainFeed.svg?style=flat)](http://cocoapods.org/pods/BotBrainFeed)

## Requirements

iOS 8.0+ is required.

## Installation

BotBrainFeed is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "BotBrainFeed", '~> 1.2.3'
```

## Usage

### 1、集成准备
**SDK支持最低版本为8.0。**

#### 1.1、获取AppKey和AppSecret

集成布本智能SDK之前，请您先获取相关的AppKey和AppSecret。
#### 1.2、项目工程集成配置
##### 1.2.1、手动集成

请先 [下载SDK](https://github.com/BotBrain/BotBrainFeed) ，SDK包含 `BotBrainFeed` 下所有文件。
把SDK直接拖入进工程目录结构中，然后在选项 `TARGETS--> Build Phases-->Link Binary With Libraries` 中添加系统依赖库 `libz.tbd` 、`WebKit.framework`。

然后在选项 `TARGETS--> Build Settings-->Linking-->Other Linker Flags` 添加 `-ObjC` 。

本SDK依赖于常用开源网络库 `AFNetworking` 和图片处理库 `SDWebImage` ， 请您自行导入工程。

##### 1.2.2、CocoaPods集成
1. 在 `Podfile` 文件中添加：

```
pod 'BotBrainFeed', '~>1.2.2'
```
2. 在终端 `cd` 到 `Podfile` 文件所在路径，执行 `pod install`


### 2、基本功能集成
#### 2.1、配置 `AppDelegate.m`

导入头文件 `#import "BotBrainManager.h"`

`AppDelegate.m` 的配置主要是填写 `Appkey` 和 `AppSecret` 以及渠道标识 `channel` ，channel默认为“AppStore”。
代码示例如下:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // 通过此方法初始化SDK，替换成自己的相关信息
    [BotBrainManager startWithAppKey:@"" appSecret:@"" channelID:@""];
    
    return YES;
}
```

新版本可以打开 `Debug` 模式，打印出log，方便调试，开始方法：

```
[BotBrainManager setBotBrainLogEnable:YES];
```
请先于初始化SDK调用此方法开启 `Debug` 模式


#### 2.2、展示图文列表

在你要展示图文列表的 `UIViewController` 中导入头文件 `#import "BotBrainManager.h"`。

在你想要展示图文列表的点击事件中调用如下代码：

```
[[BotBrainManager defaultManager] showBotBrainFeedOnViewController:self animated:YES];
```

SDK会优先选择Push方式显示ViewController，无法Push的时候会模态出一个带导航栏的图文列表。

你还可以直接添加到当前ViewController的view上：

```
[[BotBrainManager defaultManager] addBotBrainFeedOnView:self.view inViewController:self];
```

注意：分享后请调用以下方法：

```
[[BotBrainManager defaultManager] shareBotBrainFeedSuccess];
```
如果未调用此方法会影响内容的推荐效果。

#### 2.3、图文详情的回调

详情页的回调通过代理来实现。在你想要响应 `评论、点赞、分享` 等操作的类中实现代理方法即可。

首先让该类服从协议 `BotBrainFeedDetailDelegate`。
然后添加代理

```
[[BotBrainManager defaultManager] addFeedDetailDelegate:self];
```

最后在该类中实现代理方法。

目前提供的回调如下所示：

```
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

```

其中发布评论时需要登录账号，接入者根据 `BotBrainManager` 类中属性 `isLoggedIn` 来判断当前用户是否已经登录，未登录、评论成功失败都会响应评论的代理方法， `shareModel` 里会返回相应的错误信息。

未登录时提示用户去登录，UI展示效果接入者自己实现，本地不保存用户信息，所以每次APP重新启动时都需要登录。

登录时代码调用示例如下：

```
- (void)logInCommentSystem {
    BotBrainUserInfoModel *userInfo = [BotBrainUserInfoModel new];
    userInfo.userID = @"123456";
    userInfo.userIcon = @"http://balabala";
    userInfo.userNickName = @"BotBrain";
    [[BotBrainManager defaultManager] loginWithUserInfo:userInfo success:^(BotBrainUserInfoModel *userInfo) {
        NSLog(@"UserInfo：%@", userInfo);
    } failure:^(NSError *error) {
        NSLog(@"Error：%@", error);
    }];
}
```
其中 `userID` 不能为空，其他自行选择传入，如果未传，则为默认。

### 3、界面定制
目前提供有限定制，后期会开放更多。

#### 3.1、针对图文列表的定制：
图文列表相关的定制通过代理 `BotBrainFeedDelegate` 来实现。

##### 3.1.1、列表左右滑动功能
通过实现方法 `- (BOOL)feedShouldForbidRoll;` 来控制是否禁止图文列表左右滑动切换的功能。

代码示例如下：

```
- (BOOL)feedShouldForbidRoll {
    return YES;
}
```
返回YES则禁止左右滑动，不实现此方法或者返回NO不禁止。

##### 3.1.2、图文列表无结果时展示View

通过实现方法 `- (UIView *)viewForNoResultTableViewAtIndex:(NSInteger)index;` 返回自定义的占位视图，默认空白。

代码示例如下：

```
- (UIView *)viewForNoResultTableViewAtIndex:(NSInteger)index {
    UILabel *label = [[UILabel alloc] init];
    label.text = @(index).stringValue;
    label.font = [UIFont boldSystemFontOfSize:30];
    return label;
}
```

如果发生没有数据展示的情况，可以调用方法来刷新列表数据：

```
[[BotBrainManager defaultManager] reloadBotBrainFeedDataAtIndex:0];
```

其中index下标从0开始，对应栏目下标。

##### 3.1.3、支持夜间模式
具体实现见Demo
##### 3.1.4、支持UC浏览器交互效果
具体实现见Demo

### 4、从Web端跳转到App并显示图文详情
SDK支持从分享出去的文章详情跳转到App对应的详情页，请提前在配置平台和工程中配置好 `URL Scheme` 。

为了能正确显示详情页，需要在 `AppDelegate` 文件中添加如下代码：

```
// iOS 8 请用这个
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    if ([BotBrainManager handleOpenURL:url]) {
        [[BotBrainManager defaultManager] showBotBrainDetaiControllerWithURL:url onController:self.window.rootViewController];
        return YES;
    }
    return YES;
}

// iOS 9 以上请用这个
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options {
    if ([BotBrainManager handleOpenURL:url]) {
        [[BotBrainManager defaultManager] showBotBrainDetaiControllerWithURL:url onController:self.window.rootViewController];
        return YES;
    }
    return YES;
}
```
其中，方法 `- showBotBrainDetaiControllerWithURL:onController`中参数 `controller` 是用来展示 `详情ViewController` 的，可以为 `nil` ，为 `nil` 时 `SDK` 会寻找当前显示 `ViewController` 来进行跳转。


### 5、注意
5.1、 针对 `iOS 9` 及以上系统的限制 `http` 协议的访问，如果 `App` 需要访问 `http://` ， 则需要在 `Info.plist` 添加如下代码:

```
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

5.2、针对使用 Xcode 7 编译失败，遇到错误信息为:

```
*** does not contain bitcode. You must rebuild it with bitcode enabled (Xcode setting ENABLE_BITCODE), obtain an updated library from the vendor, or disable bitcode for this target.
```
请到 `Xcode` 项目的 `Build Settings` 标签页搜索 `bitcode` ，将 `Enable Bitcode` 设置为 `NO` 即可。

## Author

BotBrain, zhangzhan@firedata.cc

## License
Copyright (c) 2016 BotBrain. All rights reserved




