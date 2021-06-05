# Set minimum version required
cmake_minimum_required(VERSION 2.8.12)

# Set project name
project(GettingStarted)

# enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Confirm OpenCV is installed correctly
find_package( OpenCV REQUIRED )

# include OpenCV directories
include_directories( ${OpenCV_INCLUDE_DIRS})

# Create source variable with a link to all cpp files to compile
set(SOURCES
    TestApp.cpp
    Utiliies.cpp
)

# Required for OpenCV built as static libs
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

# Compile
add_executable(GettingStarted ${SOURCES})
target_link_libraries(GettingStarted ${OpenCV_LIBS} )