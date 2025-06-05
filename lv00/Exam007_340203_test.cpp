#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <sstream>
#include <iostream>


using namespace std;
using namespace testing;

// 테스트할 함수 선언
vector<int> solution(const vector<string> &cpr);

class Exam007_340203_Tests : public Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

// 기본 테스트 케이스들
TEST_F(Exam007_340203_Tests, DefaultTestCase01) {
    const vector<string> cpr = {"call", "respiration", "repeat", "check", "pressure"};
    const vector<int> result = solution(cpr);
    EXPECT_THAT(result, ElementsAre(2, 4, 5, 1, 3));
}

TEST_F(Exam007_340203_Tests, DefaultTestCase02) {
    const vector<string> cpr = {"respiration", "repeat", "check", "pressure", "call"};
    const vector<int> result = solution(cpr);
    EXPECT_THAT(result, ElementsAre(4, 5, 1, 3, 2));
}
