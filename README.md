# Real-Time Lane Detection Pipeline for Autonomous Driving using Classical Computer Vision 

I've been interested in AVs for quite some time, and I want to learn more about a simple method to monitor whether or not cars are staying in their lane using traditional CV methods, and avoiding the usage of the very powerful, but **expensive** GPUs.
I plan on processing live video from a road, identify lane regions, detect edges, keypoints, apply Hough Transforms to get lane lines and visualize it in real time.
Eventually, I want to create a URDF of a robot/car, simulate a LIDAR/ZED camera and test it in a simulated enviroment like Gazebo or rviz.

````markdown
# SETUP

## Prerequisites

- **macOS** with admin privileges
- **Homebrew** package manager
- **Xcode Command Line Tools** (for compiler and `make`)
- **Visual Studio Code** (optional, recommended for IDE)
- **CMake** (>= 3.15)

### Install Prerequisites

````

1. **Install Homebrew** (if not already installed):

   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Install CMake**

   ```bash
   brew update
   brew install cmake
   ```

3. **Install OpenCV**

   ```bash
   brew install opencv
   ```

## Project Structure

```
Lane-Detection/          # Project root
├── CMakeLists.txt       # Build instructions
├── src/
│   └── main.cpp         # Your C++ source code
└── build/               # Generated build directory
```

## Step-by-Step Setup

1. **Clone the Repository**

   ```bash
   git clone <your-repo-url> Lane-Detection
   cd Lane-Detection
   ```

2. **Create `CMakeLists.txt`**

   Ensure your `CMakeLists.txt` contains:

   ```cmake
   cmake_minimum_required(VERSION 3.15)
   project(LaneDetection LANGUAGES CXX)

   set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

   find_package(OpenCV REQUIRED core imgproc highgui videoio)

   message(STATUS "OpenCV include path: ${OpenCV_INCLUDE_DIRS}")
   message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")

   add_executable(lane_detect src/main.cpp)
   target_link_libraries(lane_detect PRIVATE ${OpenCV_LIBS})
   target_include_directories(lane_detect PRIVATE ${OpenCV_INCLUDE_DIRS})
   ```

3. **Add `src/main.cpp`**

   As a starting point, you can use:

   ```cpp
   #include <opencv2/opencv.hpp>
   #include <iostream>

   int main() {
       std::cout << "OpenCV version: " << CV_VERSION << std::endl;
       return 0;
   }
   ```

4. **Configure and Build**

   ```bash
   mkdir -p build
   cd build
   cmake ..
   cmake --build .
   ```

5. **Run the Executable**

   From within `build/`:

   ```bash
   ./lane_detect
   ```
   You should see the contents of your main.cpp file - which in this case is: "Hello World!"

## VS Code Configuration (Optional)

To enable proper IntelliSense and squiggles in VS Code:

1. Install the **C/C++** and **CMake Tools** extensions.
2. Create or update `.vscode/settings.json` in project root:

   ```json
   {
     "C_Cpp.default.compileCommands": "${workspaceFolder}/build/compile_commands.json",
     "C_Cpp.default.cppStandard": "c++17",
     "C_Cpp.default.intelliSenseMode": "macos-clang-x64"
   }
   ```
3. Reload VS Code.
