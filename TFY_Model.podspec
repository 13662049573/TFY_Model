Pod::Spec.new do |s|
    s.name = "TFY_Model"
    s.version = "0.0.1"
    s.summary = "iOS平台高效转换引擎json->model,model->json,model->Dictionary,支持模型类继承其他模型类,支持指定路径转换,不区分json的key和模型属性名称大小写,自动处理json中null"
    s.description = "版本控制数据"
    s.homepage = "https://github.com/13662049573/TFY_Model"
    s.license = "MIT"
    s.author = { "tianfengyou" => "420144542@qq.com" }
    s.platform = :ios,'10.0'
    s.source = { :git => 'https://github.com/13662049573/TFY_Model.git', :tag => s.version, :submodules => true }
    s.source_files = "TFY_Model/TFY_ModelKit/*.{h,m}"
    s.source_files = "TFY_Model/UINavigationController/*.{h,m}"
    s.requires_arc = true
    s.frameworks = "UIKit"
    s.ios.deployment_target = "9.0"
end
