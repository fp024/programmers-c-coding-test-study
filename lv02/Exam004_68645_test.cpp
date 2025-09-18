#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

/** === 💡 테스트할 함수 선언 💡 === */
// 문제 해결 함수
vector<int> solution(int n);

// 기본 테스트 케이스들
TEST(Exam004_68645_Tests, Default_TestCase_01) {
  const vector<int> result = solution(4);
  EXPECT_THAT(result, ContainerEq(  //
                          vector{
                              1,          //
                              2, 9,       //
                              3, 10, 8,   //
                              4, 5, 6, 7  //
                          }  //
                          )  //
  );
}

TEST(Exam004_68645_Tests, Default_TestCase_02) {
  const vector<int> result = solution(5);
  EXPECT_THAT(result, ContainerEq(  //
                          vector{
                              1,              //
                              2, 12,          //
                              3, 13, 11,      //
                              4, 14, 15, 10,  //
                              5, 6, 7, 8, 9   //
                          }  //
                          )  //
  );
}

TEST(Exam004_68645_Tests, Default_TestCase_03) {
  const vector<int> result = solution(6);
  EXPECT_THAT(result, ContainerEq(  //
                          vector{
                              1,                     //
                              2, 15,                 //
                              3, 16, 14,             //
                              4, 17, 21, 13,         //
                              5, 18, 19, 20, 12,     //
                              6, 7,  8,  9,  10, 11  //
                          }  //
                          )  //
  );
}

TEST(Exam004_68645_Tests, Extra_TestCase_01) {
  const vector<int> result = solution(2);
  EXPECT_THAT(result, ContainerEq(  //
                          vector{
                              1,  //
                              2,
                              3,  //
                          }  //
                          )  //
  );
}