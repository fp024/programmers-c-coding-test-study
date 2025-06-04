project(CommonUtils C)

# SHARED로 사용하려면, exe 실행경로와 dll의 경로를 같은 위치에 두거나 해당 dll이 PATH 환경변수에 있어야해서, 일단 정적으로 두자!
add_library(CommonUtils STATIC CommonUtils.c)
