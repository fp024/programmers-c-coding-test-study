@echo off
setlocal EnableDelayedExpansion

set "ROOT=%~dp0"
pushd "%ROOT%" >nul

rem 1) 초기화
set "CF_EXE="
set "DIRS="
set "EXTS="

rem 2) settings.properties 읽기
set "SETTINGS_FILE=%ROOT%settings.properties"
if exist "%SETTINGS_FILE%" (
  for /f "usebackq tokens=1,* delims== eol=#" %%A in ("%SETTINGS_FILE%") do (
    if /i "%%~A"=="CLANG_FORMAT_PATH" set "CF_EXE=%%~B"
    if /i "%%~A"=="TARGET_DIRS"      set "DIRS=%%~B"
    if /i "%%~A"=="TARGET_EXTS"      set "EXTS=%%~B"
  )
)

rem 쉼표 → 공백
if defined DIRS set "DIRS=%DIRS:,= %"
if defined EXTS set "EXTS=%EXTS:,= %"

rem 3) 인자 파싱: check는 모드로, 나머지는 디렉터리 목록으로 수집
set "FLAGS=-i"
set "MODE=apply"
set "DIRS_ARGS="

:arg_loop
if "%~1"=="" goto after_args
if /i "%~1"=="--check" (
  set "FLAGS=--dry-run -Werror"
  set "MODE=check"
) else (
  if defined DIRS_ARGS (set "DIRS_ARGS=%DIRS_ARGS% %~1") else (set "DIRS_ARGS=%~1")
)
shift
goto arg_loop

:after_args
if defined DIRS_ARGS set "DIRS=%DIRS_ARGS%"

rem 4) 검증
if "%DIRS%"=="" (
  echo No target directories specified. Set TARGET_DIRS in settings.properties or pass directories.
  popd >nul
  exit /b 2
)
if "%EXTS%"=="" (
  echo No target extensions specified. Set TARGET_EXTS in settings.properties, e.g. TARGET_EXTS=c,cpp,h
  popd >nul
  exit /b 2
)

rem 5) clang-format 결정
if not defined CF_EXE (
  for /f "delims=" %%P in ('where clang-format 2^>nul') do set "CF_EXE=%%P"
)
if not defined CF_EXE set "CF_EXE=C:\LLVM\21.x\bin\clang-format.exe"
if not exist "%CF_EXE%" (
  echo clang-format not found. Set CLANG_FORMAT_PATH in settings.properties or add to PATH.
  popd >nul
  exit /b 1
)

echo Running clang-format (!MODE!)
echo ROOT : %CD%
echo Tool : %CF_EXE%
echo Dirs : %DIRS%
echo Exts : %EXTS%
"%CF_EXE%" --version
echo.

set /a OK=0
set /a FAIL=0
set /a SCANNED=0
if defined DISABLE_FORMAT_SHOW_FILES (set "SHOW_FILES=0") else (set "SHOW_FILES=1")

for %%D in (%DIRS%) do (
  if exist "%ROOT%%%D" (
    echo [Dir] %%D
    set "STYLE_OPT="
    if exist "%ROOT%.clang-format" set "STYLE_OPT=-style=file"

    pushd "%ROOT%%%D" >nul
    for %%E in (%EXTS%) do (
      set "EXT=%%~E"
      for /R %%F in (*.!EXT!) do (
        if "!SHOW_FILES!"=="1" echo   %%F
        set /a SCANNED+=1
        "%CF_EXE%" !STYLE_OPT! !FLAGS! "%%F"
        if errorlevel 1 (set /a FAIL+=1) else (set /a OK+=1)
      )
    )
    popd >nul
  ) else (
    echo Skip: "%ROOT%%%D" not found.
  )
)

echo.
echo Done. Success: !OK!  Failures: !FAIL!  Scanned: !SCANNED!
popd >nul
if !FAIL! GTR 0 exit /b 1
exit /b 0
endlocal