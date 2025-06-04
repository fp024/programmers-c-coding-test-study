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



### 스터디 프로젝트  구성

* CMake 기반 프로젝트
  * **CMake:** 3.31.x
    * https://github.com/Kitware/CMake
  * **LLVM:** 20.1.x
    * https://github.com/llvm/llvm-project
  * **Ninja:** 1.12.x
    * https://github.com/ninja-build/ninja
* gtest로 단위 테스트
  * [GoogleTest - Google Testing and Mocking Framework](https://github.com/google/googletest)



### gtest 테스트 (아직은 적용하지 못함. 잘 적용할 수 있을까? 😅 => 적용됨 👍)

> CLion 내에서는 테스트 소스 편집화면에서  ▶️ 버튼이 나타나서 그냥 그걸 누르면 알아서 되는데,
> 명령프롬프트에서 할 때는, CMake의 bin이 Path에 설정되어 있어야한다.
> 나는 Visual Studio 2022 Community도 시스템에 설치되어있다.
>
> 그런데... 최종적으로는 LLVM+Clang 환경으로 사용하게되어서 VS2022는 사용하지 않게되었다. 😅

* 프로젝트 빌드

  ```sh
  cd {프로젝트 루트}
  # 빌드 디렉토리 생성
  mkdir build
  cmake ..
  cmake --build .
  ```
* 빌드할 때 환경을 Clang으로 컴파일러 설정
  ```sh
  cmake -G "Ninja" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ..
  ```
  현재 상태에서는 루트의 CMakeLists.txt에 Clang을 사용하도록 고정해서, 
  그냥 `cmake ..`만 입력해도 되긴함. 😅

* 전체 테스트 실행 (프로젝트 빌드가 된 상태에서)

  ```sh
  # Clang에서는 그냥 ctest로 실행
  ctest
  # MSVC 환경이라면 Debug 또는 Release를 옵션을 추가해야했다.
  ctest -C Debug
  ```

* lv00 폴더만 테스트

  ```sh
  ctest -R "lv00"
  ```

* 특정 테스트 소스 파일만 테스트

  ```sh
  ctest -R "^lv00_Exam000_00000$"
  ```


* 특정 테스트 소스 파일의 특정 테스트 메크로 함수만 테스트
  > 💡테스트 파일의 여러 테스트 함수중 특정 함수를 실행하려면 실제 테스트 실행파일을 실행해야하고,
  >
  > `--gtest_filter="*BasicSorting*"` 와 같은 방식으로 필터링 해서 실행할 수 있다.
  
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
