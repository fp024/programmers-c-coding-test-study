
#include <array>
#include <string>
#include <vector>

using namespace std;

/**
 * 거리두기 확인하기 - ✨✨
 *   https://school.programmers.co.kr/learn/courses/30/lessons/81302
 */
// 💡: 상, 하, 좌, 우
constexpr array<int, 4> dx = {0, 0, -1, 1};
constexpr array<int, 4> dy = {-1, 1, 0, 0};
//                            00  01 10 11

/** 인접한 위치에 응시자가 있는지 검사 */
bool isNextToVolunteer(const vector<vector<char>>& room,  //
                       const int x, const int y, const int exclude) {
  for (int d = 0; d < 4; d++) {
    if (d == exclude) continue;

    const int nx = x + dx[d];
    const int ny = y + dy[d];
    if (ny < 0 || ny >= room.size() || nx < 0 || nx >= room.size()) continue;
    if (room[ny][nx] == 'P') return true;
  }
  return false;
}

/** 특정 응시자의 위치 x, y의 거리두기가 잘 지켜지는지 검사 */
bool is_distanced(const vector<vector<char>>& room, const int x, const int y) {
  for (int d = 0; d < 4; d++) {
    const int nx = x + dx[d];
    const int ny = y + dy[d];
    if (ny < 0 || ny >= room.size() || nx < 0 || nx >= room.size()) continue;
    // room[ny][nx]를 통해 다른 응시자에게 도달할 수 있는지 검사
    switch (room[ny][nx]) {
      case 'P':
        return false;
      case 'O':
        // 인접한 곳에 다른 응시자가 있는지 검사 (💡방향 반전은 XOR 연산 사용)
        if (isNextToVolunteer(room, nx, ny, d ^ 1)) return false;
        break;
      default:
        // 💡 P, O외에 다른 상태일 때는 처리가 필요없음
        break;
    }
  }
  // room[y][x]가 거리두기를 지키는지 검사
  return true;
}

/** 대기실의 거리두기가 잘 되어있는지 여부 검사 */
bool is_distanced(const vector<vector<char>>& room) {
  for (int y = 0; y < room.size(); y++) {
    for (int x = 0; x < room[y].size(); x++) {
      if (room[y][x] != 'P') continue;
      if (!is_distanced(room, x, y)) return false;
    }
  }
  return true;
}

vector<int> solution(const vector<vector<string>>& places) {
  vector<int> answer(places.size());

  for (int i = 0; i < places.size(); i++) {
    vector<vector<char>> room(places[i].size());

    for (int j = 0; j < places[i].size(); j++) {
      room[j] = vector(places[i][j].begin(), places[i][j].end());
    }
    // 거리두기 검사 후 answer에 기록
    if (is_distanced(room)) {
      answer[i] = 1;
    } else {
      answer[i] = 0;
    }
  }
  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
//   풀이를 위한 아이디어를 자력을 생각해내기가 어렵다. 😅
//   거기다 C++로 하려니 더 힘드네...😂😂😂
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
//
