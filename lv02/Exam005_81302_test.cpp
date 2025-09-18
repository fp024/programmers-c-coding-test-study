#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;
using namespace testing;

/** === 💡 테스트할 함수 선언 💡 === */
// 문제 해결 함수
vector<int> solution(const vector<vector<string>>& places);

// 기본 테스트 케이스들
// cspell:disable
TEST(Exam005_81302_Tests, Default_TestCase_01) {
  const vector<int> result = solution(  //
      vector<vector<string>>{
          //
          {
              "POOOP",  //
              "OXXOX",  //
              "OPXPX",  //
              "OOXOX",  //
              "POXXP"   //
          },
          {
              "POOPX",  //
              "OXPXP",  //
              "PXXXO",  //
              "OXXXO",  //
              "OOOPP"   //
          },
          {
              "PXOPX",  //
              "OXOXP",  //
              "OXPOX",  //
              "OXXOP",  //
              "PXPOX"   //
          },
          {
              "OOOXX",  //
              "XOOOX",  //
              "OOOXX",  //
              "OXOOX",  //
              "OOOOO"   //
          },
          {
              "PXPXP",  //
              "XPXPX",  //
              "PXPXP",  //
              "XPXPX",  //
              "PXPXP"   //
          }  //
      });
  EXPECT_THAT(result, ContainerEq(               //
                          vector{1, 0, 1, 1, 1}  //
                          )                      //
  );
}

TEST(Exam005_81302_Tests, Extra_TestCase_01) {
  const vector<int> result = solution(  //
      vector<vector<string>>{           //
                             {
                                 "POOOP",  //
                                 "OXXOX",  //
                                 "OPXPX",  //
                                 "OOXOX",  //
                                 "POXXP"   //
                             }});
  EXPECT_THAT(result, ContainerEq(   //
                          vector{1}  //
                          )          //
  );
}