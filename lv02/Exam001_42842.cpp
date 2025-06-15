#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * 카펫 ★★
 *   https://school.programmers.co.kr/learn/courses/30/lessons/42842
 */

/** 약수 쌍을 구하는 헬퍼 함수 */
vector<pair<int, int>> getDivisorPairs(int n);

/** 문제 해결 함수 */
vector<int> solution(const int brown, const int yellow) {
  vector<int> answer;

  // (1) 노란색 넓이의 약수의 쌍을 구함:
  //     - 약수 쌍이 결국 가로 x 세로가 될 수 있다.
  //     - yellow 값 자체가 넓이가 될 수 있다.
  const vector<pair<int, int>> yellowDivisorPairs = getDivisorPairs(yellow);

  // (2) 각 약수 쌍에 대해 brown 영역을 고려한 검증
  for (auto &[w_yellow, h_yellow] : yellowDivisorPairs) {
    if (const auto w_brown = w_yellow + 2,  // 가로에 양쪽 2칸 추가
        h_brown = h_yellow + 2;
        w_brown * h_brown == brown + yellow) {
      answer.push_back(w_brown);
      answer.push_back(h_brown);
      break;  // 답을 찾았으면 더이상 검사할 필요없음.
    }
  }

  return answer;
}

vector<pair<int, int>> getDivisorPairs(const int n) {
  vector<pair<int, int>> pairs;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      pairs.emplace_back(n / i, i);
    }
  }
  return pairs;
}

//
// === 문제 읽고 첫 느낌 ===
//   처음에는 꽤 막혔는데...
//   Copilot에게 약수 쌍을 구하는 힌트를 얻어서 이후 부터는 쉽게 풀었다.
//
// === 다른 사람 풀이 확인 이후 의견 ===
//   다른 사람 풀이를 보면 좀 더 간단하게 한 것도 많이 보이는 것 같은데...
//   바로 머리에는 잘 안들어온다. 😅
//
