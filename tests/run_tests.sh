#!/bin/bash

TESTS=()

for FILE in *.cpp; do
	TESTS+=("$FILE")
done

# ${var%Pattern}
#     Remove from $var the shortest part of $Pattern that matches the back end
#     of $var.

for TEST in "${TESTS[@]}"; do
	g++ -std=c++11 "$TEST" -g -Wall -o "test_exe_${TEST%.*}"
done

for TEST in test_exe_*; do
	printf "Running test: ${TEST##test_exe_}\n"
	./"$TEST"
done

for TEST in test_exe_*; do
	rm -v "$TEST"
done

