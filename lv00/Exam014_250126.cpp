#include <string>
#include <vector>

using namespace std;

/**
 * [PCCE 기출문제] 8번 / 창고 정리
 *   https://school.programmers.co.kr/learn/courses/30/lessons/250126
 */
string solution(const vector<string> &storage, const vector<int> &num) {
  int num_item = 0;
  vector<string> clean_storage(storage.size());
  vector<int> clean_num(num.size());
  for (int i = 0; i < storage.size(); i++) {
    int clean_idx = -1;
    for (int j = 0; j < num_item; j++) {
      if (storage[i] == clean_storage[j]) {
        clean_idx = j;
        break;
      }
    }
    if (clean_idx == -1) {
      clean_storage[num_item] = storage[i];  // 💡
      clean_num[num_item] = num[i];
      num_item += 1;
    } else {
      clean_num[clean_idx] += num[i];
    }
  }

  // 아래 코드에는 틀린 부분이 없습니다.

  int num_max = -1;
  string answer;
  for (int i = 0; i < num_item; i++) {
    if (clean_num[i] > num_max) {
      num_max = clean_num[i];
      answer = clean_storage[i];
    }
  }
  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
//   계속 찍고 있다. 😅 그런데 계속 맞고 있음. 😅
//
// === 다른 사람 풀이 확인 이후 의견 ===
//    vector의 at()으로 요소를 탐색하신 분이 있다. 😅
//
