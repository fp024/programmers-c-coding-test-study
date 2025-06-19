#include <array>
#include <vector>

using namespace std;

/**
 * 삼각 달팽이 - ✨✨
 *   https://school.programmers.co.kr/learn/courses/30/lessons/68645
 */
vector<int> solution(const int n) {
  // 삼각형 데이터를 넣을 벡터
  vector triangle(n, vector<int>(n));

  int x = 0;
  int y = 0;
  int d = 0;
  int v = 1;

  while (true) {
    // 방향 지정: 아래, 오른쪽, 왼쪽위
    // 💡 컴파일 타임 상수가 되서, while안에 들어가도 한번만 생성된다.
    constexpr array<int, 3> dy = {1, 0, -1};
    constexpr array<int, 3> dx = {0, 1, -1};
    triangle[y][x] = v++;

    // 다음 이동이 유효하지 않으면 방향 변경
    if (int y_next = y + dy[d],
        x_next = x + dx[d];            //
        y_next >= n ||                 //
        y_next < 0 ||                  //
        x_next >= n ||                 //
        x_next < 0 ||                  //
        triangle[y_next][x_next] != 0  //
    ) {
      // 방향 변경
      d = (d + 1) % 3;
      //
      // 방향 변경 직후 다음 변경이 유효하지 않으면 종료
      y_next = y + dy[d];
      x_next = x + dx[d];
      if (y_next >= n ||                 //
          y_next < 0 ||                  //
          x_next >= n ||                 //
          x_next < 0 ||                  //
          triangle[y_next][x_next] != 0  //
      ) {
        break;
      }
    }

    // 이동
    y = y + dy[d];
    x = x + dx[d];
  }

  // 답변 배열 채워넣기
  vector<int> answer;

  for (int i = 0; i < triangle.size(); i++) {
    for (int j = 0; j <= i; j++) {
      answer.push_back(triangle[i][j]);
    }
  }

  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
//   이 내용은...
//   "프로그래머스 코딩 테스트 문제 풀이 전략: 자바편"의 내용을 한번 공부해보고,
//   C++로 풀어본 내용이다. 저자님께서 문제를 이해하기 쉽게 풀어내신다. 👍👍
//   그리고...
//   VSCode + CMake Tools 환경에서 진행해봤는데, 디버깅하고 중단점 찍고 값
//   확인하고 하는 것들이 괜찮았다. +1점으로 통과 👍
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
//
