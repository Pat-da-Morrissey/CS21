/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  quicksort.cpp - Assignment 03 (Quicksort)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "quicksort.h"


  VectorSorter::VectorSorter(std::vector<int> &A) {
    int p = 0;
    size = A.size();
    sort(A, p, size);
  }

  VectorSorter::~VectorSorter() {}

  int VectorSorter::medOf3(std::vector<int> &A, int front, int middle, int end) {
    if(A[front] >= A[middle] && A[front] <= A[end]) { // for the off chance that they're equal
      return front;
    }
    if(A[front] <= A[middle] && A[front] >= A[end]) {
      return front;
    }
    if(A[middle] >= A[front] && A[middle] <= A[end]) {
      return middle;
    }
    if(A[middle] <= A[front] && A[middle] >= A[end]) {
      return middle;
    }
    if(A[end] >= A[front] && A[end] <= A[middle]) {
      return end;
    }
    if(A[end] <= A[front] && A[end] >= A[middle]) {
      return end;
    }
    return 0;
  }

  void VectorSorter::sort(std::vector<int> &A, int p, int r) {
    if(p < r){
      int q = partition(A, p, r);
      sort(A, p, q-1);
      sort(A, q+1, r);
    }
  }

  int VectorSorter::partition(std::vector<int> &A, int left, int right) {
    if(right - left > mo3MinConst) { // constant
      int medium = medOf3(A, left, (right+left)/2, right);
      std::swap(A[medium], A[right]); // right is now the median
    }
        
    int pivot = A[right];
    int index = left-1;
    for(int scanner = left; scanner < right; ++scanner){
      if(A[scanner] <= pivot){ // to create the lower end
        index++;
        std::swap(A[index], A[scanner]);
      }
    }
    std::swap(A[index+1], A[right]);
    return index+1;
  }
  
  void VectorSorter::printVector(std::vector<int> A) {
    for(int data : A) {
      std::string output = std::to_string(data);
      if(output.size() != 9){
        std::string temp;
        for(int i = output.size(); i < 9; ++i) {
          temp += "0";
        }
        temp += output; // temp now has the leading zeros plus the rest of num
        output = temp;
      }
      std::cout << output << std::endl;
    }  
  }





