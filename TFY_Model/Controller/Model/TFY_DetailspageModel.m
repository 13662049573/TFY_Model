//
//  TFY_DetailspageModel.m
//  TFY_CodeBuilder
//
//  Created by 田风有 on 2020/06/08.
//  Copyright © 2020 TFY_CodeBuilder. All rights reserved.
//

#import "TFY_DetailspageModel.h"



@implementation TFY_DetailspageModel

+ (nullable NSDictionary<NSString *, id> *)tfy_modelContainerPropertyGenericClass{
     return @{@"Head" : TFY_HeadModel.class,
@"ResponseBody" : TFY_ResponseBodyModel.class,
     };
}

@end



@implementation TFY_HeadModel


@end



@implementation TFY_ResponseBodyModel

+ (nullable NSDictionary<NSString *, id> *)tfy_modelContainerPropertyGenericClass{
     return @{@"FlightListGroupList" : TFY_FlightListGroupListModel.class,
@"PolicyRuleList" : TFY_PolicyRuleListModel.class,
     };
}

@end



@implementation TFY_FlightListGroupListModel

+ (nullable NSDictionary<NSString *, id> *)tfy_modelContainerPropertyGenericClass{
     return @{@"FlightInfoList" : TFY_FlightInfoListModel.class,
     };
}

@end



@implementation TFY_FlightInfoListModel

+ (nullable NSDictionary<NSString *, id> *)tfy_modelContainerPropertyGenericClass{
     return @{@"PunctualityRateDetail" : TFY_PunctualityRateDetailModel.class,
@"StandardPriceList" : TFY_StandardPriceListModel.class,
     };
}

@end



@implementation TFY_PunctualityRateDetailModel


@end



@implementation TFY_PolicyRuleListModel

+ (nullable NSDictionary<NSString *, id> *)tfy_modelContainerPropertyGenericClass{
     return @{@"ChangeRule" : TFY_ChangeRuleModel.class,
@"FeeInfoList" : TFY_FeeInfoListModel.class,
@"EndorseRule" : TFY_EndorseRuleModel.class,
@"RefundRule" : TFY_RefundRuleModel.class,
     };
}

@end



@implementation TFY_ChangeRuleModel


@end



@implementation TFY_FeeInfoListModel


@end



@implementation TFY_EndorseRuleModel


@end



@implementation TFY_StandardPriceListModel


@end



@implementation TFY_RefundRuleModel


@end

