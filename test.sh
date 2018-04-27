#!/bin/bash
program=bridges

g++ -std=c++11 main.cpp -o $program

for graph in examples/*.txt
do
  echo "-- TEST $graph --"
  ./$program < $graph
done
