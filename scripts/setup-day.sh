#!/bin/bash

# must provide cookie session information in .env file for this script to work.

source .env

today=$(date -u "+%-d")

day=${1:-$today}

if [ -d "./day$day" ]
then
  echo "Directory for this day has already been initialized"
  exit 1
fi

mkdir "./day$day"

bash scripts/seed-files.sh $day

curl "https://adventofcode.com/2023/day/$day/input" \
  -H "cookie: session=$SESSION" \
  --compressed > ./day$day/input.txt

if [ ! -f "./day$day/input.txt" ]
then
  echo "Failed to load input"
  exit 1
fi

