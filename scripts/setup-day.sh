#!/bin/bash

# must provide cookie session information in .env file for this script to work.

source .env

today=$(date -u "+%-d")

day=${1:-$today}

if [ ! -d "./day$day" ]
then
  mkdir "./day$day"
fi

curl "https://adventofcode.com/2023/day/$day/input" \
  -H "cookie: session=$SESSION" \
  --compressed > ./day$day/input.txt

