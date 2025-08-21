#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
// ✔️ 문제 해결 함수
vector<int> solution(const vector<string>& id_list,
                     const vector<string>& report, int k);

//=============================================
// 💡 파라미터화하지 않고 테스트 함수를 개별적으로 사용
//=============================================
TEST(Exam003_92334_Tests, Default_TestCase_01) {
  const vector<string> id_list{
      "muzi",
      "frodo",  //
      "apeach",
      "neo"  //
  };

  const vector<string> report{
      "muzi frodo",  //
      "apeach frodo",
      "frodo neo",  //
      "muzi neo",
      "apeach muzi"  //
  };

  constexpr int k = 2;

  const vector<int> result = solution(id_list, report, k);
  EXPECT_THAT(result,
              ContainerEq(  //
                  vector{2, 1, 1, 0}));
}

TEST(Exam003_92334_Tests, Default_TestCase_02) {
  const vector<string> id_list{
      "con",
      "ryan"  //
  };

  const vector<string> report{
      "ryan con",
      "ryan con",  //
      "ryan con",
      "ryan con"  //
  };

  constexpr int k = 3;

  const vector<int> result = solution(id_list, report, k);
  EXPECT_THAT(result,
              ContainerEq(  //
                  vector{0, 0}));
}

//===========================================
// 💡 다음은 튜플을 사용한 Parametrize Tests 예제
//===========================================

using TestParams = tuple<vector<string>, vector<string>, int, vector<int>>;

class Exam003_92334_SimpleTests : public TestWithParam<TestParams> {};

TEST_P(Exam003_92334_SimpleTests, SolutionTest) {
  auto& [id_list, report, k, expected] = GetParam();  // C++17 구조화된 바인딩

  const vector<int> result = solution(id_list, report, k);
  EXPECT_THAT(result, ContainerEq(expected));
}

INSTANTIATE_TEST_SUITE_P(
    SimpleTestCases, Exam003_92334_SimpleTests,
    Values(make_tuple(vector<string>{"muzi", "frodo", "apeach", "neo"},
                      vector<string>{"muzi frodo", "apeach frodo", "frodo neo",
                                     "muzi neo", "apeach muzi"},
                      2, vector<int>{2, 1, 1, 0}),
           make_tuple(vector<string>{"con", "ryan"},
                      vector<string>{"ryan con", "ryan con", "ryan con",
                                     "ryan con"},
                      3, vector<int>{0, 0})));

//===========================================================
// 💡 다음은 튜플 대신 데이터 구조체를 사용한 Parametrize Tests 예제
//===========================================================

// 테스트 데이터 구조체
struct TestData {
  string test_name;
  vector<string> id_list;
  vector<string> report;
  int k;
  vector<int> expected;
};

// 매개변수화된 테스트 클래스
class Exam003_92334_ParametrizedTests : public TestWithParam<TestData> {};

// 매개변수화된 테스트 케이스
TEST_P(Exam003_92334_ParametrizedTests, SolutionTest) {
  const TestData& data = GetParam();

  const vector<int> result = solution(data.id_list, data.report, data.k);
  EXPECT_THAT(result, ContainerEq(data.expected));
}

// 테스트 데이터 정의
INSTANTIATE_TEST_SUITE_P(AllTestCases,  // 테스트 스위트 이름
                         Exam003_92334_ParametrizedTests,
                         Values(
                             TestData{
                                 "DefaultTestCase01",
                                 {
                                     "muzi",
                                     "frodo",  //
                                     "apeach",
                                     "neo"  //
                                 },
                                 {
                                     "muzi frodo",  //
                                     "apeach frodo",
                                     "frodo neo",  //
                                     "muzi neo",
                                     "apeach muzi"  //
                                 },
                                 2,            //
                                 {2, 1, 1, 0}  //
                             },
                             TestData{
                                 "DefaultTestCase02",
                                 {
                                     "con",  //
                                     "ryan"  //
                                 },
                                 {
                                     "ryan con",
                                     "ryan con",  //
                                     "ryan con",
                                     "ryan con"  //
                                 },
                                 3,  //
                                 {0, 0},
                             }),
                         [](const TestParamInfo<TestData>& info) {
                           return info.param.test_name;
                         });
