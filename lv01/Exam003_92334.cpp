#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 신고 결과 받기
 *   https://school.programmers.co.kr/learn/courses/30/lessons/92334
 */
/** 📝 ===== 선언 ===== 📝 */
vector<int> solution(const vector<string>& id_list,
                     const vector<string>& report, int k);
/** 🏗️ ===== 정의 ===== 🏗️ */
vector<int> solution(const vector<string>& id_list,
                     const vector<string>& report, int k) {
  // 불량 유저별 신고자 set
  //    <불량유저ID ,set<신고자ID>>
  unordered_map<string, unordered_set<string>> bad_user_and_reporters_map;
  // 신고자 별 불량 유저 set
  //    <신고자ID ,set<불량유저ID>>
  unordered_map<string, unordered_set<string>> reporter_and_bad_users_map;

  for (const auto& r : report) {
    string reporter, bad_user;
    stringstream ss(r);
    ss >> reporter >> bad_user;
    bad_user_and_reporters_map[bad_user].insert(reporter);
    reporter_and_bad_users_map[reporter].insert(bad_user);
  }

  vector answer(id_list.size(), 0);

  for (auto i = 0; i < id_list.size(); i++) {
    const auto& reporter = id_list[i];
    // 💡 C++에서는 키가 없는 상태에서 [] 연산자로 맵을 조회하면 키를 만들고
    //    V타입의 기본값으로 설정하므로 다음 코드가 필요없다.
    // if (reporter_and_bad_users_map.find(reporter) ==
    //     reporter_and_bad_users_map.end()) {
    //   reporter_and_bad_users_map[reporter] = {};
    // }
    for (const auto& bad_user : reporter_and_bad_users_map[reporter]) {
      if (bad_user_and_reporters_map[bad_user].size() >= k) {
        answer[i]++;
      }
    }
  }

  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
//   생각이 안나서 예전 Java로 풀은 코드를 바꿔만 봤는데, 이전에 해본게 왜
//   이렇게 이해가 안되지? 😂
// * Java
// https://github.com/fp024/programmers-java-coding-test-study/blob/master/src/test/java/org/fp024/lv01/Exam92334Tests.java
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
