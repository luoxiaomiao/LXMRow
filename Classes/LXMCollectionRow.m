//
//  LXMCollectionRow.m
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import "LXMCollectionRow.h"

@implementation LXMCollectionRow

+ (instancetype)creatCell:(UICollectionViewCell *_Nonnull (^)(UICollectionView *collectionView, NSIndexPath *indexPath))creatCell {
    LXMCollectionRow *row = [[self alloc] init];
    row.creatCell = creatCell;
    return row;
}

- (CGSize)getSizeForIndexPath:(NSIndexPath *)indexPath {
    return self.fetchSize ? self.fetchSize(indexPath) : self.size;
}

@end
