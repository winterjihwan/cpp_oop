cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 설정
project(MyProject)

# C++ 20 표준 설정
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# SFML 설치 경로 설정
set(CMAKE_PREFIX_PATH "C:/SFML-2.6.1")

# Include directories for header files
include_directories(${CMAKE_SOURCE_DIR}/src/model)
include_directories(${CMAKE_SOURCE_DIR}/src/view)
include_directories(${CMAKE_SOURCE_DIR}/src/controller)
include_directories(${CMAKE_SOURCE_DIR}/src/command)

# 소스 파일들을 재귀적으로 추가
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# SFML 2.6.1 버전 찾기 및 구성
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

# 메인 실행 파일 생성
add_executable(MyProject ${SRC_FILES})

# SFML include 디렉토리 설정
target_include_directories(MyProject PRIVATE "C:/SFML-2.6.1/include")

# SFML 라이브러리와 링크 설정
target_link_libraries(MyProject sfml-graphics sfml-window sfml-system)

# 추가 경고 메시지와 디버그 정보 표시를 위해 빌드 옵션 추가 (optional)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g")
