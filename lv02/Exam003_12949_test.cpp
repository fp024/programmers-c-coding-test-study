#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;
using namespace testing;

/** === 💡 테스트할 함수 선언 💡 === */
// 문제 해결 함수
vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2);

// 기본 테스트 케이스들
TEST(Exam003_12949_Tests, Default_TestCase_01) {
  const vector<vector<int>> result = solution(
      vector<vector<int>>{
          //
          {1, 4},
          {3, 2},
          {4, 1}  //
      },
      vector<vector<int>>{
          //
          {3, 3},
          {3, 3}  //
      }  //
  );
  EXPECT_THAT(result, ContainerEq(  //
                          vector<vector<int>>{
                              //
                              {15, 15},
                              {15, 15},
                              {15, 15}  //
                          }  //
                          )  //
  );
}

TEST(Exam003_12949_Tests, Default_TestCase_02) {
  const vector<vector<int>> result = solution(
      vector<vector<int>>{
          //
          {2, 3, 2},
          {4, 2, 4},
          {3, 1, 4}  //
      },
      vector<vector<int>>{
          //
          {5, 4, 3},
          {2, 4, 1},
          {3, 1, 1}  //
      }  //
  );
  EXPECT_THAT(result, ContainerEq(  //
                          vector<vector<int>>{
                              //
                              {22, 22, 11},
                              {36, 28, 18},
                              {29, 20, 14}  //
                          }  //
                          )  //
  );
}