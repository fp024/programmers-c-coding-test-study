### 문제 소스 추가 ###
add_executable(Exam000_00000 Exam000_00000.c)

# C++ 테스트 (BUILD_TESTING이 ON일 때만)
if (BUILD_TESTING)
    add_coding_test(00 Exam000_00000)
endif ()
