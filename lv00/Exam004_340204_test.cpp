#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
void solution(const string& code);

class Exam004_340204_Tests : public Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

// cspell:disable
// 기본 테스트 케이스들
TEST_F(Exam004_340204_Tests, DefaultTestCase01) {
  internal::CaptureStdout();
  solution("dry_eye");
  const string output = internal::GetCapturedStdout();

  EXPECT_EQ(output, "Ophthalmologyc");
}

TEST_F(Exam004_340204_Tests, DefaultTestCase02) {
  internal::CaptureStdout();
  solution("pat23_08_20_head");
  const string output = internal::GetCapturedStdout();

  EXPECT_EQ(output, "Neurosurgery");
}
