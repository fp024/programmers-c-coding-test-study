#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

extern "C" {
void solution(int arr[], int length);
}

using namespace testing;

class Exam000_00000_Tests : public Test {
 protected:
  void SetUp() override {
    // 각 테스트 전에 실행
  }

  void TearDown() override {
    // 각 테스트 후에 실행
  }
};

// 기본 정렬 테스트
TEST_F(Exam000_00000_Tests, BasicSorting) {
  int arr[] = {3, 2, 4, 1};
  constexpr int expected[] = {1, 2, 3, 4};
  constexpr int length = std::size(arr);

  solution(arr, length);

  EXPECT_THAT(arr, ElementsAreArray(expected, length));
}

// 이미 정렬된 배열 테스트
TEST_F(Exam000_00000_Tests, AlreadySorted) {
  int arr[] = {1, 2, 3, 4, 5};
  constexpr int expected[] = {1, 2, 3, 4, 5};
  constexpr int length = std::size(arr);

  solution(arr, length);

  EXPECT_THAT(arr, ElementsAreArray(expected, length));
}

// 역순 정렬된 배열 테스트
TEST_F(Exam000_00000_Tests, ReverseSorted) {
  int arr[] = {5, 4, 3, 2, 1};
  constexpr int expected[] = {1, 2, 3, 4, 5};
  constexpr int length = std::size(arr);

  solution(arr, length);

  EXPECT_THAT(arr, ElementsAreArray(expected, length));
}

// 중복 값이 있는 배열 테스트
TEST_F(Exam000_00000_Tests, DuplicateValues) {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
  constexpr int expected[] = {1, 1, 2, 3, 4, 5, 5, 6, 9};
  constexpr int length = std::size(arr);

  solution(arr, length);

  EXPECT_THAT(arr, ElementsAreArray(expected, length));
}

// 단일 원소 배열 테스트
TEST_F(Exam000_00000_Tests, SingleElement) {
  int arr[] = {42};
  constexpr int expected[] = {42};
  constexpr int length = std::size(arr);

  solution(arr, length);

  EXPECT_THAT(arr, ElementsAreArray(expected, length));
}

// 두 원소 배열 테스트
TEST_F(Exam000_00000_Tests, TwoElements) {
  int arr[] = {2, 1};
  constexpr int expected[] = {1, 2};
  constexpr int length = std::size(arr);

  solution(arr, length);

  EXPECT_THAT(arr, ElementsAreArray(expected, length));
}

// 음수가 포함된 배열 테스트
TEST_F(Exam000_00000_Tests, NegativeNumbers) {
  int arr[] = {-3, 1, -2, 5, 0};
  constexpr int expected[] = {-3, -2, 0, 1, 5};
  constexpr int length = std::size(arr);

  solution(arr, length);

  EXPECT_THAT(arr, ElementsAreArray(expected, length));
}

// 큰 배열 테스트
TEST_F(Exam000_00000_Tests, LargeArray) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
  constexpr int expected[] = {11, 12, 22, 25, 34, 42, 50, 64, 76, 88, 90};
  constexpr int length = std::size(arr);

  solution(arr, length);

  EXPECT_THAT(arr, ElementsAreArray(expected, length));
}
