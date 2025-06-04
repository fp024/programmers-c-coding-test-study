//
// 공통 사용자 정의 함수 유틸리티 라이브러리
//
#include <stdio.h>
#include "CommonUtils.h"

void printArray(int array[], const int length) {
  for (int i = 0; i < length; i++) {
    printf("array[%d]= %d\n", i, array[i]);
  }
}

void printArraySimple(int array[], const int length) {
  for (int i = 0; i < length; i++) {
    if (i == length - 1) {
      printf("%d\n", array[i]);
      break;
    }
    printf("%d, ", array[i]);
  }
}

void swap(int array[], const int aIndex, const int bIndex) {
  const int temp = array[aIndex];
  array[aIndex] = array[bIndex];
  array[bIndex] = temp;
}


int getMedianIndex(const int array[], const int firstIndex, const int lastIndex) {
  int indexArray[] = {firstIndex, (firstIndex + lastIndex) / 2, lastIndex};

  if (array[indexArray[0]] > array[indexArray[1]]) {
    swap(indexArray, 0, 1);
  }

  if (array[indexArray[1]] > array[indexArray[2]]) {
    swap(indexArray, 1, 2);
  }

  if (array[indexArray[0]] > array[indexArray[1]]) {
    swap(indexArray, 0, 1);
  }

  return indexArray[1];
}