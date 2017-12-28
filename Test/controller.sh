#!/bin/bash

mkdir tmp
g++ -std=c++11 checker_v2.cpp -o tmp/checker
for i in range {1..8}
do
	echo "Test Case $i"
	./project4 public/expr$i.txt public/input$i.txt tmp/user_result$i.txt tmp/user_derivative$i.txt
	echo "Result"
	tmp/checker public/result$i.txt tmp/user_result$i.txt
	echo "Derivative"
	tmp/checker public/derivative$i.txt tmp/user_derivative$i.txt
	echo ""
done
rm -r tmp
