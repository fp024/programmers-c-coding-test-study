#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

// 💡 테스트할 함수 선언 💡
// ✔️ 문제 해결 함수
int solution(const vector<int>& nums);

// 기본 테스트 케이스들
TEST(Prac000_000_Tests, Default_TestCase_01) {
  const vector nums{100, 4, 200, 1, 3, 2};

  const int result = solution(nums);
  EXPECT_THAT(result, Eq(4));
}

TEST(Prac000_000_Tests, Default_TestCase_02) {
  const vector<int> nums{};

  const int result = solution(nums);
  EXPECT_THAT(result, Eq(0));
}

TEST(Prac000_000_Tests, Default_TestCase_03) {
  const vector nums{5};

  const int result = solution(nums);
  EXPECT_THAT(result, Eq(1));
}

TEST(Prac000_000_Tests, Default_TestCase_04) {
  const vector nums{100, 4,  200, 1,   3,   2,   11,  12,  13, 14,
                    15,  16, 501, 502, 503, 504, 505, 506, 507};

  const int result = solution(nums);
  EXPECT_THAT(result, Eq(7));
}