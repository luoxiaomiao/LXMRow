# LXMRow
## 项目介绍

此项目主要用于搭建复杂的页面结构，比如 `UITableView` 和 `UICollectionView` 框架的复杂滚动列表。相对于原生的实现，此框架实现了业务的收口，对于频繁的业务更改和多团队合作能很好的支持，更加方便快捷搭建 UI 页面。

## 集成方式

```
pod 'LXMRow'~>1.0.1
```

## 使用方法

首先在代理方法里返回固定写法，这样写的好处是可以快速复制，增强项目健壮性。具体写法如下：

```objective-c
#pragma mark - UITableView 代理方法

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return self.sections.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    LXMTableSection *sec = [self sectionObjInSection:section];
    return sec.rows.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    return CGFLOAT_MIN;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
    return CGFLOAT_MIN;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    LXMTableRow *row = [self rowObjAtIndexPath:indexPath];
    CGFloat height = row.fetchHeight ? row.fetchHeight(indexPath) : row.height;
    if (height < 0) {
        return 0;
    }
    return height;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section {
    return nil;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section {
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    LXMTableRow *row = [self rowObjAtIndexPath:indexPath];
    if (row.creatCell) {
        return row.creatCell(tableView, indexPath);
    } else {
        return nil;
    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    LXMTableRow *row = [self rowObjAtIndexPath:indexPath];
    if (row.didSelectCell) {
        row.didSelectCell(indexPath);
    }
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    LXMTableRow *row = [self rowObjAtIndexPath:indexPath];
    if (row.willDisplayCell) {
        row.willDisplayCell(cell, indexPath);
    }
}

- (void)tableView:(UITableView *)tableView didEndDisplayingCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    LXMTableRow *row = [self rowObjAtIndexPath:indexPath];
    if (row.didEndDisplayCell) {
        row.didEndDisplayCell(cell, indexPath);
    }
}

#pragma mark - Private 避免越界

- (LXMTableSection *)sectionObjInSection:(NSInteger)section {
    if (self.sections.count <= section) {
        NSLog(@"lxm: sec 越界 入参: %ld, self.sections: %@", section, self.sections);
        return nil;
    }
    LXMTableSection *sec = [self.sections objectAtIndex:section];
    return sec;
}

- (LXMTableRow *)rowObjAtIndexPath:(NSIndexPath *)indexPath {
    LXMTableSection *sec = [self sectionObjInSection:indexPath.section];
    if (sec.rows.count <= indexPath.row) {
        NSLog(@"lxm: row 越界 入参: %@, sec.rows: %@", indexPath, sec.rows);
        return nil;
    }
    LXMTableRow *row = [sec.rows objectAtIndex:indexPath.row];
    return row;
}
```

其中 `self.sections` 是声明的一个数组，具体如下:

```objective-c
/// Cell 分组数据
@property (nonatomic, strong) NSMutableArray<LXMTableSection *> *sections;
```

这样写就是一个 `UITableViewStyleGrouped` 类型的 `UITableVIew` 当然我们也可以使用 `UITableViewStylePlain` ，我们只需要新建一个如下的数组就可以了，代理方法里面的调用也对应的更改一下，建议使用 `UITableViewStyleGrouped`。

```objective-c
@property (nonatomic, strong) NSMutableArray<LXMTableRow *> *rows;
```

具体 `Cell` 的添加如下：

```objective-c
- (void)setupViews {
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    self.tableView.backgroundColor = [UIColor clearColor];
    self.tableView.estimatedRowHeight = 0;
    self.tableView.estimatedSectionHeaderHeight = 0;
    self.tableView.estimatedSectionFooterHeight = 0;
    self.tableView.showsVerticalScrollIndicator = NO;
    // 解决刘海屏跳转横屏直播 cell.contentView 变形
    self.tableView.insetsContentViewsToSafeArea = NO;
    self.tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.view);
    }];
}

- (void)installCells {
    self.sections = [NSMutableArray array];
    [self addSpaceCellWithHeight:100 color:UIColor.clearColor];
    [self addYellowCell];
    [self addSpaceCellWithHeight:10 color:UIColor.clearColor];
    [self addBlueCell];
    [self.tableView reloadData];
}

- (void)addYellowCell {
    @weakify(self);
    LXMTableSection *sec = [LXMTableSection section];
    LXMTableRow *row = [LXMTableRow rowWithHeight:[YellowCell expectHeight:nil] creatCell:^UITableViewCell * _Nonnull(UITableView * _Nonnull tableView, NSIndexPath * _Nonnull indexPath) {
        YellowCell *cell = [YellowCell dequeueCellWithTableView:tableView forIndexPath:indexPath];
        return cell;
    }];
    
    [row setDidSelectCell:^(NSIndexPath * _Nonnull indexPath) {
        @strongify(self);
        DetailViewController *vc = [[DetailViewController alloc] init];
        vc.view.backgroundColor = UIColor.yellowColor;
        [self.navigationController pushViewController:vc animated:YES];
    }];
    
    [sec addRow:row];
    [self.sections addObject:sec];
}

- (void)addBlueCell {
    @weakify(self);
    LXMTableSection *sec = [LXMTableSection section];
    LXMTableRow *row = [LXMTableRow rowWithHeight:[BlueCell expectHeight:nil] creatCell:^UITableViewCell * _Nonnull(UITableView * _Nonnull tableView, NSIndexPath * _Nonnull indexPath) {
        BlueCell *cell = [BlueCell dequeueCellWithTableView:tableView forIndexPath:indexPath];
        return cell;
    }];
    
    [row setDidSelectCell:^(NSIndexPath * _Nonnull indexPath) {
        @strongify(self);
        DetailViewController *vc = [[DetailViewController alloc] init];
        vc.view.backgroundColor = UIColor.blueColor;
        [self.navigationController pushViewController:vc animated:YES];
    }];
    
    [sec addRow:row];
    [self.sections addObject:sec];
}

/// 添加空白 Cell
- (void)addSpaceCellWithHeight:(CGFloat)height color:(UIColor *)color {
    LXMTableSection *sec = [LXMTableSection section];
    LXMTableRow *row = [LXMTableRow rowWithHeight:height creatCell:^UITableViewCell * _Nonnull(UITableView * _Nonnull tableView, NSIndexPath * _Nonnull indexPath) {
        LXMTableViewCell *cell = [LXMTableViewCell dequeueCellWithTableView:tableView forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.backgroundColor = color;
        return cell;
    }];
    [sec addRow:row];
    [self.sections addObject:sec];
}
```

