#include <iostream>

using namespace std;

/**
 * [PCCE 기출문제] 4번 / 저축
 * https://school.programmers.co.kr/learn/courses/30/lessons/250130
 */
int solution(const int start, const int before, const int after) {
    int money = start;
    int month = 1;

    while (money < 70) {
        money += before; // 💡빈 칸채우기
        month++;
    }

    // 💡빈칸 채우기
    while (money < 100) {
        money += after; // 💡빈 칸채우기
        month++;
    }

    return month;
}
