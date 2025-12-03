#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

/*
   🤖 Gemini가 출제한 문제:
      가장 긴 연속된 숫자 찾기

   📝 문제 정의
      정수 배열 nums가 주어집니다. 배열에서 연속적으로 증가하는(연속된 숫자)
      가장 긴 부분 수열의 길이를 반환하는 함수를 작성하세요.

      연속된 숫자란 n, n+1, n+2, ... 순서를 의미하며, 배열 내의 위치는
   상관없습니다. 예를 들어, 배열 [100, 4, 200, 1, 3, 2]에서 연속된 숫자의 집합은
   [1, 2, 3, 4]이며, 길이는 4입니다.

   📥 입력 예시(JS)
       const nums = [100, 4, 200, 1, 3, 2];

   📤 기대 출력(JS)
       4
 */
/** 📝 ===== 선언 ===== 📝 */
int solution(const vector<int>& nums);

/** 🏗️ ===== 정의 ===== 🏗️ */
int solution(const vector<int>& nums) {
  // 1. Set에 모든 요소를 저장
  const unordered_set nums_set(nums.begin(), nums.end());
  int max_length = 0;

  // 2. Set의 모든 요소를 순회 (O(N))
  for (const int& n : nums_set) {
    // n이 수열의 시작점인지 확인 (n - 1이 set에 없어야 시작점)
    if (!nums_set.count(n - 1)) {
      int current_num = n;
      int current_length = 1;

      // 3. 수열을 확장하며 길이를 계산합니다. (O(1) 검색)
      while (nums_set.count(current_num + 1)) {
        current_num += 1;
        current_length += 1;
      }

      // 최대 길이 갱신
      max_length = std::max(max_length, current_length);
    }
  }

  return max_length;
}

//
// === 문제 읽고 첫 느낌 ===
// JS로 먼저 풀었던 내용인데,
// Gemini가 Set을 활용해서 풀 수 있다고 하여 적용했다.
// * https://github.com/fp024/programmers-js-coding-test-study/blob/master/src/js/practice/prac000_001.js
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
