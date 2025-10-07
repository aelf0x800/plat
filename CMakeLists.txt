# Set CMake minimum version
cmake_minimum_required(VERSION 3.30)

project(Plat)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Download and compile raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

# Add source files to the compilation
add_executable(
    Plat 
    Plat/Main.cpp 
    Plat/World/File.cpp
    Plat/World/TokenList.cpp
)

# Add libraries to link to the program
target_link_libraries(Plat PRIVATE raylib)
