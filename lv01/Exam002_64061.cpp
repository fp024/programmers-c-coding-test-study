#include <stack>
#include <vector>

using namespace std;

/**
 * 크레인 인형 뽑기 게임
 *   https://school.programmers.co.kr/learn/courses/30/lessons/64061
 */
/** 📝 ===== 선언 ===== 📝 */
int solution(const vector<vector<int>>& board, const vector<int>& moves);

/** 🏗️ ===== 정의 ===== 🏗️ */
int solution(const vector<vector<int>>& board, const vector<int>& moves) {
  const int N = static_cast<int>(board.size());

  vector<stack<int>> stack_list(N);
  stack<int> goal_stack;
  int answer = 0;

  // (1) 🤔 게임화면을 스택으로 먼저 바꿈
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] != 0) {
        stack_list[j].push(board[i][j]);
      }
    }
  }

  // (2) 이동 명령 처리
  for (const auto move : moves) {
    // (3) 이동한 슬롯에 인형이 남아 있으면...
    if (!stack_list[move - 1].empty()) {
      // (4) 뽑은 인형과 보관 스택 맨위의 인형이 일치하면...
      //     둘다 제거하고 사라진 인형 개수 증감처리
      if (const auto doll = stack_list[move - 1].top();
          !goal_stack.empty() && goal_stack.top() == doll) {
        stack_list[move - 1].pop();
        goal_stack.pop();
        answer += 2;
      } else {
        // (5) 뽑은 인형과 보관 Stack 맨위의 인형이 일치하지 않으면
        //     슬롯 스택의 인형은 제거하고, 보관 스택 안에 인형을 넣음.
        stack_list[move - 1].pop();
        goal_stack.push(doll);
      }
    }
  }

  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
// Java로는 먼저 풀었었다. 이때는 스택을 사용하지는 않았음.
// * https://github.com/fp024/programmers-java-coding-test-study/blob/master/src/test/java/org/fp024/lv01/Exam64061Tests.java
//
// 이번에는 board를 스택으로 먼저 바꾸고 풀어봤음.
// 그런데 입력데이터를 스택으로 바꾸는게 꽤 해깔린다.
// 디버깅 하면서 모양을 맞추긴했는데... 역시 해깔림 😂
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
