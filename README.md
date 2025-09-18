# 프로그래머스 C/C++ 코딩 테스트 - 스터디

> 코딩 테스트 연습을 JS/TS와 Java 환경에서 하고 있었는데, C/C++로 해봐도 재밌을 것 같아서 프로젝트를 만들었다.
>
> * JS/TS
>   * https://github.com/fp024/programmers-js-coding-test-study
>
> * Java
>   * https://github.com/fp024/programmers-java-coding-test-study
>
>
> Visual Studio 프로젝트로 만들기보다는 여러 플렛폼에도 가능하게 하기 위해 CMake로 해보기로 하자!
>



## 스터디 프로젝트  구성

### CMake 기반 프로젝트

* **CMake:** 3.31.x
  * https://github.com/Kitware/CMake
* **LLVM:** 20.1.x
  * https://github.com/llvm/llvm-project
* **Ninja:** 1.12.x
  * https://github.com/ninja-build/ninja



### 개발 도구

* **CLion**
  * https://www.jetbrains.com/clion/
  * **Free for non-commercial use** : 요즘은 CLion도 비상업적용도로는 무료로 사용할 수 있다. 👍
  * ⚠️ 사전에 [CMakePresets.json](./CMakePresets.json)에 정의한 clang, mingw 프리셋 대신, CLion의 기본 툴체인을 써야지만 디버깅할 때 STL 컨테이너의 데이터를 보는데 문제가 없었다. 😂 
    아마도 프리셋에 연결된 디버깅 도구(LLDB, GDB)들의 버전이 최신이고 CLion에 호환되지 않아 그럴 수도 있겠다.😅

* **VSCode**
  * [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)과 [C++ TestMate](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter)만 설치해도 괜찮게 쓸 수 있었다. 👍
    * 💡 VSCode에서는 사전에 [CMakePresets.json](./CMakePresets.json)에 정의한 clang, mingw 프리셋 환경을 사용해도 디버깅할 때, STL 컨테이너의 데이터를 보는데 문제가 없었다. 😊👍

* **Visual Studio 2022 Community**
  * https://visualstudio.microsoft.com/ko/vs/community/
  * 근데 이 프로그램은 왠지 모르게 사용을 안하게됨 😅, 익숙하지 않아서 그렇기도 하지만..😅



### 단위 테스트 프레임워크

* GoogleTest - Google Testing and Mocking Framework
  * https://github.com/google/googletest





## gtest 테스트

> CLion 내에서는 테스트 소스 편집화면에서  ▶️ 버튼이 나타나서 그냥 그걸 누르면 알아서 되는데,
> 명령프롬프트에서 빌드를 실행할 때, clang-cl을 사용하거나 clang, clang++을 사용하려면, 
>
> CMake, LLVM의 bin 및 Ninja 실행파일 경로가 Path에 설정되어 있어야한다.
>
> 나는 Visual Studio 2022 Community도 시스템에 설치 되어있다.
>
> 
>
> 💡아래 내용은 명령 프롬프트에서 확인해보고 싶을 때, 시도해보면 좋음
>
> * Visual Studio 2022에서는 F5나 F7로 한번 빌드를 해줘야 Test Explorer에서 나타난다. 😅
> * 테스트 매크로 바로 옆에 실행 버튼▶️ 나오는 CLion이 사용하기에는 좀 더 편한듯..👍
>   * VS2022에서도 테스트 매크로 옆에 오른쪽 마우스 메뉴 열면 Run Tests라고 뜨긴함 😅

* 프로젝트 설정 / 빌드 / 테스트

  * **preset**은 `windows-clang`,  `mingw` 두가지를 설정해 두었다. ([CMakePresets.json](CMakePresets.json))
  
  ```sh
  cd {프로젝트 루트}
  # 빌드 설정
  cmake --preset windows-clang # 또는 mingw
  # 빌드 
  cmake --build --preset windows-clang # 또는 mingw
  # 테스트
  ctest --preset windows-clang # 또는 mingw
  ```
  
* lv00만 테스트

  ```sh
  ctest --preset windows-clang -R "lv00"
  ```

* 특정 테스트 문제만 테스트

  ```sh
  ctest --preset windows-clang -R "^lv00_Exam000_00000_test$"
  ```


* 특정 테스트 문제 파일 내 특정 테스트 케이스만 실행
  > 💡테스트 파일의 여러 테스트 매크로 중 특정 테스트 매크로를 실행하려면 실제 테스트 실행파일을 실행해야하고,
  >
  > `--gtest_filter="*테스트_이름*"` 와 같은 방식으로 필터링 해서 실행할 수 있다.
  
  ```
  C:\git\programmers-c-coding-test-study\build>lv00\lv00_Exam000_00000_test.exe  --gtest_filter="*BasicSorting*"
  Running main() from C:/git/programmers-c-coding-test-study/build/_deps/googletest-src/googletest/src/gtest_main.cc
  Note: Google Test filter = *BasicSorting*
  [==========] Running 1 test from 1 test suite.
  [----------] Global test environment set-up.
  [----------] 1 test from Exam000_00000_Tests
  [ RUN      ] Exam000_00000_Tests.BasicSorting
  2, 3, 4, 1
  2, 3, 4, 1
  2, 3, 1, 4
  2, 3, 1, 4
  2, 1, 3, 4
  1, 2, 3, 4
  [       OK ] Exam000_00000_Tests.BasicSorting (0 ms)
  [----------] 1 test from Exam000_00000_Tests (1 ms total)
  
  [----------] Global test environment tear-down
  [==========] 1 test from 1 test suite ran. (2 ms total)
  [  PASSED  ] 1 test.
  
  C:\git\programmers-c-coding-test-study\build>
  ```



## 코드 포멧팅 (clang-format)

VSCode 설정도 이미 settings.json에 해두었지만, 프로젝트 루트에 전체 포멧팅을 하는 배치 파일을 추가했다.

* 배치 파일: [run-clang-format.bat](run-clang-format.bat)
* 설정 파일: [settings.properties](settings.properties)

```bash
# 전체 코드 포멧팅 수행 (대상 디렉토리는 settings.profiles에 설정되어있음)
run-clang-format.bat

# 특정 디렉토리 코드 포멧팅
run-clang-format.bat lv01 lv02

# 검사 모드
run-clang-format.bat --check

# 특정 디렉토리 검사
run-clang-format.bat --check lv01 lv02
```

