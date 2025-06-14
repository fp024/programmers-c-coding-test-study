#include <vector>

using namespace std;

/**
 * [PCCE 기출문제] 6번 / 물 부족
 *   https://school.programmers.co.kr/learn/courses/30/lessons/340202
 */
int solution(const int storage, int usage, const vector<int> &change) {
  int total_usage = 0;
  for (int i = 0; i < change.size(); i++) {
    usage = usage + usage * change[i] / 100;
    total_usage += usage;
    if (total_usage > storage) {
      return i;
    }
  }
  return -1;
}

//
// === 문제 읽고 첫 느낌 ===
//   뭔가 어려움... 찍기가 안통함 😅
//   그런데 문제가 틀린 것 같다. 입출력 예의 테이블에 두번째 예의 result가 1로
//   잘못나타남. 😅
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
