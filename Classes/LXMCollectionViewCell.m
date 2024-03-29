//
//  LXMCollectionViewCell.m
//  LXMRow
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import "LXMCollectionViewCell.h"

@implementation LXMCollectionViewCell

+ (instancetype)dequeueCellWithCollectionView:(UICollectionView *)collectionView forIndexPath:(nonnull NSIndexPath *)indexPath {
    [collectionView registerClass:self forCellWithReuseIdentifier:NSStringFromClass(self)];
    return [collectionView dequeueReusableCellWithReuseIdentifier:NSStringFromClass(self) forIndexPath:indexPath];
}

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self install];
    }
    return self;
}

- (void)install {
    // 供子类重写
}

- (void)update:(id)display {
    // 供子类重写
}

+ (CGSize)expectSize:(id)display {
    // 供子类重写
    NSAssert(0, @"如需使用 expectSize:, 需子类重写");
    return CGSizeMake(44, 44);
}

- (void)mock {
    // 供子类重写
}

+ (id)mockDisplay {
    // 供子类重写
    return nil;
}

@end
