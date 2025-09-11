/**
 * [PCCE 기출문제] 2번 / 피타고라스의 정리
 *   https://school.programmers.co.kr/learn/courses/30/lessons/250132
 */
int solution(const int a, const int c) {
  const int b_square = c * c - a * a;
  return b_square;
}

//
// === 문제 읽고 첫 느낌 ===
//   pow를 써야하나 했는데, 단순 제곱이라 그냥 2번 곱하는게 낫겠다.
//
// === 다른 사람 풀이 확인 이후 의견 ===
//   인수 분해 공식을 사용해서 해결하신 분도 있다.: c² - a² = (c - a)(c + a)
//   제곱해서 int 한계를 초과하는 값을 방지할 수 있는 장점이 있을 것 같다.
//   int b_square = (c - a) * (c + a);
//
