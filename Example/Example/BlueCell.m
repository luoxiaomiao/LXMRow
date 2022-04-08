//
//  BlueCell.m
//  Example
//
//  Created by luoxiaomiao on 2019/8/24.
//  Copyright © 2019 omiao. All rights reserved.
//

#import "BlueCell.h"

@implementation BlueCell

- (void)install {
    self.backgroundColor = UIColor.blueColor;
    self.selectionStyle = UITableViewCellSelectionStyleNone;
}

+ (CGFloat)expectHeight:(id)display {
    return 100;
}

@end

@implementation YellowCell

- (void)install {
    self.backgroundColor = UIColor.yellowColor;
    self.selectionStyle = UITableViewCellSelectionStyleNone;
}

+ (CGFloat)expectHeight:(id)display {
    return 150;
}

@end
