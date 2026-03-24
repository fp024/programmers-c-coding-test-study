# windows-clang 빌드 메모

> VS2022가 설치된 환경에 VS2026를 추가 설치한 뒤, Windows + LLVM + Ninja 조합에서 링크 오류가 발생했던 내용을 짧게 정리한다.



## 현재 동작하는 이유

현재 `windows-clang` 프리셋이 동작하는 핵심 이유는 아래와 같다.

1. **컴파일러를 `clang-cl`로 사용한다.**

   * Windows에서는 `clang`, `clang++`보다 `clang-cl`이 MSVC 스타일 빌드 환경과 더 자연스럽게 맞는다.
   * CMake도 `clang-cl`을 **MSVC-like command-line** 으로 인식해서, Windows 쪽 기본 흐름과 잘 연결된다.

2. **MSVC / Windows SDK 경로를 툴체인 파일에서 직접 넘긴다.**

   * `kernel32.lib`, `user32.lib`, `msvcrtd.lib`, `oldnames.lib` 를 못 찾는 문제는 대부분 라이브러리 검색 경로가 비어 있을 때 발생한다.
   * 현재는 `toolchains/windows-clang.cmake`에서 include 경로와 lib 경로를 직접 추가해서, 일반 터미널 환경에서도 링크에 필요한 파일을 찾을 수 있게 했다.

3. **`windows-clang` 프리셋에는 GNU 스타일 디버그 옵션을 넣지 않는다.**

   * `-gdwarf-3` 같은 옵션은 MinGW 또는 GNU 스타일 clang 쪽에는 맞지만, `clang-cl`에는 맞지 않는다.
   * `clang-cl`에서는 CMake의 Debug 기본 옵션(`/Zi`, `/Od` 등)에 맡기는 편이 더 안정적이다.

4. **CLion 설정 목적과 VS Code preset 목적을 분리한다.**

   * 예전에 넣었던 `-O0 -g -gdwarf-3` 같은 옵션은 CLion 디버깅 편의를 기대하고 넣었던 것이다.
   * 하지만 현재는 CLion에서 `CMakePresets.json`보다 자체 Toolchain / Profile 설정을 쓰는 편이 더 잘 맞으므로, VS Code용 `windows-clang` preset에는 억지로 그 요구사항을 섞지 않는다.



## 다시 깨질 때 점검할 체크리스트 5개

1. **`toolchains/default_paths.cmake` 또는 `toolchains/local_paths.cmake`의 경로가 실제 설치 경로와 일치하는지 확인**

   * 특히 아래 3가지를 먼저 본다.
     * `MSVC_TOOLS_ROOT`
     * `WINSDK_LIB_ROOT`
     * `WINSDK_INCLUDE_ROOT`
   * Visual Studio 업데이트나 Windows SDK 버전 변경 후에는 폴더명이 바뀌는 경우가 많다.

2. **`windows-clang`이 여전히 `clang-cl.exe`를 사용하고 있는지 확인**

   * `clang.exe`, `clang++.exe`로 다시 바뀌면 Windows 링크 환경에서 다시 흔들릴 수 있다.
   * CMake 출력에서 `Clang ... with MSVC-like command-line`로 인식되는지 보면 빠르게 판단할 수 있다.

3. **링크 에러 메시지 종류를 보고 빠진 경로를 구분**

   * `kernel32.lib`, `user32.lib`, `advapi32.lib` 등이 안 보이면 Windows SDK lib 경로 문제일 가능성이 크다.
   * `msvcrtd.lib`, `oldnames.lib` 가 안 보이면 MSVC CRT lib 경로 문제일 가능성이 크다.
   * 둘 다 동시에 안 보이면 툴체인 경로 설정 전체가 깨졌다고 보면 된다.

4. **기존 빌드 캐시를 지우고 다시 configure**

   * 컴파일러, linker flag, SDK 경로 관련 값은 CMake 캐시에 남아서 원인을 헷갈리게 만든다.
   * 문제가 생기면 먼저 `build/windows-clang` 을 지우고 다시 configure 하는 것이 빠르다.

5. **Visual Studio Installer에서 C++ 워크로드와 Windows SDK 설치 상태 확인**

   * `Desktop development with C++`
   * MSVC toolset
   * Windows 10/11 SDK
   위 항목 중 하나라도 빠져 있으면 경로를 맞춰도 필요한 라이브러리 자체가 없을 수 있다.



## 메모

* VS Code의 `windows-clang` preset은 **Windows에서 안정적으로 빌드되는 것**을 우선으로 둔다.
* CLion에서의 디버깅 편의 옵션은 CLion 자체 툴체인 설정으로 따로 가져가는 편이 낫다.
* 같은 문제가 다시 생기면 **CMake 버전보다 먼저 경로와 SDK 설치 상태를 의심**하는 것이 맞다.