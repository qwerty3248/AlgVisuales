cmake_minimum_required(VERSION 3.5)
project(PathfindingVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(PathfindingVisualizer
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    src/gridcell.cpp
    include/gridcell.h
    src/graphalgorithms.cpp
    include/graphalgorithms.h
    src/pathfindercontroller.cpp
    include/pathfindercontroller.h
)

target_link_libraries(PathfindingVisualizer Qt5::Widgets)