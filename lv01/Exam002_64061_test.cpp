#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
// ✔️ 문제 해결 함수
int solution(const vector<vector<int>>& board, const vector<int>& moves);

// 기본 테스트 케이스들
TEST(Exam002_64061_Tests, Default_TestCase_01) {
  const auto board = vector<vector<int>>{{0, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 3},
                                         {0, 2, 5, 0, 1},
                                         {4, 2, 4, 4, 2},
                                         {3, 5, 1, 3, 1}};
  const vector moves = {1, 5, 3, 5, 1, 2, 1, 4};
  const int score = solution(board, moves);
  EXPECT_THAT(score, Eq(4));
}