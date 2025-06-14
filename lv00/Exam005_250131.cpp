#include <iostream>

using namespace std;

/**
 * [PCCE 기출문제] 3번 / 나이 계산
 *   https://school.programmers.co.kr/learn/courses/30/lessons/250131
 */
int solution() {
  int year, answer = 0;
  string age_type;
  cin >> year >> age_type;

  if (age_type == "Korea") {
    answer = 2030 - year + 1;
  } else if (age_type == "Year") {
    answer = 2030 - year;
  }

  cout << answer << endl;
  return 0;
}

//
// === 문제 읽고 첫 느낌 ===
//   cin, cout에 대해서 완전하게 테스트를 해볼까?
//   역시 방법이 있었다. 예전에 Java+JUnit 환경에서 진행했던 내용과 비슷하게
//   되었음.
//   * https://github.com/fp024/my-utils/blob/master/my-test-util/src/main/java/org/fp024/test/util/keyboard/KeyboardInputTestHelper.java
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
