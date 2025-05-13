cmake_minimum_required(VERSION 3.5)
project(UASPCD)

# Find OpenCV package
find_package(OpenCV REQUIRED)

#include directories from OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB COMPONENT_SOURCES "components/*.cpp")

# Create an executable
add_executable(App index.cpp ${COMPONENT_SOURCES})

# Link OpenCV libraries
target_link_libraries(App ${OpenCV_LIBS})