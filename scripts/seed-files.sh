#!/bin/bash

day=${1}

# Specify the dynamic value
inputFile="./day$day/input.txt"

# Read the template file and replace the placeholder
sed "s|input.txt|$inputFile|" ./utils/template.cpp > ./day$day/task1.cpp
sed "s|input.txt|$inputFile|" ./utils/template.cpp > ./day$day/task2.cpp