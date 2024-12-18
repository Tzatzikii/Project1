#!/bin/bash

init=$1

if [ -n "$init" -a "$init" = "init" ]; then
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Debug ../src/main
    cd ..
    echo "Initialized CMake"  
fi
cmake --build build