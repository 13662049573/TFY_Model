//
//  ViewController.m
//  TFY_Model
//
//  Created by 田风有 on 2019/4/28.
//  Copyright © 2019 恋机科技. All rights reserved.
//

#import "ViewController.h"
#import "TFY_Model.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    /// 从文件ModelObject读取json对象
    NSString * jsonString = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"TFY_ModelObject" ofType:@"json"] encoding:NSUTF8StringEncoding error:nil];
    
    NSData * jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    /************** 解析jsonData **************/
    TFY_Model * model = [TFY_Model tfy_ModelWithJson:jsonData];
    NSLog(@"解析jsonData model = %@\n\n",model);
    
    /************** json -> modelObject **************/
    model = [TFY_Model tfy_ModelWithJson:jsonString];
    NSLog(@"json -> modelObject model = %@\n\n\n",model);
    
    /************** modelObject -> json **************/
    NSString * modelString = [model tfy_Json];
    NSLog(@"modelObject -> json modelString = %@\n\n\n",modelString);
    
    /************** modelObject - > NSDictionary **************/
    NSDictionary * modelDict = [model tfy_Dictionary];
    NSLog(@"modelObject - > NSDictionary modelDict = %@\n\n\n",modelDict);
    
    /************** 指定路径只解析Head对象 **************/
    Head * head = [Head tfy_ModelWithJson:jsonString keyPath:@"Head"];
    NSLog(@"指定路径只解析Head对象 head = %@\n\n\n",head);
    
    /************** 指定路径只解析ResponseBody对象 **************/
    ResponseBody * body = [ResponseBody tfy_ModelWithJson:jsonString keyPath:@"ResponseBody"];
    NSLog(@"指定路径只解析ResponseBody对象 ResponseBody = %@\n\n\n",body);
    
}


@end
