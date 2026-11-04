#!/bin/sh

# make clean
# make

verify_dir="$1"
searchstr="$2"

if [ -z "$verify_dir" ] || [ -z "$searchstr" ]; then
    echo "Error: Parameters missing. Usage: $0 <directory> <search-string>"
    exit 1
fi

if [ ! -d "$verify_dir" ]; then
    echo "Error: Directory $verify_dir does not exist."
    exit 1
fi

num_files=$(find "$verify_dir" -type f | wc -l)
num_matching_lines=$(grep -r "$searchstr" "$verify_dir" | wc -l)

echo "The number of files are $num_files and the number of matching lines are $num_matching_lines"