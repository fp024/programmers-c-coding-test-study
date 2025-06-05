#include <string>
#include <vector>

using namespace std;

/**
 * [PCCE 기출문제] 6번 / 가채점
 * https://school.programmers.co.kr/learn/courses/30/lessons/250128
 */
vector<string> solution(const vector<int> &numbers, const vector<int> &our_score, const vector<int> &score_list) {
    const size_t num_student = numbers.size();
    vector<string> answer(num_student);

    for (int i = 0; i < num_student; i++) {
        if (our_score[i] == score_list[numbers[i] - 1]) {
            answer[i] = "Same";
        } else {
            answer[i] = "Different";
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
