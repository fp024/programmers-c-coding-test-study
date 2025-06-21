#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
// ✔️ 문제 해결 함수
vector<int> solution(const vector<int> &answers);

// ✔️ 답변과 패턴으로 점수 계산
int calc_score(const vector<int> &answer, const vector<int> &pattern);

TEST(Exam006_42840_Tests, Extra_TestCase_calc_score_01) {
  const vector answers = {1, 2, 3, 4, 5, 1, 2, 3, 9, 10, 1};
  const vector pattern = {1, 2, 3, 4, 5};
  const int score = calc_score(answers, pattern);
  EXPECT_THAT(score, Eq(9));
}

// 기본 테스트 케이스들
TEST(Exam006_42840_Tests, Default_TestCase_01) {
  const vector answers = {1, 2, 3, 4, 5};
  const vector<int> result = solution(answers);
  EXPECT_THAT(result, ContainerEq(   //
                          vector{1}  //
                          )          //
  );
}

TEST(Exam006_42840_Tests, Default_TestCase_02) {
  const vector answers = {1, 3, 2, 4, 2};
  const vector<int> result = solution(answers);
  EXPECT_THAT(result, ContainerEq(         //
                          vector{1, 2, 3}  //
                          )                //
  );
}
