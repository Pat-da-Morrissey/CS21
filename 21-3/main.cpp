/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 3 (Quicksort)
  The purpose of this assignment: To create a quicksort algorithm that takes in vectors filled with unsorted numbers, it will be quicksorted and print out. During quicksort it will partition the vector into 
  sub vectors sorting those recursively. To make the sort more effieciently a helper function called medof3 will take the median number of the first, middle, and last index to increase the chance of 
  making a better partition.
  Code Status: Quicksort compiles and runs effieciently with no memory leaks
*/


#include <iostream>
#include <vector>
#include <string>
#include "quicksort.h"

int main(int argc, char *argv[]){
  std::string input;
  std::vector<int> data;
  
  while(std::getline(std::cin, input)){  
    data.push_back(stoi(input));
  }

  VectorSorter List(data);
  List.printVector(data);
 
  return 0;
}
