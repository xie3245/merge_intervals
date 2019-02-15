#!/bin/bash 

cmake -H. -Bbuild
cmake --build build/ -- -j3
./build/bin/interval_merge_tests
