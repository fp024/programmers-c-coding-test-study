#include <string>

using namespace std;

/**
 * [PCCE 기출문제] 7번 / 가습기
 *   https://school.programmers.co.kr/learn/courses/30/lessons/250127
 */
int func1(const int humidity, const int val_set) {
    if (humidity < val_set)
        return 3;
    return 1;
}

int func2(const int humidity) {
    if (humidity >= 50)
        return 0;
    if (humidity >= 40)
        return 1;
    if (humidity >= 30)
        return 2;
    if (humidity >= 20)
        return 3;
    if (humidity >= 10)
        return 4;
    return 5;
}

int func3(int humidity, int val_set) {
    if (humidity < val_set)
        return 1;
    return 0;
}

int solution(const string &mode_type, const int humidity, const int val_set) {
    int answer = 0;
    if (mode_type == "auto") {
        answer = func2(humidity);
    } else if (mode_type == "target") {
        answer = func1(humidity, val_set);
    } else if (mode_type == "minimum") {
        answer = func3(humidity, val_set);
    }
    return answer;
}

//
// === 문제 읽고 첫 느낌 ===
// ...
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
