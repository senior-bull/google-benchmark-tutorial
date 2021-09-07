#!/bin/sh

BENCH=$1

if [ "$BENCH" = "" ]
then
	echo "No BENCH passed"
fi

rm output

g++ -std=c++17 -O3 -mavx $BENCH -l benchmark -l pthread -o output

./output
