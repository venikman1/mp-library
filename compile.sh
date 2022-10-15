#!/bin/bash

g++ src/*.cpp -lboost_program_options -lboost_serialization -o build/binary --std=c++20 -I include
