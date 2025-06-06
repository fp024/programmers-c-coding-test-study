#include <string>
#include <vector>

using namespace std;

/**
 * [PCCE 기출문제] 5번 / 산책
 *   https://school.programmers.co.kr/learn/courses/30/lessons/250129
 */
vector<int> solution(const string &route) {
    int east = 0;
    int north = 0;
    vector<int> answer(2);
    for (int i = 0; i < route.length(); i++) {
        switch (route[i]) {
            case 'N':
                north++;
                break;
            case 'S':
                north--; // 💡빈칸 채우기
                break;
            case 'E':
                east++; // 💡빈칸 채우기
                break;
            case 'W':
                east--; // 💡빈칸 채우기
                break; //  💡빈칸 채우기
        }
    }
    answer[0] = east;
    answer[1] = north;
    return answer;
}

//
// === 문제 읽고 첫 느낌 ===
//  Level 0의 풀지 않았던 문제를 C/C++로 해보았는데,
//  이번 문제는 빈칸 채우기 문제였다. 쉬운 문제였다. 😅
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
