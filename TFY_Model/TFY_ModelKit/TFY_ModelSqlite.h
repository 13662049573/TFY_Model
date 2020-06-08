//
//  TFY_ModelSqlite.h
//  TFY_Model
//
//  Created by 田风有 on 2019/5/30.
//  Copyright © 2019 恋机科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

#pragma ******************************************  数据库模型处理类   ******************************************


@protocol TFY_ModelSqlite <NSObject>
@optional
/**
 *  自定义数据存储路径
 */
+ (NSString *)tfy_SqlitePath;
/**
 *  自定义模型类数据库版本号
 */
+ (NSString *)tfy_SqliteVersion;
/**
 *  自定义数据库加密密码 手动引入pod 'TFY_ModelKit/SQLCipher'
 */
+ (NSString *)tfy_SqlitePasswordKey;
/**
 *  自定义数据表主键名称
 */
+ (NSString *)tfy_SqliteMainkey;
/**
 *  忽略属性集合
 */
+ (NSArray *)tfy_IgnorePropertys;
/**
 *  引入使用其他方式创建的数据库存储路径来使用Sqlite进行操作其他方式创建的数据库
 */
+ (NSString *)tfy_OtherSqlitePath;
/**
 *  指定自定义表名 在指定引入其他方式创建的数据库时，这个时候如果表名不是模型类名需要实现该方法指定表名称
 */
+ (NSString *)tfy_TableName;

@end


@interface TFY_ModelSqlite : NSObject
/**
 *  存储模型数组到本地(事务方式) 模型数组对象(model_array 里对象类型要一致)
 */
+ (BOOL)inserts:(NSArray *)model_array;
/**
 *  存储模型到本地model_object 模型对象
 */
+ (BOOL)insert:(id)model_object;
/**
 *  获取模型类表总条数model_class 模型类 总条数
 */
+ (NSUInteger)count:(Class)model_class;
/**
 * 查询本地模型对象model_class 模型类 查询模型对象数组
 */
+ (NSArray *)query:(Class)model_class;
/**
 * 查询本地模型对象model_class 模型类 where 查询条件(查询语法和SQL where 查询语法一样，where为空则查询所有) 查询模型对象数组
 */
+ (NSArray *)query:(Class)model_class where:(NSString *)where;
/**
 * 查询本地模型对象 order 排序条件(排序语法和SQL order 查询语法一样，order为空则不排序)
 */
+ (NSArray *)query:(Class)model_class order:(NSString *)order;
/**
 *  查询本地模型对象 limit 限制条件(限制语法和SQL limit 查询语法一样，limit为空则不限制查询) [TFY_ModelSqlite query:[Person class] limit:@"8"];
 */
+ (NSArray *)query:(Class)model_class limit:(NSString *)limit;
/**
 *  [TFY_ModelSqlite query:[Person class] where:@"age < 30" order:@"by age desc/asc"]; 
 */
+ (NSArray *)query:(Class)model_class where:(NSString *)where order:(NSString *)order;
/**
 * [TFY_ModelSqlite query:[Person class] where:@"age <= 30" limit:@"8 offset 8"];
 */
+ (NSArray *)query:(Class)model_class where:(NSString *)where limit:(NSString *)limit;
/**
 *  [TFY_ModelSqlite query:[Person class] order:@"by age desc/asc" limit:@"8 offset 8"];
 */
+ (NSArray *)query:(Class)model_class order:(NSString *)order limit:(NSString *)limit;
/**
 * [TFY_ModelSqlite query:[Person class] where:@"age <= 30" order:@"by age desc/asc" limit:@"8"];
 */
+ (NSArray *)query:(Class)model_class where:(NSString *)where order:(NSString *)order limit:(NSString *)limit;
/**
 * 自定义sql查询 [TFY_ModelSqlite query:Model.self sql:@"select cc.* from ( select tt.*,(select count(*)+1 from Chapter where chapter_id = tt.chapter_id and updateTime< updateTime ) as group_id from Chapter tt) cc where cc.group_id<=7 order by updateTime desc"];
 */
+ (NSArray *)query:(Class)model_class sql:(NSString *)sql;
/**
 *  利用sqlite 函数进行查询 [TFY_ModelSqlite query:[Person class] sqliteFunc:@"max(age)"];
                         [TFY_ModelSqlite query:[Person class] sqliteFunc:@"count(*)"];
 */
+ (id)query:(Class)model_class func:(NSString *)func;
/**
 *  利用sqlite 函数进行查询 [TFY_ModelSqlite query:[Person class] sqliteFunc:@"max(age)" condition:@"where name = '北京'"];
                         [TFY_ModelSqlite query:[Person class] sqliteFunc:@"count(*)" condition:@"where name = '北京'"];
 */
+ (id)query:(Class)model_class func:(NSString *)func condition:(NSString *)condition;
/**
 * 更新本地模型对象
 */
+ (BOOL)update:(id)model_object where:(NSString *)where;
/**
 *  更新数据表字段 [TFY_ModelSqlite update:Person.self value:@"name = 'tfy', age = 100" where:@"age > 25"];
 */
+ (BOOL)update:(Class)model_class value:(NSString *)value where:(NSString *)where;
/**
 * 清空本地模型对象
 */
+ (BOOL)clear:(Class)model_class;
/**
 * 删除本地模型对象
 */
+ (BOOL)deletes:(Class)model_class where:(NSString *)where;
/**
 *  清空所有本地模型数据库
 */
+ (void)removeAllModel;
/**
 *  清空指定本地模型数据库
 */
+ (void)removeModel:(Class)model_class;
/**
 *  返回本地模型数据库路径
 */
+ (NSString *)localPathWithModel:(Class)model_class;
/**
 *  返回本地模型数据库版本号
 */
+ (NSString *)versionWithModel:(Class)model_class;

@end


#pragma ******************************************  字典数据模型转化处理类   ******************************************

typedef NS_OPTIONS(NSUInteger, TFY_EncodingType) {
    TFY_EncodingTypeMask       = 0xFF, ///< 类型值掩码
    TFY_EncodingTypeUnknown    = 0, ///< 未知的
    TFY_EncodingTypeVoid       = 1, ///< void
    TFY_EncodingTypeBool       = 2, ///< bool
    TFY_EncodingTypeInt8       = 3, ///< char / BOOL
    TFY_EncodingTypeUInt8      = 4, ///< unsigned char
    TFY_EncodingTypeInt16      = 5, ///< short
    TFY_EncodingTypeUInt16     = 6, ///< unsigned short
    TFY_EncodingTypeInt32      = 7, ///< int
    TFY_EncodingTypeUInt32     = 8, ///< unsigned int
    TFY_EncodingTypeInt64      = 9, ///< long long
    TFY_EncodingTypeUInt64     = 10, ///< unsigned long long
    TFY_EncodingTypeFloat      = 11, ///< float
    TFY_EncodingTypeDouble     = 12, ///< double
    TFY_EncodingTypeLongDouble = 13, ///< long double
    TFY_EncodingTypeObject     = 14, ///< id
    TFY_EncodingTypeClass      = 15, ///< Class
    TFY_EncodingTypeSEL        = 16, ///< SEL
    TFY_EncodingTypeBlock      = 17, ///< block
    TFY_EncodingTypePointer    = 18, ///< void*
    TFY_EncodingTypeStruct     = 19, ///< struct
    TFY_EncodingTypeUnion      = 20, ///< union
    TFY_EncodingTypeCString    = 21, ///< char*
    TFY_EncodingTypeCArray     = 22, ///< char[10] (for example)
    
    TFY_EncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    TFY_EncodingTypeQualifierConst  = 1 << 8,  ///< const
    TFY_EncodingTypeQualifierIn     = 1 << 9,  ///< in
    TFY_EncodingTypeQualifierInout  = 1 << 10, ///< inout
    TFY_EncodingTypeQualifierOut    = 1 << 11, ///< out
    TFY_EncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    TFY_EncodingTypeQualifierByref  = 1 << 13, ///< byref
    TFY_EncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    TFY_EncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    TFY_EncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    TFY_EncodingTypePropertyCopy         = 1 << 17, ///< copy
    TFY_EncodingTypePropertyRetain       = 1 << 18, ///< retain
    TFY_EncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    TFY_EncodingTypePropertyWeak         = 1 << 20, ///< weak
    TFY_EncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    TFY_EncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    TFY_EncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

/**
 从类型编码字符串中获取类型。
 */
TFY_EncodingType TFY_EncodingGetType(const char *typeEncoding);


/**
 实例变量的信息。
 */
@interface TFY_ClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar不透明的结构
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar是名字
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar的偏移
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar类型编码
@property (nonatomic, assign, readonly) TFY_EncodingType type;    ///< Ivar的类型

/**
 创建并返回一个ivar信息对象。
 */
- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 方法信息。
 */
@interface TFY_ClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< 不透明的结构方法
@property (nonatomic, strong, readonly) NSString *name;                 ///< 方法名称
@property (nonatomic, assign, readonly) SEL sel;                        ///< 方法的选择
@property (nonatomic, assign, readonly) IMP imp;                        ///< 方法的实现
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< 方法的参数和返回类型
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< 返回值的类型
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< 参数类型的数组

/**
 创建并返回一个方法信息对象。
 */
- (instancetype)initWithMethod:(Method)method;
@end

/**
 属性信息。
 */
@interface TFY_ClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< 财产不透明的结构
@property (nonatomic, strong, readonly) NSString *name;           ///< 属性的名称
@property (nonatomic, assign, readonly) TFY_EncodingType type;      ///< 属性的类型
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< 属性的编码值
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< 属性为ivar名称
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< 可能是零
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///<可能是零
@property (nonatomic, assign, readonly) SEL getter;
@property (nonatomic, assign, readonly) SEL setter;

/**
 创建并返回一个属性信息对象。
 */
- (instancetype)initWithProperty:(objc_property_t)property;
@end

/**
 一个类的类信息。
 */
@interface TFY_ClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< 类对象
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< 超类对象
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< 类的元类对象
@property (nonatomic, readonly) BOOL isMeta; ///< 这个类是否是元类
@property (nonatomic, strong, readonly) NSString *name; ///< 类名
@property (nullable, nonatomic, strong, readonly) TFY_ClassInfo *superClassInfo; ///< 超类的类信息
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, TFY_ClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, TFY_ClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, TFY_ClassPropertyInfo *> *propertyInfos; ///< properties

/**
 如果类被更改(例如:您向该类添加一个方法
 'class_addMethod()')，您应该调用这个方法来刷新类信息缓存。
 在调用这个方法后，' needUpdate '将返回' YES '，你应该调用
 'classInfoWithClass'或'classInfoWithClassName'来获取更新的类信息。
 */
- (void)setNeedUpdate;

/**
 如果这个方法返回' YES '，你应该停止使用这个实例并调用
 ' classInfoWithClass '或' classInfoWithClassName '来获取更新的类信息。
 这个类信息是否需要更新。
 */
- (BOOL)needUpdate;

/**
 获取指定类的类信息。

 这个方法将缓存类信息和超类信息
 在第一次进入类。这个方法是线程安全的。

 @返回一个类信息，如果发生错误，返回nil。
 */
+ (nullable instancetype)classInfoWithClass:(Class)cls;

/**
 获取指定类的类信息。

 这个方法将缓存类信息和超类信息
 在第一次进入类。这个方法是线程安全的。
 一个类名。
 @返回一个类信息，如果发生错误，返回nil。
 */
+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
