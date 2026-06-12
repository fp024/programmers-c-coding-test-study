# 기본 경로 (샘플)
set(LLVM_ROOT "C:/LLVM/21.x" CACHE PATH "Path to LLVM root")
set(MINGW_ROOT "C:/MinGW-w64" CACHE PATH "Path to MinGW-w64 root")
set(NINJA_ROOT "C:/Ninja/latest" CACHE PATH "Path to Ninja root")

# WINDOWS SDK, VC 경로
# MSVC_ROOT는 표준 경로로 사용하기 위해 정션링크를 걸어주었다. 
# - VC2022 BuildTools 환경인 경우
#   C:\MSVC_2022_ROOT ==> {드라이브_문자}:\VisualStudio\2022\BuildTools\VC
# - VS2022 커뮤니티 환경인 경우
#   C:\MSVC_2022_ROOT ==> {드라이브_문자}:\VS2022\Community\VC
# - VS2026 커뮤니티 환경인 경우
#   C:\MSVC_2026_ROOT ==> {드라이브_문자}:\VS2026\VC

# 💡 표준 라이브러리 못찾는 빌드 오류가 발생할 경우 ...
# C:\MSVC_2026_ROOT\Tools\MSVC 경로에 가서 버전번호를 확인해준다.
# 최신 버전을 쓸 경우 Visual Studio Installer가 업데이트 중일 때는 ...
# 제대로 동작하지 않을 수 있어서, 이전 버전을 사용하는 것이 나을 수도 있다.
# 2026년 6월 13일 기준 14.51.36231가 최신이였는데, 이 버전을 쓰면 빌드 문제가 생겼다.
# 그래서 이전 버전인 14.44.35207을 사용하도록 설정했다.
set(MSVC_TOOLS_ROOT "C:/MSVC_2026_ROOT/Tools/MSVC/14.44.35207" CACHE PATH "Path to MSVC Tools Root")
set(WINSDK_LIB_ROOT "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.26100.0" CACHE PATH "Path to Windows SDK Lib Root")
set(WINSDK_INCLUDE_ROOT "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0" CACHE PATH "Path to Windows SDK Include Root")
