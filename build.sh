# THIS SHELLSCRIPT WAS FUELED BY PURE RAGE AND AGONY. MADE PARTIALLY BY
# CHAT GPT BECAUSE I DONT GIVE A FLYING F. I HATE MAKEFILE I HATE CMAKE I HATE
# HOW EVERYTHING MUST BE OVER COMPLICATED AND LITTERED FOR NO REASON. THANKS

#!/bin/zsh

SOURCE_DIR="./src/main"
BIN_DIR="./bin"
BUILD_DIR="./build/debug"
GL_LIBS="-lGLEW -lGL-lglfw"

mkdir -p "$BIN_DIR"
mkdir -p "$BUILD_DIR"

SOURCES=$(find "$SOURCE_DIR" -type f -name "*.cpp")

OBJECTS=()

for SRC in $SOURCES; do
    BASE_NAME=$(basename "$SRC" .cpp)

    g++ -c -g "$SRC" -o "$BIN_DIR/$BASE_NAME.o"

    OBJECTS+=("$BIN_DIR/$BASE_NAME.o")
done

if [ ${#OBJECTS[@]} -gt 0 ]; then
    g++ -o "$BUILD_DIR/client" "${OBJECTS[@]}" -lGLEW -lGL -lglfw
    echo "Build complete."
else
    echo "No source files found to compile."
fi
