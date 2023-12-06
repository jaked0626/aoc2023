#!/bin/bash



source .env

today=$(date -u "+%-d")

day=${1:-$today}

if [ ! -d "./day$day" ]
then
  exit 1
fi

if [ -f "./day$day/task1.cpp" ]
then
  g++ --std=c++17 -I ./utils/ -o ./day$day/task1.out ./day$day/task1.cpp ./utils/utils.cpp
  exe_file="day$day/task1.out"
  ./"$exe_file"
fi

if [ -f "./day$day/task2.cpp" ]
then
  g++ --std=c++17 -I ./utils/ -o ./day$day/task2.out ./day$day/task2.cpp ./utils/utils.cpp
  exe_file="day$day/task2.out"
  ./"$exe_file"
fi

