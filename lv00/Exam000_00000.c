#include "CommonUtils.h"

void BubbleSort(int arr[], const int length) {
  for (int i = 0; i < length - 1; i++) {
    // 아래 반복문 조건 잘못 설정했었음.
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
      printArraySimple(arr, length);
    }
  }
}

int main() {
  int numbers[] = {3, 2, 4, 1};
  const int length = sizeof(numbers) / sizeof(int);
  BubbleSort(numbers, length);
  return 0;
}

/*
 처음에 for (int j = 0; j < ((length - i) - 1); j++)  처럼 써야하는데..
 내부 반복문을 아래와 같이 최대 가능 범위를 -1을 해줘야하는데 해주지 않아
 아래와 같은 오류를 경험했다.

 2, 3, 4, 1
 2, 3, 4, 1
 2, 3, 1, 4
 2, 3, 1, -858993460  <==  arr[3] 과 arr[4] 와 값 교환이 수행되어 쓰래기 값이 들어갔다. (4는 배열의 범위를 초과함.)
 2, 3, 1, -858993460
 2, 1, 3, -858993460
 2, 1, -858993460, 3
 1, 2, -858993460, 3
 1, -858993460, 2, 3
 */