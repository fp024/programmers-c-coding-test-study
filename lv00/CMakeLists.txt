### 문제 소스 추가 ###
add_executable(Exam000_00000 Exam000_00000.c)
add_executable(Exam001_00001 Exam001_00001.c)


### 공통 라이브러리를 사용한다면 INCLUDE 설정 ###
# Exam000_00000에 공통 라이브러리 링크
target_include_directories(Exam000_00000 PRIVATE ../${COMMON_LIB_PROJECT})
target_link_directories(Exam000_00000 PRIVATE ../cmake-build-debug/${COMMON_LIB_PROJECT})
target_link_libraries(Exam000_00000 PRIVATE ${COMMON_LIB_NAME})

# Exam000_00001에 공통 라이브러리 링크
target_include_directories(Exam001_00001 PRIVATE ../${COMMON_LIB_PROJECT})
target_link_directories(Exam001_00001 PRIVATE ../cmake-build-debug/${COMMON_LIB_PROJECT})
target_link_libraries(Exam001_00001 PRIVATE ${COMMON_LIB_NAME})