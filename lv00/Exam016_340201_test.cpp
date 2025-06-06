#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
int solution(int seat, const vector<vector<string> > &passengers);

class Exam016_340201_Tests : public Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

// 기본 테스트 케이스들
TEST_F(Exam016_340201_Tests, DefaultTestCase01) {
    const int result = solution(
        5,
        vector<vector<string> >{
            {"On", "On", "On"}, //
            {"Off", "On", "-"},
            {"Off", "-", "-"}
        }
    );
    EXPECT_EQ(result, 3);
}


// 기본 테스트 케이스들
TEST_F(Exam016_340201_Tests, DefaultTestCase02) {
    const int result = solution(
        10,
        vector<vector<string> >{
            {"On", "On", "On", "On", "On", "On", "On", "On", "-", "-"}, //
            {"On", "On", "Off", "Off", "Off", "On", "On", "-", "-", "-"},
            {"On", "On", "On", "Off", "On", "On", "On", "Off", "Off", "Off"},
            {"On", "On", "Off", "-", "-", "-", "-", "-", "-", "-"}
        }
    );
    EXPECT_EQ(result, 0);
}
