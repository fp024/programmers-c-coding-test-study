#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
string solution(const string &nickname);

class Exam009_340200_Tests : public Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

// 기본 테스트 케이스들
TEST_F(Exam009_340200_Tests, DefaultTestCase01) {
  const string result = solution("WORLDworld");
  EXPECT_EQ(result, "VV0RLDvv");
}

TEST_F(Exam009_340200_Tests, DefaultTestCase02) {
  const string result = solution("GO");
  EXPECT_EQ(result, "G0oo");
}
