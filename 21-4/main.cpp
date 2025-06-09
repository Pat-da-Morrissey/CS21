/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 4 (Radix Bucket Sort)
  The purpose of this assignment: To create a hybrid algorithm combining both bucketsort and radixsort. We will take in integer values into a vector and pass them into a the radixbucketsort function.
  From here the function will divide the vector into buckets with each bucket containing a value with an index from 0-9. The buckets will "pour" it's data back into the orginial vecotr replacing it.
  Finally it will loop indexing from the least significant to most significant value which will result in a sorted array.
  Code Status: Compiles, Runs (with datasets under 1 milliom), No memory leaks!
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "radixbucketsort.h"


  void PrintVector(std::vector<int> &A){
    for(int value : A) {
      std::cout << std::setfill('0') << std::setw(9) << value << std::endl;
    }
  }

  int main(int argc, char *argv[]){
    std::string input;
    std::vector<int> data;

    while(getline(std::cin, input)){
      data.push_back(std::stoi(input));
    }

    RadixBucketSort(data);
    PrintVector(data);

    return 0;
  }
