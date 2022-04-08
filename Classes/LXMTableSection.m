//
//  LXMTableSection.m
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import "LXMTableSection.h"

@implementation LXMTableSection

- (instancetype)init {
    if (self = [super init]) {
        _rows = [NSMutableArray array];
    }
    return self;
}

+ (instancetype)section {
    LXMTableSection *section = [[LXMTableSection alloc] init];
    return section;
}

- (void)addRow:(LXMTableRow *)row {
    [self.rows addObject:row];
}

- (void)addRows:(NSArray<LXMTableRow *> *)rows {
    [self.rows addObjectsFromArray:rows];
}

@end
