### 문제 소스 추가 ###
add_executable(Exam000_00000 Exam000_00000.c)

# C++ 테스트 (BUILD_TESTING이 ON일 때만)
if (BUILD_TESTING)
    add_executable(Exam000_00000_test
            Exam000_00000_test.cpp
            Exam000_00000.c
    )
    target_include_directories(Exam000_00000_test PRIVATE ../${COMMON_LIB_PROJECT})
    target_link_directories(Exam000_00000_test PRIVATE ../cmake-build-debug/${COMMON_LIB_PROJECT})
    target_link_libraries(Exam000_00000_test
            ${COMMON_LIB_NAME}
            gtest
            gtest_main
            gmock
            gmock_main
    )
    add_test(NAME lv00_Exam000_00000 COMMAND Exam000_00000_test)

endif ()
