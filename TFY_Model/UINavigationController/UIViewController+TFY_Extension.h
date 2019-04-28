//
//  UIViewController+TFY_Extension.h
//  WYBasisKit
//
//  Created by 田风有 on 2019/03/27.
//  Copyright © 2019 恋机科技. All rights reserved.
//


#import <UIKit/UIKit.h>

@protocol ViewControllerHandlerProtocol <NSObject>

@optional

/** 重写下面的方法以拦截导航栏pop事件，返回 YES 则 pop，NO 则不 pop  默认返回上一页 */
- (BOOL)tfy_navigationBarWillReturn;

@end

///viewController显示模式
typedef NS_ENUM(NSInteger, TFYDisplaMode) {
    /** push */
    TFY_DisplaModePush = 0,
    /** present */
    TFY_DisplaModePresent,
};

@interface UIViewController (TFY_Extension)<ViewControllerHandlerProtocol>

/** 从导航控制器栈中查找ViewController，没有时返回nil */
- (UIViewController *)tfy_findViewController:(NSString *)className;

/** 删除指定的视图控制器 */
- (void)tfy_deleteViewController:(NSString *)className complete:(void(^)(void))complete;

/** 跳转到指定的视图控制器 */
- (void)tfy_showViewController:(NSString *)className animated:(BOOL)animated displaMode:(TFYDisplaMode)displaMode;

/** 跳转到指定的视图控制器，此方法可防止循环跳转 */
- (void)tfy_showOnlyViewController:(NSString *)className animated:(BOOL)animated displaMode:(TFYDisplaMode)displaMode;

/** 返回到指定的视图控制器 */
- (void)tfy_gobackViewController:(NSString *)className animated:(BOOL)animated;

/** viewController是push还是present的方式显示的 */
- (TFYDisplaMode)tfy_viewControllerDisplaMode;


@end
