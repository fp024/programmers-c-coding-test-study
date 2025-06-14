#include <iostream>

using namespace std;

/**
 * [PCCE 기출문제] 2번 / 각도 합치기
 *   https://school.programmers.co.kr/learn/courses/30/lessons/340206
 */
int solution() {
  int angle1;
  int angle2;
  cin >> angle1 >> angle2;

  const int sum_angle = (angle1 + angle2) % 360;
  cout << sum_angle << endl;
  return 0;
}

//
// === 문제 읽고 첫 느낌 ===
// ...
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
