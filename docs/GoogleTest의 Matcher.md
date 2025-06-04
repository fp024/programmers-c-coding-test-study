# GoogleTest의 Matcher

### 다양한 Vector Matcher

> 💡마치 Hamcrest 쓰는 것 같은 느낌이다. 👍

```cpp
// 정확한 순서와 값 비교
EXPECT_THAT(result, ElementsAre(0, 1));

// 순서 상관없이 요소들 포함 확인  
EXPECT_THAT(result, UnorderedElementsAre(1, 0));

// 특정 요소들이 포함되어 있는지
EXPECT_THAT(result, Contains(0));
EXPECT_THAT(result, Contains(1));

// 크기 확인
EXPECT_THAT(result, SizeIs(2));

// 빈 벡터 확인
EXPECT_THAT(result, IsEmpty());

// 복합 조건
EXPECT_THAT(result, AllOf(SizeIs(2), ElementsAre(0, 1)));
```

