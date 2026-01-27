@ECHO OFF
cls

if not exist build mkdir build

pushd build
gcc ../src/main.c -o main
main
popd
