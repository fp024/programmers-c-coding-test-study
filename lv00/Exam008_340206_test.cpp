#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
int solution();

class Exam008_340206_Tests : public Test {
 protected:
  std::streambuf* orig_cin = nullptr;

  void SetUp() override {
    orig_cin = std::cin.rdbuf();  // 원래 stdin 저장
  }

  void TearDown() override {
    std::cin.rdbuf(orig_cin);  // 원래 stdin 복원
  }

  static void setInput(const string& input) {
    static std::istringstream input_stream;
    input_stream.str(input);
    input_stream.clear();
    std::cin.rdbuf(input_stream.rdbuf());  // 가짜 stdin으로 대체
  }
};

// 기본 테스트 케이스들
TEST_F(Exam008_340206_Tests, DefaultTestCase01) {
  setInput("280\n485\n");  // 예시 입력

  internal::CaptureStdout();
  solution();
  const string output = internal::GetCapturedStdout();

  EXPECT_EQ(output, "45\n");
}
