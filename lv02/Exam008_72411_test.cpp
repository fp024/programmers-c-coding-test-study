#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
// ✔️ 문제 해결 함수
vector<string> solution(const vector<string>& orders,
                        const vector<int>& course);

vector<string> combinations(const string& menu_ids, int r);

void calc_combinations(int idx,                       //
                       const vector<char>& menu_ids,  //
                       string result,                 //
                       vector<string>& result_list,   //
                       int r                          //
);

// cspell:disable
// 기본 테스트 케이스들
TEST(Exam008_72411_Tests, Default_TestCase_01) {
  const vector<string> orders{
      "ABCFG",
      "AC",  //
      "CDE",
      "ACDE",  //
      "BCFG",
      "ACDEH"  //
  };

  const vector course{2, 3, 4};

  const vector<string> result = solution(orders, course);
  EXPECT_THAT(result,
              ContainerEq(  //
                  vector<string>{
                      "AC",
                      "ACDE",  //
                      "BCFG",
                      "CDE"  //
                  })         //
  );
}

TEST(Exam008_72411_Tests, Default_TestCase_02) {
  const vector<string> orders{
      "ABCDE",  //
      "AB",
      "CD",  //
      "ADE",
      "XYZ",  //
      "XYZ",
      "ACD"  //
  };

  const vector course{2, 3, 5};

  const vector<string> result = solution(orders, course);
  EXPECT_THAT(result,
              ContainerEq(  //
                  vector<string>{
                      "ACD",  //
                      "AD",
                      "ADE",  //
                      "CD",
                      "XYZ"  //
                  })         //
  );
}

TEST(Exam008_72411_Tests, Default_TestCase_03) {
  const vector<string> orders{
      "XYZ",  //
      "XWY",
      "WXA"  //
  };

  const vector course{2, 3, 4};

  const vector<string> result = solution(orders, course);
  EXPECT_THAT(result,
              ContainerEq(vector<string>{
                  "WX",  //
                  "XY"   //
              })         //
  );
}

TEST(Exam008_72411_Tests, Combinations_TestCase_01) {
  const vector<string> result = combinations("ABC", 2);
  EXPECT_THAT(result,
              ContainerEq(vector<string>{
                  "AB",  //
                  "AC",  //
                  "BC"   //
              })         //
  );
}

TEST(Exam008_72411_Tests, Combinations_TestCase_02) {
  const vector<string> result = combinations("ABC", 3);
  EXPECT_THAT(result,
              ContainerEq(vector<string>{
                  "ABC",  //
              })          //
  );
}

TEST(Exam008_72411_Tests, Combinations_TestCase_03) {
  const vector<string> result = combinations("ABC", 4);
  EXPECT_THAT(result, ContainerEq(vector<string>{})  //
  );
}