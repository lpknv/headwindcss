@ECHO OFF
cls
if exist build rmdir /S /Q build

mkdir build
pushd build
gcc ../src/main.c -o main
main %1
popd
