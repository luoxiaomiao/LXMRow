//
//  LXMView.h
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import <UIKit/UIKit.h>

// 绑定 display 类型；写到 LXMView 子类 @interface 内部
#define LXMViewBindDisplay(x)               \
-(void)update : (nullable x *)display; \
+(CGSize)expectSize : (nullable x *)display;

NS_ASSUME_NONNULL_BEGIN

@interface LXMView : UIView

/// 初始化配置
- (void)install;

/// 更新；供子类重写
/// @param display 数据
- (void)update:(nullable id)display;

/// 期望尺寸；供子类重写
/// @param display 数据
+ (CGSize)expectSize:(nullable id)display;

/// 模拟；供子类重写
- (void)mock;

/// 模拟数据；供子类重写
+ (nullable id)mockDisplay;

@end

NS_ASSUME_NONNULL_END
