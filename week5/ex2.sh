#!/bin/bash

# it takes few amount of time before executions started overlap each other

input="./text.txt"
while true
do
	if ln "$input" "$input.lock"
	then
		last_line="$(cat "$input" | tail -1)"
		next_line=$((last_line+1))
		echo "$next_line" >> "$input"
		echo "written $next_line"
		rm "$input.lock"
	fi
done

