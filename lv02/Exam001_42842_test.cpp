#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

using namespace std;
using namespace testing;

/** === 💡 테스트할 함수 선언 💡 === */
// 문제 해결 함수
vector<int> solution(int brown, int yellow);

// 약수 쌍을 구하는 헬퍼 함수 선언
vector<pair<int, int> > getDivisorPairs(int n);

// 기본 테스트 케이스들
TEST(Exam067_42842_Tests, Default_TestCase_01) {
  const vector<int> result = solution(10, 2);
  EXPECT_THAT(result, ElementsAre(4, 3));
}

TEST(Exam067_42842_Tests, Default_TestCase_02) {
  const vector<int> result = solution(8, 1);
  EXPECT_THAT(result, ElementsAre(3, 3));
}

TEST(Exam067_42842_Tests, Default_TestCase_03) {
  const vector<int> result = solution(24, 24);
  EXPECT_THAT(result, ElementsAre(8, 6));
}

// 약수 쌍 함수 테스트
TEST(Exam067_42842_Tests, GetDivisorPairs_TestCase_01) {
  const vector<pair<int, int> > result = getDivisorPairs(24);
  const vector<pair<int, int> > expected = {{24, 1}, {12, 2}, {8, 3}, {6, 4}};
  EXPECT_THAT(result, ContainerEq(expected));
}
