#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 오픈채팅방 ✨✨
 *   https://school.programmers.co.kr/learn/courses/30/lessons/42888
 */
/** 📝 ===== 선언 ===== 📝 */
vector<string> solution(const vector<string> &record);

/** 🏗️ ===== 정의 ===== 🏗️ */
vector<string> solution(const vector<string> &record) {
  unordered_map<string, string> userid_nickname_map;
  for (auto &row : record) {
    string cmd, name, nickname;
    stringstream ss(row);
    ss >> cmd >> name >> nickname;

    if (cmd == "Enter" || cmd == "Change") {
      userid_nickname_map[name] = nickname;
    }
  }

  vector<string> answer;
  for (auto &row : record) {
    string cmd, name, nickname;
    stringstream ss(row);
    ss >> cmd >> name >> nickname;

    if (cmd == "Enter") {
      answer.emplace_back(userid_nickname_map[name] + "님이 들어왔습니다.");
    } else if (cmd == "Leave") {
      answer.emplace_back(userid_nickname_map[name] + "님이 나갔습니다.");
    }
  }

  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
//   C++에서는 string의 split 방법이 특이하다..😂
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
