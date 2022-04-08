//
//  LXMTableViewCell.h
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 绑定 display 类型；写到 LXMTableViewCell 子类 @interface 内部
#define LXMTableViewCellBindDisplay(x)               \
    -(void)update : (nullable x *)display; \
    +(CGFloat)expectHeight : (nullable x *)display;

NS_ASSUME_NONNULL_BEGIN

@interface LXMTableViewCell : UITableViewCell

/// 复用
/// @param tableView 列表视图
+ (instancetype)dequeueCellWithTableView:(UITableView *)tableView;

/// 初始化配置；供子类重写
- (void)install;

/// 更新；供子类重写
/// @param display 数据
- (void)update:(nullable id)display;

/// 期望高度；供子类重写
/// @param display 数据
+ (CGFloat)expectHeight:(nullable id)display;

/// 模拟；供子类重写
- (void)mock;

/// 模拟数据；供子类重写
+ (nullable id)mockDisplay;

@end

NS_ASSUME_NONNULL_END
