#include <algorithm>
#include <optional>
#include <string>
#include <vector>

using namespace std;

/**
 * 교점에 별 만들기 - ✨✨
 *   https://school.programmers.co.kr/learn/courses/30/lessons/87377
 */
// Java의 record와 가장 비슷하게 struct 사용
struct Point {
  const long x;
  const long y;
  Point(const long x_val, const long y_val) : x(x_val), y(y_val) {}
  Point() = delete;
};

/** 교점 구하기 */
std::optional<Point> get_intersection(const long a1, const long b1,
                                      const long c1, const long a2,
                                      const long b2, const long c2) {
  const long common_denominator = a1 * b2 - a2 * b1;  // 공통 분모

  // 분모가 0이면 교점이 없거나 무수히 많음 (평행하거나 일치하는 직선)
  if (common_denominator == 0) {
    return std::nullopt;
  }

  const long x_numerator = b1 * c2 - b2 * c1;  // x의 분자
  const long y_numerator = a2 * c1 - a1 * c2;  // y의 분자

  // x 좌표가 정수인지 확인 (분자가 분모로 나누어 떨어지는지)
  if (x_numerator % common_denominator != 0) {
    return std::nullopt;
  }
  // y 좌표가 정수인지 확인 (분자가 분모로 나누어 떨어지는지)
  if (y_numerator % common_denominator != 0) {
    return std::nullopt;
  }

  // 이제 x, y가 정수임이 보장되었으므로 나눗셈 수행
  const long x = x_numerator / common_denominator;
  const long y = y_numerator / common_denominator;

  return Point(x, y);
}

/** 가장 작은 좌표 찾기 */
Point get_minimum_point(const vector<Point>& points) {
  long x = LONG_MAX;
  long y = LONG_MAX;

  for (const Point p : points) {
    if (p.x < x) {
      x = p.x;
    }
    if (p.y < y) {
      y = p.y;
    }
  }
  return {x, y};
}

/** 가장 큰 좌표 찾기 */
Point get_maximum_point(const vector<Point>& points) {
  long x = LONG_MIN;
  long y = LONG_MIN;

  for (const Point p : points) {
    if (p.x > x) {
      x = p.x;
    }
    if (p.y > y) {
      y = p.y;
    }
  }
  return {x, y};
}

/** 💡 문제 해결 함수 💡 */
vector<string> solution(const vector<vector<int>>& line) {
  vector<Point> points;
  for (int i = 0; i < line.size(); i++) {
    for (int j = i + 1; j < line.size(); j++) {
      std::optional<Point> intersection =
          get_intersection(line[i][0], line[i][1], line[i][2],  //
                           line[j][0], line[j][1], line[j][2]);

      if (intersection.has_value()) {
        points.push_back(intersection.value());
      }
    }
  }

  // 2차원 배열 크기 결정
  const Point minimum = get_minimum_point(points);
  const Point maximum = get_maximum_point(points);
  const int width = maximum.x - minimum.x + 1;
  const int height = maximum.y - minimum.y + 1;

  // char[][] arr = new char[height][width];
  vector arr(height, vector<char>(width));

  for (auto& row : arr) {
    std::fill(row.begin(), row.end(), '.');
  }

  // 2차원 배열에 별 표시
  for (const Point p : points) {
    const int x = p.x - minimum.x;
    const int y = maximum.y - p.y;
    arr[y][x] = '*';
  }

  // 문자열 배열로 반환 후 반환
  vector<string> result;
  for (const auto& row : arr) {
    // std::string 생성자에 이터레이터 전달
    result.emplace_back(row.begin(), row.end());
  }

  return result;
}

//
// === 문제 읽고 첫 느낌 ===
//   Java로 먼저 해본 내용을 C++로 바꿔보긴 했는데, 확실히 어렵다.
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
//
