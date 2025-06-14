#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
int solution(const string &mode_type, int humidity, int val_set);

class Exam006_250127_Tests : public Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

// 기본 테스트 케이스들
TEST_F(Exam006_250127_Tests, DefaultTestCase01) {
  const int result = solution("auto", 23, 45);
  EXPECT_EQ(result, 3);
}

TEST_F(Exam006_250127_Tests, DefaultTestCase02) {
  const int result = solution("target", 41, 40);
  EXPECT_EQ(result, 1);
}

TEST_F(Exam006_250127_Tests, DefaultTestCase03) {
  const int result = solution("minimum", 10, 34);
  EXPECT_EQ(result, 1);
}

TEST_F(Exam006_250127_Tests, ExtraTestCase01) {
  const int result = solution("minimum", 34, 10);
  EXPECT_EQ(result, 0);
}
