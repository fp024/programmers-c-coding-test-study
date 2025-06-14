#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
int solution(int storage, int usage, const vector<int> &change);

class Exam015_340202_Tests : public Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

// 기본 테스트 케이스들
TEST_F(Exam015_340202_Tests, DefaultTestCase01) {
  const int result =
      solution(5141,  //
               500,   //
               vector{10, -10, 10, -10, 10, -10, 10, -10, 10, -10});
  EXPECT_EQ(result, -1);
}

TEST_F(Exam015_340202_Tests, DefaultTestCase02) {
  const int result = solution(1000,  //
                              2000,  //
                              vector{-10, 25, -33});
  EXPECT_EQ(result, 0);  // 💡입출력 예가 나온 테이블에서는 기대값이 1로
                         // 잘못나와있음. 😅 0이 맞음.
}
