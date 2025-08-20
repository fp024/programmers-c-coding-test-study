#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
// ✔️ 문제 해결 함수
vector<string> solution(const vector<string> &record);

// 기본 테스트 케이스들
TEST(Exam007_42888_Tests, Default_TestCase_01) {
  const vector<string> record{
      "Enter uid1234 Muzi",  //
      "Enter uid4567 Prodo",
      "Leave uid1234",  //
      "Enter uid1234 Prodo",
      "Change uid4567 Ryan"  //
  };

  const vector<string> result = solution(record);
  EXPECT_THAT(result,
              ContainerEq(  //
                  vector<string>{
                      "Prodo님이 들어왔습니다.",
                      "Ryan님이 들어왔습니다.",  //
                      "Prodo님이 나갔습니다.",
                      "Prodo님이 들어왔습니다."  //
                  }));
}
