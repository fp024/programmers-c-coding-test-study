### mingw toolchain ###
include("${CMAKE_CURRENT_LIST_DIR}/common_paths.cmake")

message(STATUS "Configuring for preset: mingw")
# MinGW Toolchain 설정
set(CMAKE_C_COMPILER "${MINGW_ROOT}/bin/gcc.exe" CACHE FILEPATH "C compiler for MinGW")
set(CMAKE_CXX_COMPILER "${MINGW_ROOT}/bin/g++.exe" CACHE FILEPATH "CXX compiler for MinGW")
set(CMAKE_MAKE_PROGRAM "${NINJA_ROOT}/ninja.exe" CACHE FILEPATH "Ninja executable")

# MinGW의 경우 bin 폴더를 PATH에 추가
set(ENV{PATH} "${MINGW_ROOT}/bin;$ENV{PATH}")
