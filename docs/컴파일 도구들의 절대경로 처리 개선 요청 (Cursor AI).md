# 컴파일 도구들의 절대경로 처리 개선 요청 (Cursor AI)

> Cursor Editor 설치한 김에... 한번 부탁을 해보았다. 😅
>
> 아마도 CLINE에게 부탁을 했어도 가능은 했을 것 같지만, 무료 API 키를 사용하고 있어서, 느렸을 것 같고.
>
> AI가 통합된 완제품이고, Pro 체험판 기간이라 그런지 Cursor의 처리 속도가 빠른 느낌이다. 👍



## 나:

안녕~ 한가지 부탁을 해볼께....

`common_paths.cmake`에 내용들이 절대경로로 설정이 정의되어있잖아..

그런데.. 경로들을 정의한 부분은 다른 컴퓨터에서 사용할 때, 경로가 달라서 바뀔 수도 있잖아.
그래서 이 파일을 수정할 수 밖에 없는 문제가 있어..

그런데 이부분이 git에 올라간 파일이라서 여러 컴퓨터에서 직접 수정이 되면 귀찮을 수 있을 것 같아.


개선방법으로는...

`common_paths.cmake`가   `local_paths.cmake`와  `default_paths.cmake`를  조건 부로 읽게 하는데...

1. `local_path.cmake`가 없으면 `default_path.cmake`를 읽게하도록함.
2. `local_path.cmake`는 git에 추가하지 않는 파일

위처럼 해서  다른 컴퓨터에서 쓸 때는 사용자가 `local_path.cmake` 파일을 `defualt_path.cmake` 파일을 참조 및 복사해서 만들어서, 자신 만의 경로를 넣을 수 있게 개선하면 좋을 것 같아.



---

## Cursor:

아주 좋은 개선 아이디어입니다!  
이런 방식은 **로컬 환경별 경로 설정**을 깔끔하게 분리하고,  
git 충돌/불편 없이 여러 개발자가 각자 환경에 맞게 쓸 수 있게 해줍니다.

---

## 개선 설계

1. **toolchains/common_paths.cmake**  
   - 더 이상 직접 경로를 정의하지 않고,
   - `local_paths.cmake`가 있으면 그걸 include,  
     없으면 `default_paths.cmake`를 include.

2. **toolchains/default_paths.cmake**  
   - 기본(샘플) 경로를 정의.
   - git에 커밋.

3. **toolchains/local_paths.cmake**  
   - 각자 환경에 맞는 경로를 정의.
   - git에 **추가하지 않음** (`.gitignore`에 등록).

---

## 예시 코드

### 1. `toolchains/common_paths.cmake`
```cmake
# 공통 컴파일러 및 도구 경로 설정 (절대 경로)
if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/local_paths.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/local_paths.cmake")
else()
    include("${CMAKE_CURRENT_LIST_DIR}/default_paths.cmake")
endif()
```

### 2. `toolchains/default_paths.cmake`
```cmake
# 기본 경로 (샘플)
set(LLVM_ROOT "C:/LLVM/20.x" CACHE PATH "Path to LLVM root")
set(MINGW_ROOT "C:/MinGW-w64" CACHE PATH "Path to MinGW-w64 root")
set(NINJA_ROOT "C:/Ninja/latest" CACHE PATH "Path to Ninja root")
set(VS2022_TOOLS_ROOT "C:/VS2022/VC_TOOLS_X64_LINK" CACHE PATH "Path to VS2022 VC Tools")
```

### 3. `toolchains/local_paths.cmake`
```cmake
# (예시) 각자 환경에 맞게 수정
set(LLVM_ROOT "D:/MyLLVM" CACHE PATH "Path to LLVM root")
set(MINGW_ROOT "D:/DevTools/MinGW" CACHE PATH "Path to MinGW-w64 root")
set(NINJA_ROOT "D:/DevTools/Ninja" CACHE PATH "Path to Ninja root")
set(VS2022_TOOLS_ROOT "D:/VS2022/VC_TOOLS_X64_LINK" CACHE PATH "Path to VS2022 VC Tools")
```

### 4. `.gitignore`에 추가
```
toolchains/local_paths.cmake
```

---

## 적용 방법

1. **default_paths.cmake**를 만들고,  
   기존의 경로 정의를 이 파일로 옮깁니다.
2. **common_paths.cmake**를 위와 같이 수정합니다.
3. **local_paths.cmake**는 각자 필요할 때 복사/수정해서 사용합니다.
4. **.gitignore**에 local_paths.cmake를 추가합니다.

---

## 장점

- **git 충돌/불편 없음**: 각자 환경 설정은 git에 올라가지 않음.
- **온보딩 쉬움**: 새 개발자는 default_paths.cmake를 복사해서 local_paths.cmake로 만들면 됨.
- **유지보수 편리**: 기본값은 항상 default_paths.cmake에서 관리.

---
