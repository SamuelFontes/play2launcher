#!/bin/bash
# Setup script for raylib and ps2gl dependencies

set -e

echo "Setting up raylib for PS2 development..."

# Check if $PS2DEV is set
if [ -z "$PS2DEV" ]; then
    echo "ERROR: Set \$PS2DEV by installing ps2dev sdk and tools before continuing."
    exit 1
fi

# Check if PS2SDK is set
if [ -z "$PS2SDK" ]; then
    echo "ERROR: Set \$PS2SDK by installing ps2sdk and ports before continuing."
    exit 1
fi

echo "PS2DEV: $PS2DEV"
echo "PS2SDK: $PS2SDK"
echo ""

# Create external directory if it doesn't exist
mkdir -p external
cd external

# Clone and build ps2gl
if [ ! -d "ps2gl" ]; then
    echo "Cloning ps2gl..."
    git clone https://github.com/raylib4Consoles/ps2gl.git
    cd ps2gl
    echo "Building ps2gl..."
    make
    cd ..
else
    echo "ps2gl already exists. Rebuilding if needed..."
    cd ps2gl
    make
    cd ..
fi

# Clone raylib (work branch)
if [ ! -d "raylib" ]; then
    echo "Cloning raylib for consoles (work branch)..."
    git clone https://github.com/raylib4Consoles/raylib.git -b work
    cd raylib/src
    echo "Building raylib for PS2..."
    make PLATFORM=PLATFORM_PLAYSTATION2
    cd ../..
else
    echo "raylib already exists. Checking if built..."
    if [ ! -f "raylib/src/libraylib.a" ]; then
        echo "Building raylib for PS2..."
        cd raylib/src
        make PLATFORM=PLATFORM_PLAYSTATION2
        cd ../..
    else
        echo "raylib already built."
    fi
fi

cd ..

echo ""
echo "Setup complete!"
echo ""
echo "Libraries built in:"
echo "  external/ps2gl/libps2gl.a"
echo "  external/raylib/src/libraylib.a"
echo ""
echo "You can now build your project with CMake."
echo "Run: cd build && cmake .. && make"
