# Git-Bash 터미널 환경변수 설정

> VSCode에서 터미널로 Git-Bash를 사용할 경우 settings.json에서 터미널 환경변수를 지정할 수 없어서,
>
> ~/.bashrc에 직접 지정해야한다.
>
> SDKMAN!과 연동이 될 수 있으면 그걸 사용하면 좋겠지만... 아쉽게도 C/C++ 관련 툴들은 지원을 안한다.



### ~/.bashrc 에 다음과 같이 설정

```bash
# CMake, LLVM/Clang, Ninja, MinGW-w64 환경 변수 설정
export CMAKE_VERSION=3.x
export LLVM_CLANG_VERSION=20.x
export NINJA_VERSION=1.12.x

# MinGW-w64는 버전 관리하지 않고 경로만 지정
export MINGW_W64_HOME=/c/MinGW-w64

export CMAKE_HOME=/c/CMake/$CMAKE_VERSION
export LLVM_CLANG_HOME=/c/LLVM/$LLVM_CLANG_VERSION
export NINJA_HOME=/c/Ninja/$NINJA_VERSION

export PATH="$CMAKE_HOME/bin:$LLVM_CLANG_HOME/bin:$MINGW_W64_HOME/bin:$NINJA_HOME:$PATH"
```

