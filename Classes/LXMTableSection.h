//
//  LXMTableSection.h
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LXMTableRow.h"

NS_ASSUME_NONNULL_BEGIN

/// UITableView 使用的脚手架
@interface LXMTableSection : NSObject
/// 总行数数据
@property (nonatomic, strong, readonly) NSMutableArray<LXMTableRow *> *rows;
/// 创建头视图
@property (nonatomic, copy, nullable) UITableViewHeaderFooterView * (^creatHeader)(void);
/// 头视图高度
@property (nonatomic, assign) CGFloat headerHeight;
/// 创建尾视图
@property (nonatomic, copy, nullable) UITableViewHeaderFooterView * (^creatFooter)(void);
/// 尾视图高度
@property (nonatomic, assign) CGFloat footerHeight;
/// 组标识
@property (nonatomic, copy, nullable) NSString *secId;
/// 可配置组参数
@property (nonatomic, strong, nullable) id userInfo;

/// 初始化方法
+ (instancetype)section;

/// 添加方法
/// @param row row
- (void)addRow:(LXMTableRow *)row;

/// 添加方法
/// /// @param rows rows
- (void)addRows:(NSArray<LXMTableRow *> *)rows;

@end

NS_ASSUME_NONNULL_END
