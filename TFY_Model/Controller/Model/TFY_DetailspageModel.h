//
//  TFY_DetailspageModel.h
//  TFY_CodeBuilder
//
//  Created by 田风有 on 2020/06/08.
//  Copyright © 2020 TFY_CodeBuilder. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TFY_RefundRuleModel;
@class TFY_StandardPriceListModel;
@class TFY_EndorseRuleModel;
@class TFY_FeeInfoListModel;
@class TFY_ChangeRuleModel;
@class TFY_PolicyRuleListModel;
@class TFY_PunctualityRateDetailModel;
@class TFY_FlightInfoListModel;
@class TFY_FlightListGroupListModel;
@class TFY_ResponseBodyModel;
@class TFY_HeadModel;


@interface TFY_DetailspageModel : NSObject

/**
 * Head: Head 
 */
@property (nonatomic, strong) TFY_HeadModel *Head;
/**
 * ResponseBody: ResponseBody 
 */
@property (nonatomic, strong) TFY_ResponseBodyModel *ResponseBody;

@end



@interface TFY_HeadModel : NSObject

/**
 * ResponseTime: ResponseTime 
 */
@property (nonatomic, copy) NSString *ResponseTime;
/**
 * ReceiveTime: ReceiveTime 
 */
@property (nonatomic, copy) NSString *ReceiveTime;
/**
 * ResultMsg: 航班查询成功 
 */
@property (nonatomic, copy) NSString *ResultMsg;
/**
 * ResultCode: 1 
 */
@property (nonatomic, assign) NSInteger ResultCode;
/**
 * RequestTime: 2016-11-01 
 */
@property (nonatomic, copy) NSString *RequestTime;
/**
 * SessionId: SessionId 
 */
@property (nonatomic, strong) id SessionId;

///-- isNonProfit : 1
@property (nonatomic, copy) NSString *isNonProfit;
///-- name : BeJson
@property (nonatomic, copy) NSString *name;
///-- url : url
@property (nonatomic, copy) NSString *url;
///-- page : 88
@property (nonatomic, assign) NSInteger page;

@end



@interface TFY_ResponseBodyModel : NSObject

/**
 * PolicyRuleList: PolicyRuleList 
 */
@property (nonatomic, strong) NSArray <TFY_PolicyRuleListModel *> *PolicyRuleList;
/**
 * FlightListGroupList: FlightListGroupList 
 */
@property (nonatomic, strong) NSArray <TFY_FlightListGroupListModel *> *FlightListGroupList;
/**
 * IsCompleted: 1 
 */
@property (nonatomic, copy) NSString *IsCompleted;

@end



@interface TFY_FlightListGroupListModel : NSObject

/**
 * FlightInfoList: FlightInfoList 
 */
@property (nonatomic, strong) NSArray <TFY_FlightInfoListModel *> *FlightInfoList;
/**
 * OrigDestSeqID: 1 
 */
@property (nonatomic, assign) NSInteger OrigDestSeqID;

@end



@interface TFY_FlightInfoListModel : NSObject

/**
 * ArrvCityCode: BJS 
 */
@property (nonatomic, copy) NSString *ArrvCityCode;
/**
 * PunctualityRateDetail: PunctualityRateDetail 
 */
@property (nonatomic, strong) TFY_PunctualityRateDetailModel *PunctualityRateDetail;
/**
 * DeptAirportName: 浦东 
 */
@property (nonatomic, copy) NSString *DeptAirportName;
/**
 * DeptAirportCode: PVG 
 */
@property (nonatomic, copy) NSString *DeptAirportCode;
/**
 * DeptCityName: 上海 
 */
@property (nonatomic, copy) NSString *DeptCityName;
/**
 * DeptDateTime: DeptDateTime 
 */
@property (nonatomic, copy) NSString *DeptDateTime;
/**
 * NextDays: 0 
 */
@property (nonatomic, assign) NSInteger NextDays;
/**
 * IsFlyMan: 0 
 */
@property (nonatomic, copy) NSString *IsFlyMan;
/**
 * StandardPriceList: StandardPriceList 
 */
@property (nonatomic, strong) NSArray <TFY_StandardPriceListModel *> *StandardPriceList;

@end



@interface TFY_PunctualityRateDetailModel : NSObject

/**
 * Cancel: 0 
 */
@property (nonatomic, assign) NSInteger Cancel;
/**
 * Delay60To90: 0 
 */
@property (nonatomic, assign) NSInteger Delay60To90;
/**
 * OnTime: 71.92 
 */
@property (nonatomic, assign) CGFloat OnTime;
/**
 * Delay30To60: 0 
 */
@property (nonatomic, assign) NSInteger Delay30To60;
/**
 * DelayOver90: 0 
 */
@property (nonatomic, assign) NSInteger DelayOver90;

@end



@interface TFY_PolicyRuleListModel : NSObject

/**
 * TravelerCategory: Child 
 */
@property (nonatomic, copy) NSString *TravelerCategory;
/**
 * CanUpgrade: 0 
 */
@property (nonatomic, copy) NSString *CanUpgrade;
/**
 * Index: 43 
 */
@property (nonatomic, assign) NSInteger Index;
/**
 * ChangeRule: ChangeRule 
 */
@property (nonatomic, strong) TFY_ChangeRuleModel *ChangeRule;
/**
 * RefundFeeFormulaID: 260 
 */
@property (nonatomic, copy) NSString *RefundFeeFormulaID;
/**
 * IsPackageProduct: false 
 */
@property (nonatomic, copy) NSString *IsPackageProduct;
/**
 * FeeInfoList: FeeInfoList 
 */
@property (nonatomic, strong) NSArray <TFY_FeeInfoListModel *> *FeeInfoList;
/**
 * EndorseRule: EndorseRule 
 */
@property (nonatomic, strong) TFY_EndorseRuleModel *EndorseRule;
/**
 * RefundRule: RefundRule 
 */
@property (nonatomic, strong) TFY_RefundRuleModel *RefundRule;
/**
 * TicketType: NA 
 */
@property (nonatomic, copy) NSString *TicketType;

@end



@interface TFY_ChangeRuleModel : NSObject

/**
 * RuleRestriction: H 
 */
@property (nonatomic, copy) NSString *RuleRestriction;
/**
 * RuleNote: RuleNote 
 */
@property (nonatomic, copy) NSString *RuleNote;
/**
 * RuleRemarks: RuleRemarks 
 */
@property (nonatomic, copy) NSString *RuleRemarks;
/**
 * RuleRemarks_En: RuleRemarks_En 
 */
@property (nonatomic, copy) NSString *RuleRemarks_En;
/**
 * RuleNote_En: RuleNote_En 
 */
@property (nonatomic, copy) NSString *RuleNote_En;

@end



@interface TFY_FeeInfoListModel : NSObject

/**
 * FeeType: TAX 
 */
@property (nonatomic, copy) NSString *FeeType;
/**
 * Fee: 0 
 */
@property (nonatomic, assign) NSInteger Fee;

@end



@interface TFY_EndorseRuleModel : NSObject

/**
 * RuleRestriction: T 
 */
@property (nonatomic, copy) NSString *RuleRestriction;
/**
 * RuleNote: 不得签转。 
 */
@property (nonatomic, copy) NSString *RuleNote;
/**
 * RuleRemarks: RuleRemarks 
 */
@property (nonatomic, copy) NSString *RuleRemarks;
/**
 * RuleRemarks_En: RuleRemarks_En 
 */
@property (nonatomic, copy) NSString *RuleRemarks_En;
/**
 * RuleNote_En: RuleNote_En 
 */
@property (nonatomic, copy) NSString *RuleNote_En;

@end



@interface TFY_StandardPriceListModel : NSObject

/**
 * Price: 1240 
 */
@property (nonatomic, assign) NSInteger Price;
/**
 * CabinClass: 经济舱 
 */
@property (nonatomic, copy) NSString *CabinClass;

@end



@interface TFY_RefundRuleModel : NSObject

/**
 * RuleRestriction: H 
 */
@property (nonatomic, copy) NSString *RuleRestriction;
/**
 * RuleNote: RuleNote 
 */
@property (nonatomic, copy) NSString *RuleNote;
/**
 * RuleRemarks: RuleRemarks 
 */
@property (nonatomic, copy) NSString *RuleRemarks;
/**
 * RuleRemarks_En: RuleRemarks_En 
 */
@property (nonatomic, copy) NSString *RuleRemarks_En;
/**
 * RuleNote_En: RuleNote_En 
 */
@property (nonatomic, copy) NSString *RuleNote_En;

@end

