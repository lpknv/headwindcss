@ECHO OFF
cls

if not exist build mkdir build

pushd build
gcc ../main.c -o main
main
popd
