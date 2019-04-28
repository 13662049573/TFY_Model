//
//  UIViewController+TFY_Extension.m
//  WYBasisKit
//
//  Created by 田风有 on 2019/03/27.
//  Copyright © 2019 恋机科技. All rights reserved.
//

#import "UIViewController+TFY_Extension.h"

#define weakSelf(type)      __weak typeof(type) weak##type = type;

@implementation UIViewController (TFY_Extension)

- (UIViewController *)tfy_findViewController:(NSString *)className {
    
    if([self tfy_emptyStr:className].length <= 0) return nil;
    
    Class class = NSClassFromString(className);
    
    if (class == nil) return nil;
    
    for (UIViewController *controller in self.navigationController.viewControllers) {
        
        if([controller isKindOfClass:class]) {
            
            return controller;
        }
    }
    return nil;
}

- (void)tfy_deleteViewController:(NSString *)className complete:(void (^)(void))complete {
    
    if([self tfy_emptyStr:className].length <= 0) return;
    
    Class class = NSClassFromString(className);
    
    if (class == nil) return;
    
    __kindof NSMutableArray<UIViewController *> *controllers = [self.navigationController.viewControllers mutableCopy];
    
    for (UIViewController *vc in controllers) {
        
        if ([vc isKindOfClass:class]) {
            
            [controllers removeObject:vc];
            
            self.navigationController.viewControllers = [controllers copy];
            
            if(complete) {
                
                complete();
            }
            
            return;
        }
    }
}

- (void)tfy_showViewController:(NSString *)className animated:(BOOL)animated displaMode:(TFYDisplaMode)displaMode {
    
    if([self tfy_emptyStr:className].length <= 0) return;
    
    Class class = NSClassFromString(className);
    
    if (class == nil) return;
    
    UIViewController *viewController = [[class alloc]init];
    
    if(viewController == nil) return;
    
    [self showViewController:viewController animated:animated displaMode:displaMode];
}

- (void)tfy_showOnlyViewController:(NSString *)className animated:(BOOL)animated displaMode:(TFYDisplaMode)displaMode {
    
    if([self tfy_emptyStr:className].length <= 0) return;
    
    Class class = NSClassFromString(className);
    
    if (class == nil) return;
    
    weakSelf(self);
    [self tfy_deleteViewController:className complete:^{
        
        UIViewController *viewController = [[class alloc]init];
        
        if(viewController == nil) return;
        
        [weakself showViewController:viewController animated:animated displaMode:displaMode];
    }];
}

- (void)tfy_gobackViewController:(NSString *)className animated:(BOOL)animated {
    
    if([self tfy_emptyStr:className].length <= 0) return;
    
    Class class = NSClassFromString(className);
    
    if (class == nil) return;
    
    __kindof NSArray<UIViewController *> *controllers = self.navigationController.viewControllers;
   
    for (UIViewController *vc in controllers) {
        
        if ([vc isKindOfClass:class]) {
            
            if([self tfy_viewControllerDisplaMode] == TFY_DisplaModePush) {
//                [self.navigationController popToViewController:[controllers objectAtIndex:1] animated:YES];
                [self.navigationController popToViewController:vc animated:animated];
                
            }else {
                
                UIViewController *presentingController = self.presentingViewController;
                
                while (![presentingController isKindOfClass:[vc class]]) {

                    presentingController = presentingController.presentingViewController;
                }
                [presentingController dismissViewControllerAnimated:animated completion:nil];
            }
            
            return;
        }
    }
}

- (TFYDisplaMode)tfy_viewControllerDisplaMode {
    
    NSArray *viewcontrollers = self.navigationController.viewControllers;
    TFYDisplaMode displaMode = TFY_DisplaModePush;
    if (viewcontrollers.count > 1) {
        
        if ([viewcontrollers objectAtIndex:viewcontrollers.count - 1] == self) {
            //push方式
            displaMode = TFY_DisplaModePush;
        }
    }
    else {
        //present方式
        displaMode = TFY_DisplaModePresent;
    }
    
    return displaMode;
}

- (void)showViewController:(UIViewController *)viewController animated:(BOOL)animated displaMode:(TFYDisplaMode)displaMode {
    
    if(displaMode == TFY_DisplaModePush) {
        
        [self.navigationController pushViewController:viewController animated:animated];
        
    }else {
        
        [self presentViewController:viewController animated:animated completion:nil];
    }
}

-(NSString *)tfy_emptyStr:(NSString *)str {
    
    if(([str isKindOfClass:[NSNull class]]) || ([str isEqual:[NSNull null]]) || (str == nil) || (!str)) {
        
        str = @"";
    }
    return str;
}
@end
