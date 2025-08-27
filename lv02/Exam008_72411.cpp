#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 메뉴 리뉴얼
 *   https://school.programmers.co.kr/learn/courses/30/lessons/72411
 */
/** 📝 ===== 선언 ===== 📝 */
vector<string> solution(const vector<string> &orders,
                        const vector<int> &course);

vector<string> combinations(string menu_ids, int r);

void calc_combinations(int idx,                      //
                       vector<char> &order,          //
                       const string &result,         //
                       vector<string> &result_list,  //
                       int r                         //
);
/** 💡 ===== 문제 풀이 전략 ===== 💡 */
/*
  요소간 순서는 상관 없지만, 메뉴 중에 몇가지씩 뽑기가 구현되야한다.
  ==> 조합 함수 구현

  조합 결과의 요소들을 일단 오름 차순 정렬
  요소를 맵의 Key로 사용하고 카운트를 값으로 설정해서
  카운트를 셈

  문제에 아직 익숙하진 않으니 😅, Java로 먼저 풀었던 스타일로 적용해보자!
*/

/** 🏗️ ===== 정의 ===== 🏗️ */
// 재귀 실행 영역
void calc_combinations(const int idx,                //
                       vector<char> &order,          //
                       const string &result,         //
                       vector<string> &result_list,  //
                       const int r                   //
) {
  if (result.length() == r) {
    result_list.push_back(result);
    return;
  }

  for (int i = idx; i < order.size(); i++) {
    calc_combinations(i + 1, order, result + order[i], result_list, r);
  }
}

vector<string> combinations(string menu_ids, const int r) {
  vector<string> result_list;
  vector menus(menu_ids.begin(), menu_ids.end());
  calc_combinations(0, menus, "", result_list, r);
  return result_list;
}

vector<string> solution(const vector<string> &orders,
                        const vector<int> &course) {
  vector<string> answer;

  for (const int &course_qty : course) {
    // <코스 단위, 카운트> 맵
    unordered_map<string, int> course_unit_count_map;
    for (string order_set : orders) {  // 참조가 아닌 복사 방식으로 순회
      // 메뉴 ID들의 정렬
      sort(order_set.begin(), order_set.end());
      vector<string> combi_list = combinations(order_set, course_qty);

      // 코드 단위 카운트 맵을 생성
      for (const string &combi : combi_list) {
        // C++의 map은 Value 타입의 기본값으로 초기화되어,
        // 0으로 초기화 되어있으므로 그냥 증감해주면 된다.
        course_unit_count_map[combi]++;
      }
    }

    int max_count = 0;
    for (const auto &[_, count] : course_unit_count_map) {
      // 코스 단위별 가장 많이 나타난 카운트:
      //   예) 코스단위2|3|4 에서 가장 많이 나온 코스단위 카운트
      if (count > max_count) {
        max_count = count;
      }
    }

    for (const auto &[c_unit, count] : course_unit_count_map) {
      if (count == max_count  //
                              // 코스 단위 별 가장 많이 나온 코스단위를 답안에
                              // 추가하는데, 2개 이상일 때만 답안에 추가
          && count >= 2) {
        answer.push_back(c_unit);
      }
    }
  }
  sort(answer.begin(), answer.end());
  return answer;
}

//
// === 문제 읽고 첫 느낌 ===
// 이전에 Java 코드로 만든 것을 C++로 바꿔봤다.
// https://github.com/fp024/programmers-java-coding-test-study/blob/master/src/test/java/org/fp024/lv02/Exam72411Tests.java
//
// 그래도 백지상태에서 여전히 조합 함수 만들어보라고 하면 못 만들것 같은데...😂
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
