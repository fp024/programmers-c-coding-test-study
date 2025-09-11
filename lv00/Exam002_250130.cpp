/**
 * [PCCE 기출문제] 4번 / 저축
 *   https://school.programmers.co.kr/learn/courses/30/lessons/250130
 */
int solution(const int start, const int before, const int after) {
  int money = start;
  int month = 1;

  while (money < 70) {
    money += before;  // 💡빈 칸채우기
    month++;
  }

  // 💡빈칸 채우기
  while (money < 100) {
    money += after;  // 💡빈 칸채우기
    month++;
  }

  return month;
}

//
// === 문제 읽고 첫 느낌 ===
//  아직 Lv0에 빈칸채우기 문제라 어렵지 않았다. 😅
//  그런데 gtest로 테스트가 쉽도록.
//  원본 문제에서 cin으로 start, before, after를 입력 받는 부분만
//  함수 매개변수로 직접 받도록 수정하고, 계산된 값을 함수의 반환 값으로
//  처리하도록 수정했다.
//
//  앞으로도 cin으로 받는 부분은 이런식으로 수정해야겠다.
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
