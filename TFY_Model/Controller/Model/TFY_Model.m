//
//  TFY_Model.m
//  TFY_Model
//
//  Created by 田风有 on 2019/4/28.
//  Copyright © 2019 恋机科技. All rights reserved.
//

#import "TFY_Model.h"

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


