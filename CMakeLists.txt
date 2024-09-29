cmake_minimum_required(VERSION 3.30)

project(MyProject)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(main ${SRC_FILES})

target_link_libraries(main sfml-graphics sfml-window sfml-system)
