//
//  ViewController.m
//  TFY_Model
//
//  Created by 田风有 on 2019/4/28.
//  Copyright © 2019 恋机科技. All rights reserved.
//

#import "ViewController.h"
#import "TFY_Model.h"
#import "TFY_normal_faceModel.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];

    /************** 解析jsonData **************/
    NSDictionary *jsonString = [NSDictionary tfy_objectArrayWithFilename:@"TFY_ModelObject.json"];
    
    TFY_Model * model = [TFY_Model tfy_ModelWithJson:jsonString];
    NSLog(@"解析jsonData model = %@\n\n",model);
    
    
    NSArray *arr = [TFY_normal_faceModel tfy_objectArrayWithFilename:@"normal_face.plist"];
    
    NSLog(@"arr---%@",arr);
    [arr enumerateObjectsUsingBlock:^(TFY_normal_faceModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
        NSLog(@"face_name-------%@",obj.face_name);
        
    }];
    
    
    /************** modelObject - > NSDictionary **************/
    NSDictionary * modelDict = [model tfy_Dictionary];
    NSLog(@"modelObject - > NSDictionary modelDict = %@\n\n\n",modelDict);
    
    /************** 指定路径只解析Head对象 **************/
    Head * head = [Head tfy_ModelWithJson:jsonString keyPath:@"Head"];
    NSLog(@"指定路径只解析Head对象 head = %@\n\n\n",head);
    
    /************** 指定路径只解析ResponseBody对象 **************/
    ResponseBody * body = [ResponseBody tfy_ModelWithJson:jsonString keyPath:@"ResponseBody"];
    NSLog(@"指定路径只解析ResponseBody对象 ResponseBody = %@\n\n\n",body);
    EndorseRule *hh = [EndorseRule new];
    hh.ruleNote = @"你好";
    hh.ruleNote_En = @"这是一个测试数据";
    hh.ruleRemarks = @"参数变";
    hh.ruleRemarks_En = @"中文数据";
    hh.ruleRestriction = @"奥会计师咖啡连锁店白费力气播放器分离器吧";
    
    
//    [TFY_ModelSqlite removeAllModel];
    
    
    NSArray *person = [TFY_ModelSqlite query:[EndorseRule class]];
    
    [person enumerateObjectsUsingBlock:^(EndorseRule  *_Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
         NSLog(@"TFY_ModelSqlite model = %@\n\n",obj.ruleRemarks);
    }];
    
    NSArray * persons = [self makeArrayPerson];
    [TFY_ModelSqlite inserts:persons];
    [TFY_ModelSqlite insert:model];
    NSLog(@"线程1.存储单个模型对象到数据库演示代码");
    
    NSString * path = [TFY_ModelSqlite localPathWithModel:[TFY_Model class]];
    NSLog(@"localPath = %@",path);
}


- (NSArray *)makeArrayPerson {
    NSMutableArray * personArray = [NSMutableArray array];
    for (int i = 0; i < 10; i++) {
        EndorseRule *hh = [EndorseRule new];
        hh.ruleNote = @"你好";
        hh.ruleNote_En = @"这是一个测试数据";
        hh.ruleRemarks = @"参数变";
        hh.ruleRemarks_En = @"中文数据";
        hh.ruleRestriction = @"奥会计师咖啡连锁店白费力气播放器分离器吧";
    
        [personArray addObject:hh];
    }
    return personArray;
}



@end
