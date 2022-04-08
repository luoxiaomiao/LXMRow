//
//  LXMCollectionSection.m
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import "LXMCollectionSection.h"

@implementation LXMCollectionSection

- (instancetype)init {
    if (self = [super init]) {
        _rows = [NSMutableArray array];
    }
    return self;
}

+ (instancetype)section {
    return [[self alloc] init];
}

- (void)addRow:(LXMCollectionRow *)row {
    [self.rows addObject:row];
}

- (void)addRows:(NSArray<LXMCollectionRow *> *)rows {
    [self.rows addObjectsFromArray:rows];
}

@end
