//
//  ViewController.m
//  TFY_Model
//
//  Created by 田风有 on 2019/4/28.
//  Copyright © 2019 恋机科技. All rights reserved.
//

#import "ViewController.h"
#import "TFY_ModelSqliteHeader.h"
#import "TFY_DetailspageModel.h"
#import "TFY_normal_faceModel.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"模型转数据";
    
    
    TFY_DetailspageModel *model = [TFY_DetailspageModel tfy_ModelobjectArrayWithFilename:@"TFY_ModelObject.json"];
    
    NSLog(@"---%@----",model.Head.ResultMsg);
    
    [model.ResponseBody.FlightListGroupList enumerateObjectsUsingBlock:^(TFY_FlightListGroupListModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
       
        NSLog(@"%ld",(long)obj.OrigDestSeqID);
        
        [obj.FlightInfoList enumerateObjectsUsingBlock:^(TFY_FlightInfoListModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
           
            NSLog(@"%@---%@",obj.DeptCityName,obj.IsFlyMan);
            
            [obj.StandardPriceList enumerateObjectsUsingBlock:^(TFY_StandardPriceListModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                
                NSLog(@"%@",obj.CabinClass);
            }];
            
        }];
        
    }];
    
    
    NSArray<TFY_normal_faceModel *> *arr = [TFY_normal_faceModel tfy_ModelobjectArrayWithFilename:@"normal_face.plist"];
    
    [arr enumerateObjectsUsingBlock:^(TFY_normal_faceModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
       
        NSLog(@"------%@-",obj.face_name);
    }];
   
}


@end
