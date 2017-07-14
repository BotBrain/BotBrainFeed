#
# Be sure to run `pod lib lint BotBrainFeed.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'BotBrainFeed'
  s.version          = '0.4.0'
  s.summary          = '布本智能图文SDK'

  s.homepage         = 'https://github.com/BotBrain/BotBrainFeed'
  s.license = {
    :type => "Copyright",
    :text => "      Copyright (c) 2016 BotBrain. All rights reserved.\n"
  }
  s.author           = { 'BotBrain' => 'zhangzhan@firedata.cc' }
  s.source           = { :git => 'https://github.com/BotBrain/BotBrainFeed.git', :tag => s.version.to_s }
  s.ios.deployment_target = '8.0'
  s.requires_arc = true

  s.subspec 'GDTLibrary' do |ss|
  ss.source_files = 'BotBrainFeed/Classes/GDTLibrary/*.h'
  ss.vendored_library = 'BotBrainFeed/Classes/GDTLibrary/libGDTMobSDK.a'
  end


  s.vendored_frameworks = 'BotBrainFeed/Classes/*.framework'
  s.resource = 'BotBrainFeed/Assets/*.bundle'

  s.dependency 'AFNetworking', '~> 3.1.0'
  s.dependency 'SDWebImage', '~> 4.0.0'
  s.dependency 'BotFireData', '~>0.1.0'

  s.frameworks = 'WebKit'
  s.libraries = 'z'
  s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}

end
