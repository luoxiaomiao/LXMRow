//
//  LXMCollectionSection.h
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LXMCollectionRow.h"

NS_ASSUME_NONNULL_BEGIN

/// UICollectionView 使用的脚手架
@interface LXMCollectionSection : NSObject

/// 总行数数据
@property (nonatomic, strong, readonly) NSMutableArray<LXMCollectionRow *> *rows;
/// 组标识
@property (nonatomic, copy, nullable) NSString *secId;
/// 可配置组参数
@property (nonatomic, strong, nullable) id userInfo;

/// 初始化方法
+ (instancetype)section;

/// 添加方法
/// @param row row
- (void)addRow:(LXMCollectionRow *)row;

/// 添加方法
/// /// @param rows rows
- (void)addRows:(NSArray<LXMCollectionRow *> *)rows;

@end

NS_ASSUME_NONNULL_END
