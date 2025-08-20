#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
// ✔️ 문제 해결 함수
vector<int> solution(const vector<string> &genres, const vector<int> &plays);

// 기본 테스트 케이스들
TEST(Exam001_42579_Tests, Default_TestCase_01) {
  const vector<string> genres{
      "classic",  //
      "pop",
      "classic",  //
      "classic",
      "pop"  //
  };

  const vector plays{
      500,  //
      600,
      150,  //
      800,
      2500  //
  };

  const vector<int> result = solution(genres, plays);
  EXPECT_THAT(result,
              ContainerEq(  //
                  vector{4, 1, 3, 0}));
}

TEST(Exam001_42579_Tests, Default_TestCase_02) {
  const vector<string> genres{
      "classic",  //
      "pop",
      "classic",  //
      "pop",
      "classic",  //
      "classic"   //
  };

  const vector plays{
      400,  //
      600,
      150,  //
      2500,
      500,  //
      500   //
  };

  const vector<int> result = solution(genres, plays);
  EXPECT_THAT(result,
              ContainerEq(  //
                  vector{3, 1, 4, 5}));
}
