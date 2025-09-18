@echo off
setlocal EnableDelayedExpansion

rem 사용법:
rem   format_all.bat [check] [dir1 dir2 ...]
rem 우선순위: CLI 인자 > settings.properties > 기본값

set ROOT=%~dp0
pushd "%ROOT%" >nul

rem 1) 기본값
set CF_EXE=
set DIRS=
set EXTS=

rem 2) settings.properties 읽기 (있으면 적용)
set SETTINGS_FILE=%ROOT%\settings.properties
if exist "%SETTINGS_FILE%" (
  for /f "usebackq tokens=1,* delims== eol=#" %%A in ("%SETTINGS_FILE%") do (
    set KEY=%%A
    set VAL=%%B
    rem 앞뒤 공백 제거
    for /f "tokens=*" %%K in ("!KEY!") do set KEY=%%K
    for /f "tokens=*" %%V in ("!VAL!") do set VAL=%%V
    if /i "!KEY!"=="CLANG_FORMAT_PATH" set CF_EXE=!VAL!
    if /i "!KEY!"=="TARGET_DIRS" set DIRS=!VAL!
    if /i "!KEY!"=="TARGET_EXTS" set EXTS=!VAL!
  )
)

rem 쉼표 구분자를 공백으로 치환 (TARGET_DIRS=CommonUtils,lv00,...)
if defined DIRS (
  set DIRS=%DIRS:,= %
)
if defined EXTS (
  set EXTS=%EXTS:,= %
)

rem 3) CLI 인자 처리: check 모드 및 디렉터리 오버라이드
set FLAGS=-i
set MODE=apply
if /i "%~1"=="check" (
  set FLAGS=--dry-run -Werror
  set MODE=check
  shift
)

if not "%*"=="" (
  set DIRS=%*
)

rem 4) 최종 DIRS 결정
if "%DIRS%"=="" (
  echo No target directories specified.
  echo Set TARGET_DIRS in settings.properties or pass directories as arguments.
  popd >nul
  exit /b 2
)

rem 4.1) 확장자 목록 검증 (settings.properties의 TARGET_EXTS 필수)
if "%EXTS%"=="" (
  echo No target extensions specified.
  echo Set TARGET_EXTS in settings.properties, e.g. TARGET_EXTS=c,cpp,h
  popd >nul
  exit /b 2
)

rem 5) clang-format 경로 결정: 설정값 우선, 없으면 PATH 검색
if not defined CF_EXE (
  for /f "delims=" %%i in ('where clang-format 2^>nul') do set CF_EXE=%%i
)
if not defined CF_EXE set CF_EXE=C:\LLVM\21.x\bin\clang-format.exe

if not exist "%CF_EXE%" (
  echo clang-format not found. Checked: settings.properties, PATH, default path.
  echo Set CLANG_FORMAT_PATH in settings.properties or add to PATH.
  popd >nul
  exit /b 1
)

echo Running clang-format (%MODE%)
echo ROOT : %CD%
echo Tool : %CF_EXE%
echo Dirs : %DIRS%
echo Exts : %EXTS%
"%CF_EXE%" --version
echo.

set /a OK=0
set /a FAIL=0
set /a SCANNED=0
set /a SHOW_FILES=1

rem 파일명을 출력하지 않으려면 환경변수 DISABLE_FORMAT_SHOW_FILES=1 설정
if defined DISABLE_FORMAT_SHOW_FILES (
  set SHOW_FILES=0
)

for %%D in (%DIRS%) do (
  if exist "%ROOT%%%D" (
    echo [Dir] %%D
    rem .clang-format가 있으면 -style=file 사용
    set STYLE_OPT=
    if exist "%ROOT%.clang-format" set STYLE_OPT=-style=file

    for %%E in (%EXTS%) do (
      set "EXT=%%E"
      rem for의 /R 이후에 타겟 디렉토리에대한 확장변수 식을 사용할 수가 없어 직접 디렉토리를 변경한다.
      pushd %ROOT%%%D"
      for /R %%F in (*.!EXT!) do (
        if defined SHOW_FILES echo   %%F
        set /a SCANNED+=1
        "%CF_EXE%" !STYLE_OPT! %FLAGS% "%%F"
        if errorlevel 1 (
          set /a FAIL+=1
        ) else (
          set /a OK+=1
        )
      )
      popd >nul
    )
  ) else (
    echo Skip: "%ROOT%%%D" not found.
  )
)

echo.
echo Done. Success: %OK%  Failures: %FAIL%  Scanned: %SCANNED%
popd >nul

if %FAIL% GTR 0 exit /b 1
exit /b 0
endlocal