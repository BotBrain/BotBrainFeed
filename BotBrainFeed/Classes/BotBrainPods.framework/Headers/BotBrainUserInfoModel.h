//
//  BotBrainUserInfoModel.h
//  BotBrainLib
//
//  Created by ZHAN on 2017/5/10.
//  Copyright © 2017年 ZHAN. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BotBrainUserInfoModel : NSObject

/** 登录用户ID，必填 */
@property (nonatomic, copy) NSString *userID;
/** 用户头像URL，选填 */
@property (nonatomic, copy) NSString *userIcon;
/** 用户昵称，选填，默认BotBrain */
@property (nonatomic, copy) NSString *userNickName;

@end
