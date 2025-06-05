#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <iostream>


using namespace std;
using namespace testing;

// 테스트할 함수 선언
int solution();

class Exam013_250133_Tests : public Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

// 기본 테스트 케이스들
TEST_F(Exam013_250133_Tests, DefaultTestCase01) {
    internal::CaptureStdout();
    solution();
    const string output = internal::GetCapturedStdout();

    // Raw String Literals (C++11부터)을 사용할 수 있는데,
    // Java의 텍스트 블록(""")은 자동으로 들여쓰기가 제거되는데, 여기선 안되서
    // 맨 앞에 공백없게 적어 줄 수 밖에 없다. 😅
    EXPECT_EQ(output,
              R"(Spring is beginning
13
310
)"
    );
}
