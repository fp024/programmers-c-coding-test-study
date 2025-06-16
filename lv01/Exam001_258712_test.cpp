#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
int solution(const vector<string> &friends, const vector<string> &gifts);

// 기본 테스트 케이스들 // cspell:disable
TEST(Exam001_258712_Tests, Default_Test_Case01) {
  const int result = solution(vector<string>{"muzi", "ryan", "frodo", "neo"},
                              vector<string>{
                                  "muzi frodo",  //
                                  "muzi frodo",
                                  "ryan muzi",  //
                                  "ryan muzi",
                                  "ryan muzi",  //
                                  "frodo muzi",
                                  "frodo ryan",  //
                                  "neo muzi"     //
                              }  //
  );
  EXPECT_EQ(result, 2);
}

TEST(Exam001_258712_Tests, Default_TestCase_02) {
  const int result =
      solution(vector<string>{"joy", "brad", "alessandro", "conan", "david"},
               vector<string>{
                   "alessandro brad",  //
                   "alessandro joy",
                   "alessandro conan",  //
                   "david alessandro",
                   "alessandro david"  //
               }  //
      );
  EXPECT_EQ(result, 4);
}

TEST(Exam001_258712_Tests, Default_TestCase_03) {
  const int result =
      solution(vector<string>{"joy", "brad", "alessandro", "conan", "david"},
               vector<string>{
                   "alessandro brad",  //
                   "alessandro joy",
                   "alessandro conan",  //
                   "david alessandro",
                   "alessandro david"  //
               }  //
      );
  EXPECT_EQ(result, 4);
}

TEST(Exam001_258712_Tests, Default_TestCase_04) {
  const int result = solution(vector<string>{"a", "b", "c"},
                              vector<string>{
                                  "a b",  //
                                  "b a",
                                  "c a",  //
                                  "a c",
                                  "a c",  //
                                  "c a"   //
                              }  //
  );
  EXPECT_EQ(result, 0);
}
