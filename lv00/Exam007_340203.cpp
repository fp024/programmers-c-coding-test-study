#include <string>
#include <vector>

using namespace std;

/**
 * [PCCE 기출문제] 5번 / 심폐소생술
 * https://school.programmers.co.kr/learn/courses/30/lessons/340203
 */
vector<int> solution(const vector<string> &cpr) {
    vector answer = {0, 0, 0, 0, 0};
    const vector<string> basic_order = {"check", "call", "pressure", "respiration", "repeat"};

    for (int i = 0; i < cpr.size(); i++) {
        for (int j = 0; j < basic_order.size(); j++) {
            if (cpr[i] == basic_order[j]) {
                answer[i] = j + 1;
                break;
            }
        }
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
