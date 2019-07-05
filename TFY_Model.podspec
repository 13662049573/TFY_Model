

Pod::Spec.new do |spec|

  spec.name         = "TFY_Model"

  spec.version      = "2.6.2"

  spec.summary      = "模型数据解析，数据库添加。"

  spec.description  = "json解析数据,数据库添加。"

  spec.homepage     = "https://github.com/13662049573/TFY_Model"

  spec.license      = "MIT"

  spec.author       = { "tianfengyou" => "420144542@qq.com" }

  spec.platform     = :ios, "10.0"


  spec.source       = { :git => "https://github.com/13662049573/TFY_Model.git", :tag => spec.version }


  spec.source_files  = "TFY_Model/TFY_ModelKit/*.{h,m}","TFY_Model/TFY_ModelKit/TFY_ModelSqliteHeader.h"
  
  spec.frameworks    = "Foundation","UIKit"

  spec.xcconfig      = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include" }

  spec.library        = "sqlite3"

  spec.requires_arc   = true

end
