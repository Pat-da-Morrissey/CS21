/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  radixbucketsort.cpp - Assignment 4 (Radix Bucket Sort)
*/

#include <iostream>
#include <vector>
#include <cmath>
#include "radixbucketsort.h"

  void RadixBucketSort(std::vector<int> &A){
    
    int n = A.size();
    int d = 9;
    int k = 10;

    std::vector<int> Bay[k]; // the buckets go into the bay

    for(int i = 1; i <= d; ++i) { // i is index
      for(int j = 0; j < n; ++j) { // j loops through the array
        int r = static_cast<int>(A[j] / std::pow(10, i - 1)) % 10; 
        Bay[r].push_back(A[j]);
      }
      A.clear();
      for(int b = 0; b < k; ++b) { // loops through the buckets
        for(int p = 0; p < Bay[b].size(); ++p) {
          A.push_back(Bay[b][p]);
        }
        Bay[b].clear();
      }
    }
  }
