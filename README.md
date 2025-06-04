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
* gtest로 단위 테스트
  * [GoogleTest - Google Testing and Mocking Framework](https://github.com/google/googletest)



### gtest 테스트 (아직은 적용하지 못함. 잘 적용할 수 있을까? 😅)

> CLion 내에서는 테스트 소스 편집화면에서  ▶️ 버튼이 나타나서 그냥 그거 누르면 알아서 되는데,
>
> 명령프롬프트에서 할 때는, CMake의 bin이 Path 에 설정되어있어야한다. 
>
> 컴파일러를 LLVM+CLang을 쓰면 그것도 추가되야함.

* 프로젝트 빌드

  ```sh
  cd {프로젝트 루트}
  # 빌드 디렉토리 생성
  mkdir build
  cmake ..
  cmake --build .
  ```

  

* 전체 테스트 실행 (프로젝트 빌드가 된 상태에서)

  ```sh
  # MSVC 환경이라면 Debug 또는 Release를 선택해줄 수 있음
  ctest -C Debug
  ```

* lv00 폴더만 테스트

  ```sh
  ...
  ```

* 특정 테스트 소스 파일만 테스트

  ```sh
  ...
  ```


* 특정 테스트 소스 파일의 특정 함수만 테스트

  ```
  ...
  ```

  

