# C++ `std::string_view` vs `const std::string&`

최근 코딩 테스트 문제 풀이(`Exam008_72411.cpp`)를 진행하며, 문자열을 파라미터로 받는 방식을 `const std::string&`에서 `std::string_view`로 변경했습니다. 이 문서에서는 두 방식의 차이점과 `string_view`를 사용하는 이유, 그리고 올바른 사용법에 대해 정리합니다.

## 1. `std::string_view`란?

C++17부터 도입된 `std::string_view`는 문자열을 **"소유"하지 않고 "관찰"만 하는** 가벼운 객체입니다. 내부적으로 다음과 같이 단 두 가지 정보만 가집니다.

1.  **문자열의 시작 주소 (`const char*`)**
2.  **문자열의 길이 (`size_t`)**

즉, `string_view`는 문자열의 원본이 `std::string`이든, C 스타일의 문자열 리터럴(`"text"`)이든 상관없이 **"저 메모리 위치에서 N개의 문자"**라는 정보만 저장하는 일종의 **꼬리표(Tag)** 역할을 합니다.

## 2. 왜 `const std::string&` 대신 사용하는가?

### A. 불필요한 임시 객체 생성 방지 (성능)

`const std::string&`는 `std::string` 객체의 참조를 받습니다. 만약 이 함수에 `"Hello"`와 같은 **문자열 리터럴**을 전달하면 어떤 일이 벌어질까요?

```cpp
void func(const std::string& str);

func("Hello");
// 1. "Hello"를 담기 위해 힙 메모리를 할당하여 임시 std::string 객체 생성
// 2. 그 객체의 참조를 func에 전달
// 3. 함수 종료 후 임시 객체 소멸 (메모리 해제)
```

매번 힙 메모리 할당(Allocation)과 복사(Copy), 해제(Deallocation)가 발생합니다.

반면, `std::string_view`는:

```cpp
void func(std::string_view sv);

func("Hello");
// 1. "Hello"의 주소와 길이(5)만 sv에 저장
// 2. 메모리 할당 전혀 없음
```

### B. 더 넓은 범용성

- `std::string` 객체
- C-Style 문자열 (`char*`, `"literals"`)
- 다른 `string_view`

이 모든 것을 효율적으로 받아들일 수 있습니다.

## 3. 올바른 사용법: "값(Value)"으로 전달하라

가장 중요한 점은 **`string_view`를 전달할 때 참조(`const string_view&`)가 아닌 값(`string_view`)으로 전달해야 한다**는 것입니다.

### 왜 값으로 전달하는가?

`string_view`의 크기는 포인터 하나와 정수 하나(64bit 시스템 기준 16바이트)로 매우 작습니다. 이를 참조(`&`)로 전달하면 간접 참조(Indirection) 비용이 발생하여, 레지스터에 값을 바로 담아 전달하는 "값 전달" 방식보다 오히려 느릴 수 있습니다. `int`를 `const int&`로 전달하지 않는 것과 같은 이치입니다.

### 코드 예시

**❌ 비권장 (기존 방식 or 잘못된 사용)**

```cpp
// 문자열 리터럴 전달 시 임시 객체 생성됨
void processString(const std::string& str) { ... }

// 참조로 전달할 필요가 없음 (너무 작음)
void processString(const std::string_view& sv) { ... }
```

**✅ 권장 (Modern C++)**

```cpp
// 읽기 전용 문자열 파라미터는 string_view를 값으로 받는다.
void processString(std::string_view sv) {
    if (sv.empty()) return;
    // ...
}
```

## 4. 요약

| 구분                      | `const std::string&`                    | `std::string_view`                   |
| :------------------------ | :-------------------------------------- | :----------------------------------- |
| **소유권**                | 문자열을 소유한 객체의 참조             | 소유하지 않음 (View)                 |
| **문자열 리터럴 전달 시** | 임시 `std::string` 생성 (메모리 할당 O) | 포인터와 길이만 복사 (메모리 할당 X) |
| **전달 방식**             | 참조 (`const &`) 권장                   | **값 (Value)** 권장                  |
| **수정 가능 여부**        | 불가능 (`const`)                        | 불가능 (읽기 전용)                   |
| **도입 버전**             | C++98                                   | **C++17**                            |

앞으로 **"문자열을 읽기만 하는 함수"**를 작성할 때는 `std::string_view`를 적극적으로 활용합니다.
