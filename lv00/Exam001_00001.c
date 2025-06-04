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