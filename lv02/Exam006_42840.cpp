#include <algorithm>
#include <vector>

using namespace std;

/**
 * 모의고사 ★
 *   https://school.programmers.co.kr/learn/courses/30/lessons/42840
 */
/** 📝 ===== 선언 ===== 📝 */
vector<int> solution(const vector<int>& answers);

/** 답안과 패턴을 전달 받았을 때.. 점수 계산 */
int calc_score(const vector<int>& answer, const vector<int>& pattern);

/** 비교를 하는 규칙 함수*/
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

/** 🏗️ ===== 정의 ===== 🏗️ */
vector<int> solution(const vector<int>& answers) {
  vector<pair<int, int>> number_score_pairs;

  const vector<vector<int>> patterns = {{1, 2, 3, 4, 5},
                                        {2, 1, 2, 3, 2, 4, 2, 5},
                                        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

  for (int i = 0; i < patterns.size(); i++) {
    const auto score = calc_score(answers, patterns[i]);
    number_score_pairs.emplace_back(i + 1, score);
  }

  sort(number_score_pairs.begin(), number_score_pairs.end(), compare);

  vector<int> result;

  for (const auto& [number, score] : number_score_pairs) {
    // 최고 점수를 만나지 않는 순간 끝낸다.
    if (number_score_pairs[0].second != score) {
      break;
    }
    result.push_back(number);
  }

  return result;
}

int calc_score(const vector<int>& answer, const vector<int>& pattern) {
  int total_score = 0;
  for (int i = 0; i < answer.size(); i++) {
    if (const auto pattern_index = i % pattern.size();
        pattern[pattern_index] == answer[i]) {
      total_score++;
    }
  }
  return total_score;
}

//
// === 문제 읽고 첫 느낌 ===
//   뭔가 난 복잡하게 푸는 느낌이 든다. 😅
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
