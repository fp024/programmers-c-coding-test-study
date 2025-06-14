#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <iostream>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
int solution();

class Exam012_340207_Tests : public Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

// 기본 테스트 케이스들
TEST_F(Exam012_340207_Tests, DefaultTestCase01) {
  internal::CaptureStdout();
  solution();
  const string output = internal::GetCapturedStdout();

  EXPECT_EQ(output, "3\n2\n1\nLet's go!\n");
}
