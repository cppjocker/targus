@echo off

set PRJ_NAME=test_argus
set PRJ_DIR=%PRJ_NAME%
set BUILD_DIR=%PRJ_DIR%-build

mkdir "..\%BUILD_DIR%"
cd "..\%BUILD_DIR%"

cmake -DCMAKE_CONFIGURATION_TYPES="Release"  -G "Visual Studio 15 2017 Win64" "..\%PRJ_DIR%"
if %ERRORLEVEL% neq 0 goto :exit

#MSBuild.exe "targus.sln" /maxcpucount /p:Target=targus /p:Configuration=Release

MSBuild.exe "targus.sln" /maxcpucount /p:Configuration=Release 

:exit
cd "..\%PRJ_DIR%"
