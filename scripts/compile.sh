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
  g++ --std=c++17 -o ./day$day/task1 ./day$day/task1.cpp
  exe_file="day$day/task1"
  ./"$exe_file"
fi

if [ -f "./day$day/task2.cpp" ]
then
  g++ --std=c++17 -o ./day$day/task2 ./day$day/task2.cpp
  exe_file="day$day/task2"
  ./"$exe_file"
fi

