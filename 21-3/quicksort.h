/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  quicksort.h - Assignment 03 - Quicksort
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>

  class VectorSorter{
   public:
    VectorSorter(std::vector<int> &A);
    ~VectorSorter();
    void sort(std::vector<int> &A, int p, int r);
    int medOf3(std::vector<int> &A, int front, int middle, int end);
    int partition(std::vector<int> &A, int left, int right); // without the & i would be modifying a passed in copy in sense 
    void printVector(std::vector<int> A);
    
   private:
    const int mo3MinConst = 15;
    int size;
 
  };

#endif
