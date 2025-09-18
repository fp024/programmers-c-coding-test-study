#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
vector<string> solution(const vector<int>& numbers,
                        const vector<int>& our_score,
                        const vector<int>& score_list);

class Exam010_250128_Tests : public Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

// 기본 테스트 케이스들
TEST_F(Exam010_250128_Tests, DefaultTestCase01) {
  const vector<string> result =
      solution(vector{1}, vector{100}, vector{100, 80, 90, 84, 20});
  EXPECT_THAT(result, ElementsAre("Same"));
}

TEST_F(Exam010_250128_Tests, DefaultTestCase02) {
  const vector<string> result = solution(
      vector{3, 4}, vector{85, 93}, vector{85, 92, 38, 93, 48, 85, 92, 56});
  EXPECT_THAT(result, ElementsAre("Different", "Same"));
}
