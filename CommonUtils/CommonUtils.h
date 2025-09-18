//
// 사용자 정의 단순 공통 구현 함수 라이브러리 프로젝트
//
// 타입에 대해서 제네릭처럼 가능하게 작성하면 좋을 수 있는데,
// 일단은 int 기준으로 만들고, 우선 책 내용에 집중하자!
//

#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

/**
 * 배열 내용 출력
 * @param array     배열
 * @param length    배열의 길이
 */
void printArray(int array[], int length);

/**
 * 배열 내용 단순하게 한줄 출력
 * @param array     배열
 * @param length    배열의 길이
 */
void printArraySimple(int array[], int length);

/**
 * 배열의 특정 인덱스 값을 서로 스왑
 * @param array     배열
 * @param aIndex    a 인덱스
 * @param bIndex    b 인덱스
 */
void swap(int array[], int aIndex, int bIndex);

/**
 * 중간값 구하기
 *
 * 자바 코드로 할 때는, 아래와 같이 했었는데,
 * https://github.com/fp024/java-study/blob/master/etc-project/src/main/java/org/fp024/java/study/sort/CommonUtils.java
 *
 * 여기서는 저자님 방식대로 해보자!
 * 문제 10-1에 해당.
 *
 * @param array             중간 값 인덱스를 구할 배열
 * @param firstIndex        앞쪽 범위 인덱스
 * @param lastIndex         마지막 인덱스
 * @return  중간 값의 인덱스
 */
int getMedianIndex(const int array[], int firstIndex, int lastIndex);

#endif  // COMMON_UTILS_H
