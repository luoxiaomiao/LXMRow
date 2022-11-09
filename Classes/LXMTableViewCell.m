//
//  LXMTableViewCell.m
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import "LXMTableViewCell.h"

@implementation LXMTableViewCell

+ (instancetype)dequeueCellWithTableView:(UITableView *)tableView forIndexPath:(NSIndexPath *)indexPath {
    [tableView registerClass:self forCellReuseIdentifier:NSStringFromClass(self)];
    LXMTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(self) forIndexPath:indexPath];
    return cell;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        [self install];
    }
    return self;
}

- (void)install {
    // 供子类重写
}

// 用于监听不要删
- (void)update:(id)display {
    // 供子类重写
}

+ (CGFloat)expectHeight:(id)display {
    NSAssert(0, @"如需使用 expectHeight:, 需子类重写");
    return 44.0;
}

// 用于监听不要删
- (void)mock {
    // 供子类重写
}

+ (id)mockDisplay {
    // 供子类重写
    return nil;
}

@end
