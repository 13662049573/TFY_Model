//
//  NSObject+TFY_Model.h
//  TFY_CHESHI  版本：2.0.0
//
//  Created by 田风有 on 2019/4/25.
//  Copyright © 2019 田风有. All rights reserved.
//  下载地址：https://github.com/13662049573/TFY_Model.git

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TFY_ModelKeyValue <NSObject>
@optional
/**
 *  + (NSDictionary *)tfy_modelCustomPropertyMapper {
     return @{@"name"  : @"n",
              @"page"  : @"p",
              @"desc"  : @"ext.desc",
              @"bookID": @[@"id", @"ID", @"book_id"]};
 }
 */
+ (nullable NSDictionary<NSString *, id> *)tfy_modelCustomPropertyMapper;
/**
 *  + (NSDictionary *)tfy_modelContainerPropertyGenericClass {
     return @{@"shadows" : [TFY_Shadow class],
              @"borders" : TFY_Border.class,
              @"attachments" : @"TFY_Attachment" };
 }
 */
+ (nullable NSDictionary<NSString *, id> *)tfy_modelContainerPropertyGenericClass;

/**
 *  + (Class)tfy_modelCustomClassForDictionary:(NSDictionary*)dictionary {
            if (dictionary[@"radius"] != nil) {
                return [TFY_Circle class];
            } else if (dictionary[@"width"] != nil) {
                return [TFY_Rectangle class];
            } else if (dictionary[@"y2"] != nil) {
                return [TFY_Line class];
            } else {
                return [self class];
            }
        }
 */
+ (nullable Class)tfy_modelCustomClassForDictionary:(NSDictionary *)dictionary;

/**
 在模型转换过程中，黑名单中的所有属性都将被忽略。返回nil来忽略这个特性。返回属性名称的数组。
 */
+ (nullable NSArray<NSString *> *)tfy_modelPropertyBlacklist;

/**
 如果一个属性不在白名单中，它将在模型转换过程中被忽略。返回nil来忽略这个特性。返回属性名称的数组。
 */
+ (nullable NSArray<NSString *> *)tfy_modelPropertyWhitelist;

/**
 这个方法的行为类似于' - (BOOL)tfy_modelCustomTransformFromDictionary:(NSDictionary *)dic; '，
 但是在模型转换之前被调用。返回修改后的字典，或nil来忽略这个模型。
 */
- (NSDictionary *)tfy_modelCustomWillTransformFromDictionary:(NSDictionary *)dic;

/**
 如果默认的json-to-model转换不适合您的模型对象，请实现此方法做附加处理。还可以使用此方法验证 返回YES，或者忽略这个模型返回NO。
 */
- (BOOL)tfy_modelCustomTransformFromDictionary:(NSDictionary *)dic;

/**
 如果默认的模型到json转换不适合您的模型类，请实现
 此方法做附加处理。还可以使用此方法验证
 json字典。

 如果模型实现了这个方法，它将在末尾被调用
 “-modelToJSONObject”和“-modelToJSONString”。
 如果该方法返回NO，转换过程将忽略这个json字典。

 @param dic json字典。

 如果模型有效，@return返回YES，或者忽略这个模型返回NO。
 */
- (BOOL)tfy_modelCustomTransformToDictionary:(NSMutableDictionary *)dic;

@end

@interface NSObject (TFY_Model) <TFY_ModelKeyValue>

/**
 *  字典转模型数据
 */
+ (nullable instancetype)tfy_modelWithJSON:(id)json;
/**
 *  filename 文件名(仅限于mainBundle中的文件) 如果末尾json格式返回字典
 */
+ (id)tfy_ModelobjectArrayWithFilename:(NSString *)filename;
/**
 * 从键-值字典创建并返回接收方的新实例。
 */
+ (nullable instancetype)tfy_modelWithDictionary:(NSDictionary *)dictionary;

/**
 * piit 转数组
 */
+(NSArray *)tfy_pathForResource:(NSString *)filename;

/**
 * 使用json对象设置接收方的属性。 任何无效的json数据将被忽略。一个NSDictionary NSString或NSData的json对象，映射到接收器的属性。
 */
- (BOOL)tfy_modelSetWithJSON:(id)json;
/**
 *用键-值字典设置接收者的属性。映射到接收者属性的键-值字典。字典中任何无效的键-值对都将被忽略。
 */
- (BOOL)tfy_modelSetWithDictionary:(NSDictionary *)dic;

/**
 * 从接收方的属性生成json对象。一个json对象在' NSDictionary '或' NSArray '，或nil，如果发生错误。更多信息请参见[NSJSONSerialization isValidJSONObject]。
 */
- (nullable id)tfy_modelToJSONObject;

/**
 * 从接收方的属性生成json字符串的数据。
 */
- (nullable NSData *)tfy_modelToJSONData;

/**
 *  从接收方的属性生成一个json字符串。 返回 一个json字符串，如果出现错误，返回nil。
 */
- (nullable NSString *)tfy_modelToJSONString;

/**
 * 复制带有接收者属性的实例。
 */
- (nullable id)tfy_modelCopy;

/**
 将接收方的属性编码为编码器。
 */
- (void)tfy_modelEncodeWithCoder:(NSCoder *)aCoder;

/**
 从解码器解码接收方的属性。一个归档对象。
 */
- (id)tfy_modelInitWithCoder:(NSCoder *)aDecoder;

/**
 获取带有接收方属性的哈希码。哈希代码。
 */
- (NSUInteger)tfy_modelHash;

/**
 基于属性，比较接收者与另一个对象是否相等。' YES '如果接收者等于对象，否则' NO '。
 */
- (BOOL)tfy_modelIsEqual:(id)model;

/**
 基于属性用于调试的描述方法。描述接收方内容的字符串。
 */
- (NSString *)tfy_modelDescription;

@end

/**
 为NSArray提供一些数据模型方法。
 */
@interface NSArray (TFY_Model)

/**
 从json数组创建并返回数组。这个方法是线程安全的。在数组中cls实例的类。一个包含NSArray NSString或NSData的json数组。@返回一个数组，如果发生错误，返回nil。
 */
+ (nullable NSArray *)tfy_modelArrayWithClass:(Class)cls json:(id)json;

@end

/**
 为NSDictionary提供一些数据模型方法。
 */
@interface NSDictionary (TFY_Model)

/**
 从json创建并返回一个字典。这个方法是线程安全的。在字典中cls值实例的类。返回一个字典，如果出现错误，返回nil。
 */
+ (nullable NSDictionary *)tfy_modelDictionaryWithClass:(Class)cls json:(id)json;

@end


NS_ASSUME_NONNULL_END
