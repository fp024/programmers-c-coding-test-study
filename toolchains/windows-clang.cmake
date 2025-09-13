### clang toolchain ###
include("${CMAKE_CURRENT_LIST_DIR}/common_paths.cmake")

message(STATUS "Configuring for preset: windows-clang")

# Clang Toolchain 설정
set(CMAKE_C_COMPILER "${LLVM_ROOT}/bin/clang.exe" CACHE FILEPATH "C compiler for Clang")
set(CMAKE_CXX_COMPILER "${LLVM_ROOT}/bin/clang++.exe" CACHE FILEPATH "CXX compiler for Clang")
set(CMAKE_MAKE_PROGRAM "${NINJA_ROOT}/ninja.exe" CACHE FILEPATH "Ninja executable")

# RC 컴파일러 설정 (llvm-rc 또는 rc.exe)
set(CMAKE_RC_COMPILER "${LLVM_ROOT}/bin/llvm-rc.exe" CACHE FILEPATH "RC compiler")
