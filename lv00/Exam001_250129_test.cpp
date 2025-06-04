#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace testing;

// 테스트할 함수 선언
vector<int> solution(const string &route);

class RouteTest : public Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

// 기본 테스트 케이스들
TEST_F(RouteTest, EmptyRoute) {
    const vector<int> result = solution("");
    EXPECT_EQ(result[0], 0); // east
    EXPECT_EQ(result[1], 0); // north
    // vector을 바로 비교할 수 있는 Matcher
    EXPECT_THAT(result, SizeIs(2));
    EXPECT_THAT(result, ElementsAre(0, 0));
}

TEST_F(RouteTest, SingleDirection) {
    // 북쪽으로 한 번
    vector<int> result = solution("N");
    EXPECT_EQ(result[0], 0); // east
    EXPECT_EQ(result[1], 1); // north

    // 남쪽으로 한 번
    result = solution("S");
    EXPECT_EQ(result[0], 0); // east
    EXPECT_EQ(result[1], -1); // north

    // 동쪽으로 한 번
    result = solution("E");
    EXPECT_EQ(result[0], 1); // east
    EXPECT_EQ(result[1], 0); // north

    // 서쪽으로 한 번
    result = solution("W");
    EXPECT_EQ(result[0], -1); // east
    EXPECT_EQ(result[1], 0); // north
}

TEST_F(RouteTest, OppositeDirections) {
    // 북쪽으로 갔다가 남쪽으로 돌아오기
    vector<int> result = solution("NS");
    EXPECT_EQ(result[0], 0); // east
    EXPECT_EQ(result[1], 0); // north

    // 동쪽으로 갔다가 서쪽으로 돌아오기
    result = solution("EW");
    EXPECT_EQ(result[0], 0); // east
    EXPECT_EQ(result[1], 0); // north
}

TEST_F(RouteTest, ComplexRoute) {
    // 복잡한 경로
    const vector<int> result = solution("NESWNESWNESW");
    EXPECT_EQ(result[0], 0); // east (3E - 3W = 0)
    EXPECT_EQ(result[1], 0); // north (3N - 3S = 0)
}

TEST_F(RouteTest, SquarePath) {
    // 정사각형 경로 (시계방향)
    vector<int> result = solution("NESW");
    EXPECT_EQ(result[0], 0); // east
    EXPECT_EQ(result[1], 0); // north

    // 정사각형 경로 (반시계방향)
    result = solution("NWSE");
    EXPECT_EQ(result[0], 0); // east
    EXPECT_EQ(result[1], 0); // north
}

TEST_F(RouteTest, LongRoute) {
    // 긴 경로
    const vector<int> result = solution("NNNEEESSSSWWW");
    EXPECT_EQ(result[0], 0); // east (3E - 3W = 0)
    EXPECT_EQ(result[1], -1); // north (3N - 4S = -1)
}

TEST_F(RouteTest, OnlyEastWest) {
    const vector<int> result = solution("EEEWW");
    EXPECT_EQ(result[0], 1); // east (3E - 2W = 1)
    EXPECT_EQ(result[1], 0); // north
}

TEST_F(RouteTest, OnlyNorthSouth) {
    const vector<int> result = solution("NNNSS");
    EXPECT_EQ(result[0], 0); // east
    EXPECT_EQ(result[1], 1); // north (3N - 2S = 1)
}
