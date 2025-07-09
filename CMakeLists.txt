cmake_minimum_required(VERSION 3.15)
project(LaneDetection LANGUAGES CXX)

# Export compile commands for IDEs (optional)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find OpenCV via Homebrew
find_package(OpenCV REQUIRED core imgproc highgui videoio)

message(STATUS "OpenCV include path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")

add_executable(lane_detect src/main.cpp)
target_link_libraries(lane_detect PRIVATE ${OpenCV_LIBS})
target_include_directories(lane_detect PRIVATE ${OpenCV_INCLUDE_DIRS})
