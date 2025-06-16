### clang toolchain ###
include("${CMAKE_CURRENT_LIST_DIR}/common_paths.cmake")

message(STATUS "Configuring for preset: windows-clang")
# Clang Toolchain 설정
set(CMAKE_C_COMPILER "${LLVM_ROOT}/bin/clang.exe" CACHE FILEPATH "C compiler for Clang")
set(CMAKE_CXX_COMPILER "${LLVM_ROOT}/bin/clang++.exe" CACHE FILEPATH "CXX compiler for Clang")
set(CMAKE_RC_COMPILER "${VS2022_TOOLS_ROOT}/rc.exe" CACHE FILEPATH "RC compiler for Clang (Windows Resource Compiler)")
set(CMAKE_MAKE_PROGRAM "${NINJA_ROOT}/ninja.exe" CACHE FILEPATH "Ninja executable")
