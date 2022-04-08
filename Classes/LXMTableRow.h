//
//  LXMTableRow.h
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// UITableView 使用的脚手架
@interface LXMTableRow : NSObject
/// 创建 Cell
@property (nonatomic, copy, nullable) UITableViewCell * (^creatCell)(UITableView *tableView, NSIndexPath *indexPath);
/// Cell 点击
@property (nonatomic, copy, nullable) void (^didSelectCell)(NSIndexPath *indexPath);
/// Cell 即将绘制
@property (nonatomic, copy, nullable) void (^willDisplayCell)(__kindof UITableViewCell *cell, NSIndexPath *indexPath);
/// Cell 绘制完成
@property (nonatomic, copy, nullable) void (^didEndDisplayCell)(__kindof UITableViewCell *cell, NSIndexPath *indexPath);
/// Cell 高度
@property (nonatomic, assign) CGFloat height;
/// 获取高度
@property (nonatomic, copy, nullable) CGFloat (^fetchHeight)(NSIndexPath *indexPath);
/// 标识
@property (nonatomic, copy, nullable) NSString *rowId;
/// 可配置参数
@property (nonatomic, strong, nullable) id userInfo;

/// 初始化方法
/// @param height Cell 高度
/// @param creatCell 创建 Cell 的 Block
+ (instancetype)rowWithHeight:(CGFloat)height creatCell:(UITableViewCell * (^)(UITableView *tableView, NSIndexPath *indexPath))creatCell;

/// 初始化方法
/// @param creatCell 创建 Cell 的 Block
+ (instancetype)creatCell:(UITableViewCell * (^)(UITableView *tableView, NSIndexPath *indexPath))creatCell;

@end

NS_ASSUME_NONNULL_END
