#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
int solution(int a, int c);

class Exam003_250132_Tests : public Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

// 기본 테스트 케이스들
TEST_F(Exam003_250132_Tests, DefaultTestCase01) {
    const int result = solution(3, 5);
    EXPECT_EQ(result, 16);
}

TEST_F(Exam003_250132_Tests, DefaultTestCase02) {
    const int result = solution(9, 10);
    EXPECT_EQ(result, 19);
}
