#include <iostream>
#include <map>
#include <vector>
#include <string>

// 💡 디버그 출력 제어 매크로
#define DEBUG 1  // 1: 출력 ON, 0: 출력 OFF

using namespace std;

/**
 * 가장 많이 받은 선물
 *   https://school.programmers.co.kr/learn/courses/30/lessons/258712
 */
int solution(const vector<string> &friends, const vector<string> &gifts) {
    auto answer = 0;

    // 💡 <보낸사람ID, <선물받는ID, 보낸선물 개수>> Map
    map<string, map<string, int> > giftSenderReceiversMap;

    for (auto &senderAndReceiver: gifts) {
        const auto splitIndex = senderAndReceiver.find(' ');
        auto sender = senderAndReceiver.substr(0, splitIndex);
        auto receiver = senderAndReceiver.substr(splitIndex + 1);

        giftSenderReceiversMap[sender][receiver]++;
    }

#if DEBUG
    // 💡 중간 결과 출력 😅
    for (const auto &[sender, receivers]: giftSenderReceiversMap) {
        cout << sender << "가 준 선물:" << endl;
        for (const auto &[receiver, count]: receivers) {
            cout << "  -> " << receiver << ": " << count << "개" << endl;
        }
        cout << endl;
    }
#endif

    // 💡 ID별 보낸선물수 Map
    map<string, int> sentCount;
    // 💡 ID별 받은선물수 Map
    map<string, int> receivedCount;

    for (const auto &id: friends) {
        for (const auto &[receiver, count]: giftSenderReceiversMap[id]) {
            sentCount[id] += count;
            receivedCount[receiver] += count;
        }

        // 선물을 한번도 보내지 않은 ID는 0으로 초기화해준다.
        if (!sentCount.count(id)) {
            sentCount[id] = 0;
        }
        // 선물을 한번도 받지 않은 ID는 0으로 초기화해준다.
        if (!receivedCount.count(id)) {
            receivedCount[id] = 0;
        }
    }

#if DEBUG
    for (const auto &[sender, count]: sentCount) {
        cout << "선물 보낸수:" << sender << ": " << count << endl;
    }

    for (const auto &[receiver, count]: receivedCount) {
        cout << "선물 받은수:" << receiver << ": " << count << endl;
    }
#endif

    // 💡 다음 달에 받을 선물 수 계산
    map<string, int> nextMonthGifts;

    // 모든 친구 쌍에 대해 처리
    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            const string &person1 = friends[i];
            const string &person2 = friends[j];
            // 직접 주고받은 선물 수

            if (const int gifts1to2 = giftSenderReceiversMap[person1][person2],
                        gifts2to1 = giftSenderReceiversMap[person2][person1];
                gifts1to2 > gifts2to1
            ) {
                nextMonthGifts[person1]++;
            } else if (gifts2to1 > gifts1to2) {
                nextMonthGifts[person2]++;
            } else {
                // 선물 지수로 판단

                if (const int index1 = sentCount[person1] - receivedCount[person1],
                            index2 = sentCount[person2] - receivedCount[person2];
                    index1 > index2
                ) {
                    nextMonthGifts[person1]++;
                } else if (index2 > index1) {
                    nextMonthGifts[person2]++;
                }
                // 선물 지수도 같으면 아무도 안 받음
            }
        }
    }

    // 💡 최댓값 찾기
    for (const auto &[person, count]: nextMonthGifts) {
        answer = max(answer, count);
    }


    return answer;
}

//
// === 문제 읽고 첫 느낌 ===
//   아주 쉬운 Lv00 문제만 풀다가 갑자기 레벨이 올랐다. 😅
//   Lv01의 마지막 문제인데... 어떻게 풀어야할까?
//   C++ map에 const는 진짜 상수를 만든다.. readOnly Map이 된다. Java 처럼 참조 주소만 상수로 만드는게 아님..😅
//
//   여러 상황을 담은 Map까지는 완성을 했는데, 마지막, 친구 쌍별로 처리하는게 생각이 안떠올라서,
//   JetBrains AI에게 부탁했는데, 잘 풀어낸 것 같다. 😂😂😂
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
