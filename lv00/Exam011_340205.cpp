#include <iostream>

using namespace std;

/**
 * [PCCE 기출문제] 3번 / 수 나누기
 * https://school.programmers.co.kr/learn/courses/30/lessons/340205
 */
int solution() {
    int number;
    cin >> number;

    int answer = 0;

    // 💡: 빈칸 채우기
    for (int i = 0; i < number; i++) {
        answer += number % 100;
        number /= 100;
    }
    cout << answer << endl;
    return 0;
}

//
// === 문제 읽고 첫 느낌 ===
//   이거 i < 1로 되어있는 것, 그냥 number 대신 넣으면 될 것 같아서
//   넣었는데... 통과했음. 😅
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
