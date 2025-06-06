#include <vector>
#include <string>

using namespace std;

/**
 * [PCCE 기출문제] 7번 / 버스
 *   https://school.programmers.co.kr/learn/courses/30/lessons/340201
 */
int func1(const int num) {
    if (0 > num) {
        return 0;
    }
    return num;
}

int func2(const int num) {
    if (num > 0) {
        return 0;
    }
    return num;
}

int func3(const vector<string> &station) {
    int num = 0;
    for (int i = 0; i < station.size(); i++) {
        if (station[i] == "Off") {
            num += 1;
        }
    }
    return num;
}

int func4(const vector<string> &station) {
    int num = 0;
    for (int i = 0; i < station.size(); i++) {
        if (station[i] == "On") {
            num += 1;
        }
    }
    return num;
}

int solution(const int seat, const vector<vector<string> > &passengers) {
    int num_passenger = 0;
    for (int i = 0; i < passengers.size(); i++) {
        num_passenger += func4(passengers[i]);
        num_passenger -= func3(passengers[i]);
    }
    const int answer = func1(seat - num_passenger);
    return answer;
}

//
// === 문제 읽고 첫 느낌 ===
// ...
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
