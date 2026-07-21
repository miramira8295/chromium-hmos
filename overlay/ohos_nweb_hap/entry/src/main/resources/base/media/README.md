# 资源文件说明

## 需要的资源文件

### 应用图标
- `app_icon.png` - 应用图标（需要添加）
  - 建议尺寸：512x512像素
  - 格式：PNG

### 组件图标（可选）
- `ic_back.png` - 返回按钮图标
- `ic_refresh.png` - 刷新按钮图标
- `ic_menu.png` - 菜单图标
- `ic_bookmark.png` - 书签图标
- `ic_settings.png` - 设置图标
- `ic_add.png` - 添加图标
- `ic_close.png` - 关闭图标

## 临时解决方案

如果暂时没有图标文件，可以：
1. 使用文本按钮代替图标按钮
2. 使用系统内置图标
3. 使用占位符图片

## 添加资源文件步骤

1. 将图标文件复制到 `entry/src/main/resources/base/media/` 目录
2. 在代码中使用 `$r('app.media.icon_name')` 引用
3. 重新构建项目

