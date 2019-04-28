//
//  TFY_Model.h
//  TFY_Model
//
//  Created by 田风有 on 2019/4/28.
//  Copyright © 2019 恋机科技. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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


NS_ASSUME_NONNULL_END
