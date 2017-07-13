
#import <Foundation/Foundation.h>

@protocol FireDataManagerDelegate <NSObject>

@optional
/* 统计SDK捕获到异常，程序即将崩溃时，回调此函数 */
- (void)onCrash;

/**
 定义协议函数，在SDK内部捕获到对应崩溃事件，并将对应的崩溃事件添加到事件队列后进行对应的事件处理，并将当前获取到的异常信息对象传递
 */
- (void)onCrashAfterAddedToEventArrWithCrashInfo:(NSDictionary *)exception;

@end

@interface FireDataManager : NSObject


+ (FireDataManager *)sharedInstance;

@property (nonatomic, weak) id<FireDataManagerDelegate> delegate;
/** Debug模式，此时打印调试日志，默认为NO */
@property (nonatomic, assign) BOOL debugMode;
/** 是否收集APP异常崩溃事件，默认为YES */
@property (nonatomic, assign) BOOL enableCrashReport;
/** 是否收集地理位置， 默认为NO，如果设置为YES，请在Info.plist文件中添加相应的描述信息 */
@property (nonatomic, assign) BOOL enableLocationReport;
/** check 本地缓存日志间隔，默认为15分钟 */
@property (nonatomic, assign) NSInteger sendTimeInterval;
/** 会话时间间隔，默认为10分钟 */
@property (nonatomic, assign) NSInteger sessionInterval;
/** 日志缓存最高条数限制，默认为50条 */
@property (nonatomic, assign) NSInteger bufferNumber;
/** 是否允许获取 IDFA，默认为允许 YES，此时更精确，提交APP时注意勾选相应选项 */
@property (nonatomic, assign) BOOL enableIDFA;
/*
 初始化设置
 */
- (void)initWithAppKey:(NSString *)appKey distributors:(NSString *)channelId;
/*
 用户登录
 */
- (void)loginWithUserid:(NSString *)uid uvar:(NSDictionary *)uvar;

/*
 用户退出登录
 */
- (void)logout;

/**
 在该页面展示时调用beginLogPageView:，当退出该页面时调用endLogPageView:
 @param pageName 当前所处的页面名称.
 @param attributes pv级作用域的参数, 应包含 cid:cid, cch:channel
 @param cvar 内容额外参数
 */
- (void)beginLogPageView:(NSString *)pageName
              attributes:(NSDictionary *)attributes
                    cvar:(NSDictionary *)cvar;

/**
 必须配对调用beginLogPageView:和endLogPageView:两个函数来完成自动统计，若只调用某一个函数不会生成有效数据。
 在该页面展示时调用beginLogPageView:，当退出该页面时调用endLogPageView:
 @param pageName 统计的页面名称.
 */
- (void)endLogPageView:(NSString *)pageName;

/*
 自定义事件
 @param category 事件分类 (如：Videos, Music, Games...)
 @param action 动作 (如Play, Pause, Duration, Buy)
 @param evar 事件统计参数（json格式）
 @param attributes 额外统计参数（可选，预留，若有值则以 key1=value1&key2=value2的形式加入post参数中）
 */
- (void)eventWithCategory:(NSString *)category
                   action:(NSString *)action
                     evar:(NSDictionary *)evar
               attributes:(NSDictionary *)attributes;
/*
 重置各级作用域的相关参数
 */
- (void)resetUserid:(NSString *)uid
               uvar:(NSDictionary *)uvar
               cvar:(NSDictionary *)cvar
          contentId:(NSString *)cid
         contentCat:(NSString *)cch;

///---------------------------------------------------------------------------------------
/// @name  公用参数
///---------------------------------------------------------------------------------------
/** 用户ID */
- (NSString *)userid;
/** 设备ID，如果允许IDFA，则使用IDFA，反之使用OpenUUID计算 */
- (NSString *)guid;
/** IDFA */
- (NSString *)idfa;
/** IDFV */
- (NSString *)idfv;
/** SDK版本 */
- (NSString *)analyticsSDKVersion;

@end
