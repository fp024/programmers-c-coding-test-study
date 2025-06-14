#include <iostream>

using namespace std;

/**
 * [PCCE 기출문제] 4번 / 병과분류
 *   https://school.programmers.co.kr/learn/courses/30/lessons/340204
 */
void solution(const string& code) {
  if (const string last_four_words = code.substr(code.size() - 4, 4);  //
      last_four_words == "_eye") {
    cout << "Ophthalmologyc";
  } else if (last_four_words == "head") {
    cout << "Neurosurgery";
  } else if (last_four_words == "infl") {
    cout << "Orthopedics";
  } else if (last_four_words == "skin") {
    cout << "Dermatology";
  } else {
    cout << "direct recommendation";
  }
}

//
// === 문제 읽고 첫 느낌 ===
//   이번 문제는 넘어가려다가...
//   함수 내부의 cout 결과를 테스트 할 수 있는지 궁금해서 진행했다.
//   해보니 다음 처럼, 캡처 기능을 제공해줘서, 쉽게 테스트 할 수 있었다.
//
//      testing::internal::CaptureStdout(); // 캡쳐 시작
//      solution("pat23_08_20_head"); // 솔루션 함수 실행
//      const string output = testing::internal::GetCapturedStdout(); // 캡쳐
//      종료, 결과 얻기 EXPECT_EQ(output, "Neurosurgery"); // 결과 확인
//
//   이제 부터는 그냥... 빈칸 표시 주석은 하지말자..😅
//
// === 다른 사람 풀이 확인 이후 의견 ===
//   ...
//
