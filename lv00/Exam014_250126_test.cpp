#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
string solution(const vector<string>& storage, const vector<int>& num);

class Exam014_250126_Tests : public Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

// 기본 테스트 케이스들
TEST_F(Exam014_250126_Tests, DefaultTestCase01) {
  const string result = solution(
      vector<string>{"pencil", "pencil", "pencil", "book"}, vector{2, 4, 3, 1});
  EXPECT_EQ(result, "pencil");
}

TEST_F(Exam014_250126_Tests, DefaultTestCase02) {
  const string result = solution(vector<string>{"doll", "doll", "doll", "doll"},
                                 vector{1, 1, 1, 1});
  EXPECT_EQ(result, "doll");
}

TEST_F(Exam014_250126_Tests, DefaultTestCase03) {
  const string result =
      solution(vector<string>{"apple", "steel", "leaf", "apple", "leaf"},
               vector{5, 3, 5, 3, 7});
  EXPECT_EQ(result, "leaf");
}

TEST_F(Exam014_250126_Tests, DefaultTestCase04) {
  const string result =
      solution(vector<string>{"mirror", "net", "mirror", "net", "bottle"},
               vector{4, 1, 4, 1, 5});
  EXPECT_EQ(result, "mirror");
}
