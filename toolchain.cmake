# toolchain.cmake

# 컴파일러 및 도구 경로 설정 (절대 경로)
set(LLVM_ROOT "C:/LLVM/20.x" CACHE PATH "Path to LLVM root")
set(MINGW_ROOT "C:/MinGW-w64" CACHE PATH "Path to MinGW-w64 root")
set(NINJA_ROOT "C:/Ninja/1.12.x" CACHE PATH "Path to Ninja root")
set(VS2022_TOOLS_ROOT "C:/VS2022/VC_TOOLS_X64_LINK" CACHE PATH "Path to VS2022 VC Tools")

# -----------------------------------------------------------
# Clang Toolchain 설정
# -----------------------------------------------------------
if (CMAKE_SYSTEM_NAME STREQUAL "Windows" AND CMAKE_GENERATOR_TOOLSET MATCHES "Clang")
    # Clang 컴파일러 경로 지정
    set(CMAKE_C_COMPILER "${LLVM_ROOT}/bin/clang.exe" CACHE FILEPATH "C compiler for Clang")
    set(CMAKE_CXX_COMPILER "${LLVM_ROOT}/bin/clang++.exe" CACHE FILEPATH "CXX compiler for Clang")
    set(CMAKE_RC_COMPILER "${VS2022_TOOLS_ROOT}/rc.exe" CACHE FILEPATH "RC compiler for Clang (Windows Resource Compiler)")
    set(CMAKE_MAKE_PROGRAM "${NINJA_ROOT}/ninja.exe" CACHE FILEPATH "Ninja executable")

    # 필요한 경우 PATH 환경 변수 추가 (Clang 자체는 PATH 불필요, VS Toolchain 관련은 필요)
    # environment: { "PATH": "${env:PATH};${VS2022_TOOLS_ROOT}" } 등을 고려
endif ()

# -----------------------------------------------------------
# MinGW Toolchain 설정
# -----------------------------------------------------------
if (CMAKE_HOST_WIN32 AND CMAKE_GENERATOR_TOOLSET MATCHES "MinGW") # 또는 CMAKE_C_COMPILER_ID STREQUAL "GNU"
    # MinGW 컴파일러 경로 지정
    set(CMAKE_C_COMPILER "${MINGW_ROOT}/bin/gcc.exe" CACHE FILEPATH "C compiler for MinGW")
    set(CMAKE_CXX_COMPILER "${MINGW_ROOT}/bin/g++.exe" CACHE FILEPATH "CXX compiler for MinGW")
    set(CMAKE_MAKE_PROGRAM "${NINJA_ROOT}/ninja.exe" CACHE FILEPATH "Ninja executable")

    # MinGW의 경우 bin 폴더를 PATH에 추가하는 것이 일반적
    set(ENV{PATH} "${MINGW_ROOT}/bin;$ENV{PATH}")
endif ()

# 공통 설정 (Ninja 경로 등)
# 이 부분은 각 if 블록 안에 넣는 것이 더 명확할 수 있음
# set(CMAKE_MAKE_PROGRAM "${NINJA_ROOT}/ninja.exe" CACHE FILEPATH "Ninja executable")