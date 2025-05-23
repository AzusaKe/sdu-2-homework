#!/bin/bash
set -e

APP_NAME="sdu-2-homework"
EXECUTABLE="/home/azusake/CLionProjects/sdu-2-homework/cmake-build-debug/bin/SDU_2_homework"
ICON_PATH="/home/azusake/CLionProjects/sdu-2-homework/cmake-build-debug/bin/icon.ico"
APP_DIR="./AppDir"

# 下载工具
[ ! -f linuxdeploy-x86_64.AppImage ] && wget -q https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage
[ ! -f linuxdeploy-plugin-qt-x86_64.AppImage ] && wget -q https://github.com/linuxdeploy/linuxdeploy-plugin-qt/releases/download/continuous/linuxdeploy-plugin-qt-x86_64.AppImage
chmod +x linuxdeploy*.AppImage

# 准备图标
ICON_PNG="icon.png"
convert "$ICON_PATH[0]" -resize 256x256 "$ICON_PNG"

# 准备 desktop 文件
cat > "$APP_NAME.desktop" <<EOF
[Desktop Entry]
Name=SDU 2 Homework
Exec=SDU_2_homework
Icon=icon
Type=Application
Categories=Utility;
EOF

# 清理旧数据
rm -rf "$APP_DIR"

# 打包 AppImage

export QTDIR="/home/azusake/Qt/6.7.3/gcc_64"
export PATH="$QTDIR/bin:$PATH"
export LD_LIBRARY_PATH="$QTDIR/lib:$LD_LIBRARY_PATH"

./linuxdeploy-x86_64.AppImage \
  --appdir "$APP_DIR" \
  --executable "$EXECUTABLE" \
  --desktop-file "$APP_NAME.desktop" \
  --icon-file "$ICON_PNG" \
  --plugin qt \
  --output appimage

# 清理临时文件
rm "$APP_NAME.desktop" "$ICON_PNG"

echo "✅ AppImage 打包完成，文件名为：$(ls ./*.AppImage)"

