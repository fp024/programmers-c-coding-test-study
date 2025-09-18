#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 베스트 앨범
 *   https://school.programmers.co.kr/learn/courses/30/lessons/42579
 */
/** 📝 ===== 선언 ===== 📝 */
vector<int> solution(const vector<string>& genres, const vector<int>& plays);

/** 🏗️ ===== 정의 ===== 🏗️ */
vector<int> solution(const vector<string>& genres, const vector<int>& plays) {
  // 장르 별 전체 플레이 횟수 맵
  unordered_map<string, int> genre_total_play_count_map;

  // 장르 별 상세 플레이 횟수 맵 <장르 <플레이인덱스, 플레이 횟수>>
  unordered_map<string, vector<pair<int, int>>> genre_detail_play_count_map;

  for (int i = 0; i < genres.size(); i++) {
    genre_total_play_count_map[genres[i]] += plays[i];
    genre_detail_play_count_map[genres[i]].emplace_back(i, plays[i]);
  }

  // 장르 별 전체 플레이 횟수 리스트
  vector<pair<string, int>> genre_total_play_count_list(
      genre_total_play_count_map.begin(), genre_total_play_count_map.end());

  std::sort(genre_total_play_count_list.begin(),
            genre_total_play_count_list.end(),
            [](const pair<string, int>& a, const pair<string, int>& b) {
              return a.second > b.second;
            });

  vector<int> answer;
  for (const auto& [genre, _] : genre_total_play_count_list) {
    // 장르 별 상세 플레이 횟수 맵에서...
    // 백터<플레이 인덱스, 플레이 횟수>를 꺼내면서 바로 정렬을 함.
    auto& detail_play_count_list = genre_detail_play_count_map[genre];
    std::sort(detail_play_count_list.begin(), detail_play_count_list.end(),
              [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second) {
                  return a.first < b.first;
                }
                return a.second > b.second;
              });

    answer.emplace_back(detail_play_count_list[0].first);
    if (detail_play_count_list.size() > 1) {
      answer.emplace_back(detail_play_count_list[1].first);
    }
  }

  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
//   뭔가 꼬여있어서 어렵긴 했는데, 통과는 했다. +1점 통과 👍
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
