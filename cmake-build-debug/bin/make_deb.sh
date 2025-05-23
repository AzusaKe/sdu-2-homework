#!/bin/bash

set -e

APP_NAME="sdu-2-homework"
APP_EXEC="/home/azusake/CLionProjects/sdu-2-homework/cmake-build-debug/bin/SDU_2_homework"
ICON_SRC="/home/azusake/CLionProjects/sdu-2-homework/cmake-build-debug/bin/icon.ico"
VERSION="1.0"
ARCH="amd64"

WORK_DIR="build_deb"
INSTALL_PREFIX="$WORK_DIR/usr"
BIN_DIR="$INSTALL_PREFIX/bin"
DESKTOP_DIR="$INSTALL_PREFIX/share/applications"
ICON_DIR="$INSTALL_PREFIX/share/icons/hicolor/256x256/apps"
DEBIAN_DIR="$WORK_DIR/DEBIAN"

echo "Cleaning up old build..."
rm -rf "$WORK_DIR"
mkdir -p "$BIN_DIR" "$DESKTOP_DIR" "$ICON_DIR" "$DEBIAN_DIR"

echo "Copying executable and icon..."
cp "$APP_EXEC" "$BIN_DIR/$APP_NAME"
convert "$ICON_SRC[0]" -resize 256x256 "$ICON_DIR/${APP_NAME}.png"  # 要求 ImageMagick

echo "Generating .desktop file..."
cat > "$DESKTOP_DIR/${APP_NAME}.desktop" <<EOF
[Desktop Entry]
Name=SDU 2 Homework
Exec=/usr/bin/$APP_NAME
Icon=$APP_NAME
Type=Application
Categories=Utility;
EOF

echo "Generating control file..."
cat > "$DEBIAN_DIR/control" <<EOF
Package: $APP_NAME
Version: $VERSION
Section: utils
Priority: optional
Architecture: $ARCH
Maintainer: Azusa <azusa@example.com>
Description: SDU Qt Homework Project
Depends: libqt6core6, libqt6gui6, libqt6widgets6
EOF

echo "Building .deb package..."
dpkg-deb --build "$WORK_DIR" "${APP_NAME}_${VERSION}_${ARCH}.deb"

echo "Cleaning up build directory..."
rm -rf "$WORK_DIR"

echo "✅ Done: ${APP_NAME}_${VERSION}_${ARCH}.deb"

