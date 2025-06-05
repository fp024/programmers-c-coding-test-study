#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
int solution(int start, int before, int after);

class Exam002_250130_Tests : public Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

// 기본 테스트 케이스들
TEST_F(Exam002_250130_Tests, DefaultTestCase01) {
    const int result = solution(28, 6, 8);
    EXPECT_EQ(result, 12);
}

TEST_F(Exam002_250130_Tests, DefaultTestCase02) {
    const int result = solution(75, 8, 25);
    EXPECT_EQ(result, 2);
}
