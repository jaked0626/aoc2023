#!/bin/bash

day=${1}

# Specify the dynamic value
inputFile="./day$day/input.txt"

# Read the template file and replace the placeholder
sed -e "s|input.txt|$inputFile|" -e "s|DAY X TASK X|DAY $day TASK 1|"  ./utils/template.cpp > ./day$day/task1.cpp
sed -e "s|input.txt|$inputFile|" -e "s|DAY X TASK X|DAY $day TASK 2|"  ./utils/template.cpp > ./day$day/task2.cpp
