cmake_minimum_required(VERSION 3.10)

# PS2SDK environment variable
if(NOT DEFINED ENV{PS2SDK})
    message(FATAL_ERROR "PS2SDK environment variable is not set")
endif()

set(PS2SDK $ENV{PS2SDK})

# Set the PS2SDK toolchain (must be before project())
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR mips64r5900el)

# Skip compiler tests for cross-compilation
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Set the compiler
set(CMAKE_C_COMPILER mips64r5900el-ps2-elf-gcc)
set(CMAKE_CXX_COMPILER mips64r5900el-ps2-elf-g++)
set(CMAKE_ASM_COMPILER mips64r5900el-ps2-elf-gcc)
set(CMAKE_AR mips64r5900el-ps2-elf-ar CACHE FILEPATH "Archiver")
set(CMAKE_RANLIB mips64r5900el-ps2-elf-ranlib CACHE FILEPATH "Ranlib")
set(CMAKE_STRIP mips64r5900el-ps2-elf-strip CACHE FILEPATH "Strip")

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Search for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

project(play2launcher C)

# Generate compile_commands.json for LSP/IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Base compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_EE -G0 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_EE -G0 -Wall")

# Debug configuration
set(CMAKE_C_FLAGS_DEBUG "-O0 -gdwarf-2 -gz")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -gdwarf-2 -gz")

# Release configuration
set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Include directories
include_directories(
    ${PS2SDK}/ee/include
    ${PS2SDK}/common/include
)

# Link directories
link_directories(
    ${PS2SDK}/ee/lib
)

# Source files
set(SOURCES
    main.c
)

# Create the executable
add_executable(play2launcher.elf ${SOURCES})

# Link libraries (order matters for PS2SDK)
# Set linker flags to match PS2SDK requirements exactly
target_link_options(play2launcher.elf PRIVATE
    -T${PS2SDK}/ee/startup/linkfile
    -L${PS2SDK}/ee/lib
    -Wl,-zmax-page-size=128
    -ldebug
    -lpad
    -lkernel
)

# Strip the executable only for Release builds
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET play2launcher.elf POST_BUILD
        COMMAND ${CMAKE_STRIP} $<TARGET_FILE:play2launcher.elf>
        COMMENT "Stripping release executable..."
    )
endif()

# Install target (optional)
install(TARGETS play2launcher.elf DESTINATION bin)
