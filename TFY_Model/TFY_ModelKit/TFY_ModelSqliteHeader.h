//
//  TFY_ModelSqliteHeader.h
//  TFY_Model
//
//  Created by 田风有 on 2019/5/30.
//  Copyright © 2019 恋机科技. All rights reserved.
//  最新版本号: 2.6.8

#ifndef TFY_ModelSqliteHeader_h
#define TFY_ModelSqliteHeader_h



#endif /* TFY_ModelSqliteHeader_h */

#import <Foundation/Foundation.h>

#if __has_include(<TFY_ModelKit/TFY_ModelSqliteHeader.h>)

FOUNDATION_EXPORT double TFY_ModelVersionNumber;
FOUNDATION_EXPORT const unsigned char TFY_ModelVersionString[];

#import <TFY_ModelKit/NSObject+TFY_Model.h>
#import <TFY_ModelKit/TFY_ModelSqlite.h>

#else

#import "NSObject+TFY_Model.h"
#import "TFY_ModelSqlite.h"

#endif
