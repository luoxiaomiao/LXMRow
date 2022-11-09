
Pod::Spec.new do |spec|

  spec.name         = "LXMRow"
  spec.version      = "1.0.1"
  spec.summary      = "UI 脚手架"
  spec.description  = <<-DESC
                      UITableView 和 UICollectionView 的脚手架
                   DESC
  spec.homepage     = "https://github.com/luoxiaomiao/LXMRow"
  spec.license      = "MIT"
  spec.author             = { "luoxiaomiao" => "luoyangguang@live.com" }
  spec.platform     = :ios, "8.0"
  spec.source       = { :git => "https://github.com/luoxiaomiao/LXMRow.git", :tag => "#{spec.version}" }
  spec.source_files  = "Classes", "Classes/*.{h,m}"
  spec.requires_arc = true
end
