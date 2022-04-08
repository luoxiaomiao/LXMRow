//
//  LXMCollectionRow.h
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// UICollectionView 使用的脚手架
@interface LXMCollectionRow : NSObject
/// 创建 Cell
@property (nonatomic, copy, nullable) UICollectionViewCell * (^creatCell)(UICollectionView *collectionView, NSIndexPath *indexPath);
/// Cell 点击
@property (nonatomic, copy, nullable) void (^didSelectCell)(NSIndexPath *indexPath);
/// Cell 即将绘制
@property (nonatomic, copy, nullable) void (^willDisplayCell)(__kindof UICollectionViewCell *cell, NSIndexPath *indexPath);
/// Cell 绘制完成
@property (nonatomic, copy, nullable) void (^didEndDisplayCell)(__kindof UICollectionViewCell *cell, NSIndexPath *indexPath);
/// Cell 尺寸
@property (nonatomic, assign) CGSize size;
/// 获取尺寸
@property (nonatomic, copy, nullable) CGSize (^fetchSize)(NSIndexPath *indexPath);
/// 标识
@property (nonatomic, copy, nullable) NSString *rowId;
/// 可配置参数
@property (nonatomic, strong, nullable) id userInfo;

/// 初始化方法
/// @param creatCell 创建 Cell 的 Block
+ (instancetype)creatCell:(UICollectionViewCell * (^)(UICollectionView *collectionView, NSIndexPath *indexPath))creatCell;

/// 获取高度
/// @param indexPath indexPath
- (CGSize)getSizeForIndexPath:(NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END
