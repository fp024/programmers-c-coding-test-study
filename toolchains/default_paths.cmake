# 기본 경로 (샘플)
set(LLVM_ROOT "C:/LLVM/21.x" CACHE PATH "Path to LLVM root")
set(MINGW_ROOT "C:/MinGW-w64" CACHE PATH "Path to MinGW-w64 root")
set(NINJA_ROOT "C:/Ninja/latest" CACHE PATH "Path to Ninja root")

# WINDOWS SDK, VC 경로
# MSVC_ROOT는 표준 경로로 사용하기 위해 정션링크를 걸어주었다. 
# - BuildTools 환경인 경우
#   C:\MSVC_ROOT ==> {드라이브_문자}:\VisualStudio\2022\BuildTools\VC
# - VS2022 커뮤니티 환경인 경우
#   C:\MSVC_ROOT ==> {드라이브_문자}:\VS2022\Community\VC
set(MSVC_TOOLS_ROOT "C:/MSVC_ROOT/Tools/MSVC/14.44.35207" CACHE PATH "Path to MSVC Tools Root")
set(WINSDK_LIB_ROOT "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.26100.0" CACHE PATH "Path to Windows SDK Lib Root")
set(WINSDK_INCLUDE_ROOT "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0" CACHE PATH "Path to Windows SDK Include Root")
