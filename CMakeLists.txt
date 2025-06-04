cmake_minimum_required(VERSION 3.16)
project(programmers-c-coding-test-study C CXX)  # C++도 추가 (테스트용)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)  # Google Test용

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

# 테스트 빌드 옵션
option(BUILD_TESTING "Build tests with Google Test" ON)

# Google Test 설정 (테스트가 활성화된 경우에만)
if (BUILD_TESTING)
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
    enable_testing()

    message(STATUS "Google Test enabled for testing")
endif ()


# 공통 함수 모음 라이브러리
set(COMMON_LIB_PROJECT CommonUtils)
set(COMMON_LIB_NAME ${COMMON_LIB_PROJECT})

add_subdirectory(CommonUtils)

# 전체 테스트 실행을 위한 커스텀 타겟 (테스트가 활성화된 경우에만)
if (BUILD_TESTING)
    add_custom_target(run_all_tests
            COMMAND ${CMAKE_CTEST_COMMAND} --verbose --output-on-failure
            COMMENT "Running all tests"
            USES_TERMINAL
    )
endif ()

# 각 레벨별 하위 디렉토리 추가
add_subdirectory(lv00)
