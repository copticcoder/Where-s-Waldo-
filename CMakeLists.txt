cmake_minimum_required(VERSION 3.27)
project(WhereisWaldo)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(WhereisWaldo main.cpp
        waldoDetector.cpp
        waldoDetector.h)
target_link_libraries( WhereisWaldo  ${OpenCV_LIBS})
set(CMAKE_CXX_STANDARD 17)
