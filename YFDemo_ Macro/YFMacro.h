//
//  YFMacro.h
//  YFDemo_ Macro
//
//  Created by 亚飞 on 2018/4/22.
//  Copyright © 2018年 yafei. All rights reserved.
//

#ifndef YFMacro_h
#define YFMacro_h


/** MainScreen bounds */
#define Main_Screen_Bounds [[UIScreen mainScreen] bounds]
/** 屏幕宽高 */
#define kLFSCREEN_W [UIScreen mainScreen].bounds.size.width
#define kLFSCREEN_H [UIScreen mainScreen].bounds.size.height
/** 状态栏的size */
#define kstatusBarSize [[UIApplication sharedApplication] statusBarFrame].size


/** 屏幕尺寸 */
#define IS_SCREEN_4_INCH    ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_SCREEN_35_INCH   ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_SCREEN_47_INCH   ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_SCREEN_55_INCH   ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

/** 屏幕尺寸 */
#define is_screen_35_inch   CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(320, 480))
#define is_screen_40_inch   CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(320, 568))
#define is_screen_47_inch   CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(375, 667))
#define is_screen_55_inch   CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(414, 736))

//不同屏幕尺寸字体适配（320，568是因为效果图为IPHONE5 如果不是则根据实际情况修改）
#define kScreenWidthRatio  (Main_Screen_Width / 320.0)
#define kScreenHeightRatio (Main_Screen_Height / 568.0)
#define AdaptedWidth(x)  ceilf((x) * kScreenWidthRatio)
#define AdaptedHeight(x) ceilf((x) * kScreenHeightRatio)
#define AdaptedFontSize(R)     CHINESE_SYSTEM(AdaptedWidth(R))

// 字体大小(常规/粗体)
#define BOLDSYSTEMFONT(FONTSIZE)[UIFont boldSystemFontOfSize:FONTSIZE]
#define SYSTEMFONT(FONTSIZE)    [UIFont systemFontOfSize:FONTSIZE]
#define FONT(NAME, FONTSIZE)    [UIFont fontWithName:(NAME) size:(FONTSIZE)]

//中文字体
#define CHINESE_FONT_NAME  @"Heiti SC"
#define CHINESE_SYSTEM(x) [UIFont fontWithName:CHINESE_FONT_NAME size:x]

//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG

#define RZLog(FORMAT, ...) do {                                     \
fprintf(stderr,"\nfunction:%s \nline:%d content: -> %s\n",          \
__FUNCTION__,                                                       \
__LINE__,                                                           \
[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);    \
} while (0)

#else
#define RZLog(FORMAT, ...) nil
#endif

/** 系统版本 */
#define FSystemVersion  ([[[UIDevice currentDevice] systemVersion] floatValue])
#define DSystemVersion  ([[[UIDevice currentDevice] systemVersion] doubleValue])
#define SSystemVersion  ([[UIDevice currentDevice] systemVersion])

#define ios7_or_later ([UIDevice currentDevice].systemVersion.floatValue >= 7.0)
#define ios8_or_later ([UIDevice currentDevice].systemVersion.floatValue >= 8.0)
#define ios9_or_later ([UIDevice currentDevice].systemVersion.floatValue >= 9.0)

/** 当前app信息 */
#define kbundelId [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"]
#define kexecutable  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleExecutable"]
#define kdisplayName  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]

/** 应用的Verison号 */
#define kappVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

/** build号 */
#define kappBuild [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

/** AppDelegate对象 */
#define AppDelegateInstance [[UIApplication sharedApplication] delegate]

//获取图片资源
#define GetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]

//Library/Caches 文件路径
#define FilePath ([[NSFileManager defaultManager] URLForDirectory:NSCachesDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:YES error:nil])
//获取沙盒Document路径
#define kDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒temp路径
#define kTempPath NSTemporaryDirectory()
//获取沙盒Cache路径
#define kCachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//真机
#endif

#if TARGET_IPHONE_SIMULATOR
//模拟器
#endif

//NSUserDefaults 实例化
/**  以key,value存储信息 */
#define USERDEFAULTSET(key,value) [[NSUserDefaults standardUserDefaults] setObject:value forKey:key]
/** 以key取出value */
#define USERDEFAULTS(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]
/** 以key删除value */
#define USERDEFAULTREMOVE(key) [[NSUserDefaults standardUserDefaults] removeObjectForKey:key]
/** 立即同步 */
#define USERDEFAULTSYNCHRONIZE  [[NSUserDefaults standardUserDefaults] synchronize]

/** 是否是iPad */
#define isPad  (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
/** 判断是否为iPhone */
#define isIPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)



/***************************    颜色宏    ***************************/


/** 三原色 */
#define UIColorRGBA(_r, _g, _b, _a) [UIColor colorWithRed:_r/255.f green:_g/255.f blue:_b/255.f alpha:_a]
#define UIColorRgb(_r, _g, _b) UIColorRGBA(_r, _g, _b, 1.0f)

/** 传入色值 */
#define LFHEXCOLOR_a(hex,a) [UIColor colorWithRed:((float)((hex & 0xFF0000) >> 16)) / 255.0 green:((float)((hex & 0xFF00) >> 8)) / 255.0 blue:((float)(hex & 0xFF)) / 255.0 alpha:(a)]
#define LFHEXCOLOR(hex) [UIColor colorWithRed:((float)((hex & 0xFF0000) >> 16)) / 255.0 green:((float)((hex & 0xFF00) >> 8)) / 255.0 blue:((float)(hex & 0xFF)) / 255.0 alpha:1]

/** 随机色  */
#define LFRandomColor UIColorRgb(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))


/***************************    ios11适配    ***************************/

/** 透明背景色 */
#define CLEARCOLOR [UIColor clearColor]
#define kAdjustmentBehavior(VC, view) if (@available(iOS 11.0, *)) {                \
view.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;  \
} else {                                                                            \
VC.automaticallyAdjustsScrollViewInsets = NO;                                   \
}                                                                                   \



/***************************    线程队列    ***************************/

/*! 主线程同步队列 */
#define dispatch_main_sync_safe(block)          \
if ([NSThread isMainThread]) {                  \
block();                                        \
} else {                                        \
dispatch_sync(dispatch_get_main_queue(), block);\
}
/*! 主线程异步队列 */
#define dispatch_main_async_safe(block)        \
if ([NSThread isMainThread]) {                 \
block();                                       \
} else {                                       \
dispatch_async(dispatch_get_main_queue(), block);\
}


/***************************    引用的一些宏    ***************************/

//字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
//数组是否为空
#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//字典是否为空
#define kDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
//是否是空对象
#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

//一些缩写
#define kApplication [UIApplication sharedApplication]
#define kKeyWindow [UIApplication sharedApplication].keyWindow
#define kAppDelegate [UIApplication sharedApplication].delegate
#define kUserDefaults [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]

/** 当前语言 */
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//获取一段时间间隔
#define kStartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define kEndTime   NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)

//弱引用/强引用
#define kWeakSelf(type)   __weak typeof(type) weak##type = type;
#define kStrongSelf(type) __strong typeof(type) type = weak##type;

/*! 复制文字内容 */
#define BAKit_CopyContent(content) [[UIPasteboard generalPasteboard] setString:content]

//上传图片相关
#define kImageCollectionCell_Width floorf((Main_Screen_Width - 10*2- 10*3)/3)
//最大的上传图片张数
#define kupdateMaximumNumberOfImage 12

//由角度转换弧度
#define kDegreesToRadian(x)      (M_PI * (x) / 180.0)
//由弧度转换角度
#define kRadianToDegrees(radian) (radian * 180.0) / (M_PI)


#endif /* YFMacro_h */
