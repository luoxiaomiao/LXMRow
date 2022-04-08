//
//  LXMTableRow.m
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import "LXMTableRow.h"

@implementation LXMTableRow

+ (instancetype)rowWithHeight:(CGFloat)height
                    creatCell:(UITableViewCell * (^)(UITableView *tableView, NSIndexPath *indexPath))creatCell {
    LXMTableRow *row = [[LXMTableRow alloc] init];
    row.height = height;
    row.creatCell = creatCell;
    return row;
}

+ (instancetype)creatCell:(UITableViewCell * (^)(UITableView *tableView, NSIndexPath *indexPath))creatCell {
    LXMTableRow *row = [[LXMTableRow alloc] init];
    row.creatCell = creatCell;
    return row;
}

@end
