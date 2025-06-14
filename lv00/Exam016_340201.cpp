#include <string>
#include <vector>

using namespace std;

/**
 * [PCCE 기출문제] 7번 / 버스
 *   https://school.programmers.co.kr/learn/courses/30/lessons/340201
 */
int func1(const int num) {
  if (0 > num) {
    return 0;
  }
  return num;
}

int func2(const int num) {
  if (num > 0) {
    return 0;
  }
  return num;
}

int func3(const vector<string> &station) {
  int num = 0;
  for (const auto &i : station) {
    if (i == "Off") {
      num += 1;
    }
  }
  return num;
}

int func4(const vector<string> &station) {
  int num = 0;
  for (const auto &i : station) {
    if (i == "On") {
      num += 1;
    }
  }
  return num;
}

int solution(const int seat, const vector<vector<string> > &passengers) {
  int num_passenger = 0;
  for (const auto &passenger : passengers) {
    num_passenger += func4(passenger);
    num_passenger -= func3(passenger);
  }
  const int answer = func1(seat - num_passenger);
  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
// * auto가 Java 11 이상의 var와 비슷하다.
// * 반복문 개선: IDE 권고: 인덱스 기반 반복문을 range-based for로 개선
//     const auto &i 사용으로 string 복사 없이 참조로 접근하여 성능 향상
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
