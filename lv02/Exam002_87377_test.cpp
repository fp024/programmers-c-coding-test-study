#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;
using namespace testing;

/** === 💡 테스트할 함수 선언 💡 === */
// 문제 해결 함수
vector<string> solution(const vector<vector<int>> &line);

// 기본 테스트 케이스들
TEST(Exam002_87377_Tests, Default_TestCase_01) {
  const vector<string> result = solution(  //
      vector<vector<int>>{
          {2, -1, 4},
          {-2, -1, 4},
          {0, -1, 1},  //
          {5, -8, -12},
          {5, 8, 12}  //
      }

  );
  EXPECT_THAT(result,
              ElementsAre("....*....",  //
                          ".........",
                          ".........",  //
                          "*.......*",
                          ".........",  //
                          ".........",
                          ".........",  //
                          ".........",
                          "*.......*"  //
                          ));
}

TEST(Exam002_87377_Tests, Default_TestCase_02) {
  const vector<string> result = solution(  //
      vector<vector<int>>{
          {0, 1, -1},  //
          {1, 0, -1},
          {1, 0, 1}  //
      }

  );
  EXPECT_THAT(result, ElementsAre("*.*"));
}

TEST(Exam002_87377_Tests, Default_TestCase_03) {
  const vector<string> result = solution(  //
      vector<vector<int>>{
          {1, -1, 0},  //
          {2, -1, 0}   //
      }

  );
  EXPECT_THAT(result, ElementsAre("*"));
}

TEST(Exam002_87377_Tests, Default_TestCase_04) {
  const vector<string> result = solution(  //
      vector<vector<int>>{
          {1, -1, 0},  //
          {2, -1, 0},
          {4, -1, 0}  //
      }

  );
  EXPECT_THAT(result, ElementsAre("*"));
}