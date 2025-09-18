#include <string>

using namespace std;

/**
 * [PCCE 기출문제] 8번 / 닉네임 규칙
 *   https://school.programmers.co.kr/learn/courses/30/lessons/340200
 */
string solution(const string& nickname) {
  string answer;
  for (const char i : nickname) {
    if (i == 'l') {
      answer += "I";
    } else if (i == 'w') {
      answer += "vv";
    } else if (i == 'W') {
      answer += "VV";
    } else if (i == 'O') {
      answer += "0";
    } else {
      answer += i;
    }
  }
  while (answer.size() < 4) {
    answer += "o";
  }
  if (answer.size() > 8) {
    answer = answer.substr(0, 8);
  }
  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
// ...
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
