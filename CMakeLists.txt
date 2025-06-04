cmake_minimum_required(VERSION 3.16)
project(programmers-c-coding-test-study C)

set(CMAKE_C_STANDARD 99)

if(WIN32)
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
    if(SYSTEM_CODEPAGE EQUAL 949)
        if(MSVC)
            # Visual Studio cl.exe를 사용할 때, 윈도우 터미널 환경은 CP949 인데,
            # 소스파일을 UTF-8로 저장해서 관리할 경우, 컴파일러 아래 옵션을 전달한다.
            add_compile_options(/source-charset:utf-8 /execution-charset:euc-kr)
            message(STATUS "Added MSVC charset options for CP949 system encoding")
        elseif(MINGW)
            add_compile_options(-fexec-charset=CP949 -g -W -Wall)
            message(STATUS "Added MinGW charset options for CP949 system encoding")
        endif()
    elseif(SYSTEM_CODEPAGE EQUAL 65001)
        if(MSVC)
            add_compile_options(/source-charset:utf-8 /execution-charset:utf-8)
            message(STATUS "Added MSVC charset options for UTF-8 system encoding")
        elseif(MINGW)
            add_compile_options(-fexec-charset=UTF-8 -g -W -Wall)
            message(STATUS "Added MinGW charset options for UTF-8 system encoding")
        endif()
    else()
        message(STATUS "Using system default encoding (Codepage: ${SYSTEM_CODEPAGE})")
    endif ()
endif()

# 공통 함수 모음 라이브러리
set(COMMON_LIB_PROJECT CommonUtils)
set(COMMON_LIB_NAME ${COMMON_LIB_PROJECT})

add_subdirectory(CommonUtils)

# 각 레벨별 하위 디렉토리 추가
add_subdirectory(lv00)
