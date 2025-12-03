cmake_minimum_required(VERSION 4.0.2)

project(programmers-c-coding-test-study C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# compile_commands.json가 항상 생성되도록 설정
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 빌드 시 compile_commands.json를 루트로 자동 복사
add_custom_target(copy_compile_commands ALL
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${CMAKE_BINARY_DIR}/compile_commands.json"
		"${CMAKE_SOURCE_DIR}/compile_commands.json"
	DEPENDS "${CMAKE_BINARY_DIR}/compile_commands.json"
	COMMENT "Copy compile_commands.json to project root"
	VERBATIM
)

if (WIN32)
    # Windows 시스템 로케일 확인을 위한 함수
    function(get_system_encoding result)
        execute_process(
                COMMAND powershell.exe -NoProfile -Command "[System.Text.Encoding]::Default.WindowsCodePage"
                OUTPUT_VARIABLE codepage
                OUTPUT_STRIP_TRAILING_WHITESPACE
                ERROR_QUIET
        )
        set(${result} ${codepage} PARENT_SCOPE)
    endfunction()

    # 시스템 인코딩 확인
    get_system_encoding(SYSTEM_CODEPAGE)

    # CP949(MS949), CP65001(UTF-8)인 경우에 EUC-KR 또는 UTF-8 실행 문자셋 옵션 추가
    if (SYSTEM_CODEPAGE EQUAL 949)
        if (MSVC)
            # Visual Studio cl.exe를 사용할 때, 윈도우 터미널 환경은 CP949 인데,
            # 소스파일을 UTF-8로 저장해서 관리할 경우, 컴파일러 아래 옵션을 전달한다.
            add_compile_options(/source-charset:utf-8 /execution-charset:euc-kr)
            message(STATUS "Added MSVC charset options for CP949 system encoding")
        elseif (MINGW)
            add_compile_options(-fexec-charset=CP949 -g -W -Wall)
            message(STATUS "Added MinGW charset options for CP949 system encoding")
        endif ()
    elseif (SYSTEM_CODEPAGE EQUAL 65001)
        if (MSVC)
            add_compile_options(/source-charset:utf-8 /execution-charset:utf-8)
            message(STATUS "Added MSVC charset options for UTF-8 system encoding")
        elseif (MINGW)
            add_compile_options(-fexec-charset=UTF-8 -g -W -Wall)
            message(STATUS "Added MinGW charset options for UTF-8 system encoding")
        endif ()
    else ()
        message(STATUS "Using system default encoding (Codepage: ${SYSTEM_CODEPAGE})")
    endif ()
endif ()

# 공통 함수 모음 라이브러리
set(COMMON_LIB_PROJECT CommonUtils)
set(COMMON_LIB_NAME ${COMMON_LIB_PROJECT})
add_subdirectory(CommonUtils)

# Google Test 설정
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

# Google Test의 설정이 우리 프로젝트에 영향주지 않도록
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# 💡 gmock을 같이 빌드한다. gmock에서 제공되는 matcher가 다양함.
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# GoogleTest 빌드 후 경고 억제 설정
foreach(tgt gtest gtest_main gmock gmock_main)
    if(TARGET ${tgt})
        target_compile_options(${tgt} PRIVATE -Wno-character-conversion)
    endif()
endforeach()

enable_testing()

message(STATUS "Google Test enabled for testing")

# 테스트 이름 생성 함수
function(get_test_target_name LEVEL PROBLEM_ID OUTPUT_VAR)
    set(${OUTPUT_VAR} "lv${LEVEL}_${PROBLEM_ID}_test" PARENT_SCOPE)
endfunction()

# CommonUtils 연결 함수
function(link_common_utils LEVEL PROBLEM_ID)
    get_test_target_name(${LEVEL} ${PROBLEM_ID} TARGET_NAME)
    target_include_directories(${TARGET_NAME} PRIVATE ../${COMMON_LIB_PROJECT})
    target_link_libraries(${TARGET_NAME} ${COMMON_LIB_NAME})
endfunction()


# 테스트 파일 설정 추가를 위한 공통 함수
function(add_coding_test LEVEL PROBLEM_ID EXTENSION)
    get_test_target_name(${LEVEL} ${PROBLEM_ID} TEST_NAME)
    set(TEST_SOURCE_FILE "${PROBLEM_ID}_test.cpp")
    set(TARGET_SOURCE_FILE "${PROBLEM_ID}.${EXTENSION}")

    add_executable(${TEST_NAME}
            ${TEST_SOURCE_FILE}
            ${TARGET_SOURCE_FILE}
    )

    # gtest 라이브러리 링크
    target_link_libraries(${TEST_NAME}
            gtest gtest_main gmock gmock_main
    )

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction()

# 전체 테스트 실행을 위한 커스텀 타겟
add_custom_target(run_all_tests
        COMMAND ${CMAKE_CTEST_COMMAND} --verbose --output-on-failure
        COMMENT "Running all tests"
        USES_TERMINAL
)

# 각 레벨별 하위 디렉토리 추가, 빌드가 필요없을 경우 주석으로 둔다.
add_subdirectory(lv00)
add_subdirectory(lv01)
add_subdirectory(lv02)
add_subdirectory(lv03)
