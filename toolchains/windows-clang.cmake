### clang toolchain ###
include("${CMAKE_CURRENT_LIST_DIR}/common_paths.cmake")

message(STATUS "Configuring for preset: windows-clang")

# Clang Toolchain 설정
# Windows에서는 clang/clang++보다 clang-cl이 MSVC 스타일 빌드 흐름과 더 잘 맞는다.
set(CMAKE_C_COMPILER "${LLVM_ROOT}/bin/clang-cl.exe" CACHE FILEPATH "C compiler for Clang")
set(CMAKE_CXX_COMPILER "${LLVM_ROOT}/bin/clang-cl.exe" CACHE FILEPATH "CXX compiler for Clang")
set(CMAKE_MAKE_PROGRAM "${NINJA_ROOT}/ninja.exe" CACHE FILEPATH "Ninja executable")

# RC 컴파일러 설정
set(CMAKE_RC_COMPILER "${LLVM_ROOT}/bin/llvm-rc.exe" CACHE FILEPATH "RC compiler")

# MSVC / Windows SDK include path
# 일반 터미널에서도 Windows SDK/MSVC 헤더와 라이브러리를 찾도록 경로를 명시한다.
# 이 설정이 없으면 kernel32.lib, msvcrtd.lib, oldnames.lib 링크 오류가 다시 날 수 있다.
string(APPEND CMAKE_C_FLAGS_INIT
    " /imsvc\"${MSVC_TOOLS_ROOT}/include\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/ucrt\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/shared\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/um\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/winrt\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/cppwinrt\""
)

string(APPEND CMAKE_CXX_FLAGS_INIT
    " /imsvc\"${MSVC_TOOLS_ROOT}/include\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/ucrt\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/shared\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/um\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/winrt\""
    " /imsvc\"${WINSDK_INCLUDE_ROOT}/cppwinrt\""
)

# MSVC / Windows SDK library path
string(APPEND CMAKE_EXE_LINKER_FLAGS_INIT
    " /libpath:\"${MSVC_TOOLS_ROOT}/lib/x64\""
    " /libpath:\"${WINSDK_LIB_ROOT}/ucrt/x64\""
    " /libpath:\"${WINSDK_LIB_ROOT}/um/x64\""
)

string(APPEND CMAKE_SHARED_LINKER_FLAGS_INIT
    " /libpath:\"${MSVC_TOOLS_ROOT}/lib/x64\""
    " /libpath:\"${WINSDK_LIB_ROOT}/ucrt/x64\""
    " /libpath:\"${WINSDK_LIB_ROOT}/um/x64\""
)

string(APPEND CMAKE_MODULE_LINKER_FLAGS_INIT
    " /libpath:\"${MSVC_TOOLS_ROOT}/lib/x64\""
    " /libpath:\"${WINSDK_LIB_ROOT}/ucrt/x64\""
    " /libpath:\"${WINSDK_LIB_ROOT}/um/x64\""
)
