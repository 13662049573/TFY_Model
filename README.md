# TFY_Model


使用方法

@interface Head :NSObject
@property (nonatomic , copy) NSString              * responseTime;
@property (nonatomic , copy) NSString              * receiveTime;
@property (nonatomic , copy) NSString              * resultMsg;
@property (nonatomic , assign) NSInteger              resultCode;
@property (nonatomic , copy) NSString              * requestTime;
@property (nonatomic , copy) NSString              * sessionId;

@end

@interface ChangeRule :NSObject
@property (nonatomic , copy) NSString              * ruleRestriction;
@property (nonatomic , copy) NSString              * ruleNote;
@property (nonatomic , copy) NSString              * ruleRemarks;
@property (nonatomic , copy) NSString              * ruleRemarks_En;
@property (nonatomic , copy) NSString              * ruleNote_En;

@end

@interface FeeInfoList :NSObject
@property (nonatomic , copy) NSString              * feeType;
@property (nonatomic , assign) NSInteger              fee;

@end

@interface EndorseRule :NSObject
@property (nonatomic , copy) NSString              * ruleRestriction;
@property (nonatomic , copy) NSString              * ruleNote;
@property (nonatomic , copy) NSString              * ruleRemarks;
@property (nonatomic , copy) NSString              * ruleRemarks_En;
@property (nonatomic , copy) NSString              * ruleNote_En;

@end

@interface RefundRule :NSObject
@property (nonatomic , copy) NSString              * ruleRestriction;
@property (nonatomic , copy) NSString              * ruleNote;
@property (nonatomic , copy) NSString              * ruleRemarks;
@property (nonatomic , copy) NSString              * ruleRemarks_En;
@property (nonatomic , copy) NSString              * ruleNote_En;

@end

@interface PolicyRuleList :NSObject
@property (nonatomic , copy) NSString              * travelerCategory;
@property (nonatomic , assign) BOOL              canUpgrade;
@property (nonatomic , assign) NSInteger              index;
@property (nonatomic , strong) ChangeRule              * changeRule;
@property (nonatomic , copy) NSString              * refundFeeFormulaID;
@property (nonatomic , copy) NSString              * isPackageProduct;
@property (nonatomic , copy) NSArray<FeeInfoList *>              * feeInfoList;
@property (nonatomic , strong) EndorseRule              * endorseRule;
@property (nonatomic , strong) RefundRule              * refundRule;
@property (nonatomic , copy) NSString              * ticketType;

@end

@interface PunctualityRateDetail :NSObject
@property (nonatomic , assign) NSInteger              cancel;
@property (nonatomic , assign) NSInteger              delay60To90;
@property (nonatomic , assign) CGFloat              onTime;
@property (nonatomic , assign) NSInteger              delay30To60;
@property (nonatomic , assign) NSInteger              delayOver90;

@end

@interface StandardPriceList :NSObject
@property (nonatomic , assign) NSInteger              price;
@property (nonatomic , copy) NSString              * cabinClass;

@end

@interface FlightInfoList :NSObject
@property (nonatomic , copy) NSString              * arrvCityCode;
@property (nonatomic , strong) PunctualityRateDetail              * punctualityRateDetail;
@property (nonatomic , copy) NSString              * deptAirportName;
@property (nonatomic , copy) NSString              * deptAirportCode;
@property (nonatomic , copy) NSString              * deptCityName;
@property (nonatomic , copy) NSString              * deptDateTime;
@property (nonatomic , assign) NSInteger              nextDays;
@property (nonatomic , assign) BOOL              isFlyMan;
@property (nonatomic , copy) NSArray<StandardPriceList *>              * standardPriceList;

@end

@interface FlightListGroupList :NSObject
@property (nonatomic , copy) NSArray<FlightInfoList *>              * flightInfoList;
@property (nonatomic , assign) NSInteger              origDestSeqID;

@end

@interface ResponseBody :NSObject
@property (nonatomic , copy) NSArray<PolicyRuleList *>              * policyRuleList;
@property (nonatomic , copy) NSArray<FlightListGroupList *>              * flightListGroupList;
@property (nonatomic , assign) BOOL              isCompleted;

@end

@interface TFY_Model :NSObject
@property (nonatomic , strong) Head              * head;
@property (nonatomic , strong) ResponseBody              * responseBody;

@end

@implementation Head

@end
@implementation ChangeRule

@end
@implementation FeeInfoList

@end
@implementation EndorseRule

@end
@implementation RefundRule

@end
@implementation PolicyRuleList
+(NSDictionary <NSString *, Class> *)tfy_ModelReplacePropertyClassMapper{
    return @{@"changeRule":[ChangeRule class],
             @"feeInfoList":[FeeInfoList class],
             @"endorseRule":[EndorseRule class],
             @"refundRule":[RefundRule class]
             };
}
@end
@implementation PunctualityRateDetail

@end
@implementation StandardPriceList

@end
@implementation FlightInfoList
+(NSDictionary <NSString *, Class> *)tfy_ModelReplacePropertyClassMapper{
    return @{@"punctualityRateDetail":[PunctualityRateDetail class],
             @"standardPriceList":[StandardPriceList class],
             
             };
}
@end
@implementation FlightListGroupList
+(NSDictionary <NSString *, Class> *)tfy_ModelReplacePropertyClassMapper{
    return @{@"flightInfoList":[FlightInfoList class]
             };
}
@end
@implementation ResponseBody
+(NSDictionary <NSString *, Class> *)tfy_ModelReplacePropertyClassMapper{
    return @{@"flightListGroupList":[FlightListGroupList class],
             @"policyRuleList":[PolicyRuleList class]
             };
}
@end
@implementation TFY_Model
+(NSDictionary <NSString *, Class> *)tfy_ModelReplacePropertyClassMapper{
    return @{@"responseBody":[ResponseBody class],
             @"head":[Head class]
             };
}
@end



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