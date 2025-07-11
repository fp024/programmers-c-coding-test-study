#include <vector>

using namespace std;

/**
 * 행렬의 곱셈 - ✨✨
 *   https://school.programmers.co.kr/learn/courses/30/lessons/12949
 */
vector<vector<int>> solution(const vector<vector<int>> &arr1,
                             const vector<vector<int>> &arr2)  //
{
  vector product(arr1.size(), vector<int>(arr2[0].size()));

  for (int i = 0; i < product.size(); i++) {
    for (int j = 0; j < product[i].size(); j++) {
      product[i][j] = 0;
      for (int k = 0; k < arr1[i].size(); k++) {
        product[i][j] += arr1[i][k] * arr2[k][j];
        // i:0
        //                   0  0         0  0
        //                   0  1         1  0
        //
        //                   0  0         0  1
        //                   0  1         1  1
        // i:1
        //                   1  0         0  0
        //                   1  1         1  0
        //
        //                   1  0         0  1
        //                   1  1         1  1
        // i:2
        //                   2  0         0  0
        //                   2  1         1  0
        //
        //                   2  0         0  1
        //                   2  1         1  1
      }
    }
  }

  return product;
}

//
// === 문제 읽고 첫 느낌 ===
//   분명히 어려운 문제는 아닌데... 꼭 잘~ 못한다.
//   도무지 머리에 안그려짐. 😂
//
// === 다른 사람 풀이 확인 이후 의견 ===
// ...
//
//
