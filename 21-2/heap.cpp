/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  heap.cpp - Assignment 02 (Integer Minimun Heap and Priority Queues)
*/

#include <iostream>
#include <utility>
#include <string>
#include "heap.h"

  intMinHeap::intMinHeap(int init_capacity) { 
    capacity = init_capacity;
    A = new int[capacity];
    size = 0;
  }

  intMinHeap::~intMinHeap() { // clean up allocated memory  
    delete[] A;
  }

  std::pair<int *, int> intMinHeap::heapsort() { // return sorted array and size from heap
    int backup_size = size;
    int* A_copy = new int[size]; // to reassign and sort A then pass
    for(int i = 0; i < size; ++i){ // makes the copy
      A_copy[i] = A[i];
    }
    int* A_backup = A; // points to A block of memory as a backup
    A = A_copy; // now A points to A_copy to swap it's data
    for(int i = size-1; i >= 0; i--) {
      std::swap(A[0], A[i]);
      size--;
      heapify(0);
    }
    A = A_backup; // restores A to it's original
    size = backup_size;
    return {A_copy, size};
  }

  std::string intMinHeap::toString() { // outputs a string with the sorted heap
    std::string output = "heap size ";
    output += std::to_string(size);
    output += ": ";
    for(int i = 0; i < size; ++i) {
      output += std::to_string(A[i]);
      if(i != size-1) {
        output += ", ";
      }
    }
    return output;
  }
  
  bool intMinHeap::heapinsert(int value) { // add element to heap; return success
    if(!isFull()) {
      size++;
      A[size-1] = value+1;
      decreasekey(size-1, value);
      return true;
    }
    return false;
  }
   
  int intMinHeap::minimum() { // return value of A[root]
    if(isEmpty()){
      return 0;
    }
    int min = A[0];
    return min;
  }

  int intMinHeap::extractmin() { // return and remove A[root] replaces with the last leaf then heapifys
    if(isEmpty()){
      return 0;
    }
    int min = A[0];
    A[0] = A[size-1];
    size--;
    heapify(0);
    return min;
  }

  void intMinHeap::decreasekey(int i, int k) { // A[i] decreased to k
    if(A[i] <= k || i < 0 || i > size){
     return;
    }
    A[i] = k;
    while (i > 0 && A[parent(i)] > A[i]){
      std::swap(A[i], A[parent(i)]);
      i = parent(i);
    }
  }

  bool intMinHeap::isEmpty() {
    return size == 0;
  }

  bool intMinHeap::isFull() {
    return capacity == size;
  }

  void intMinHeap::buildheap() { // converts the array into a heap through heapify
    for(int i = size/2-1; i >= 0; i--){
      heapify(i);
    }
  }

  void intMinHeap::heapify(int i) {  // checks for violations and corrects them
    int n = minOf3(i, left(i), right(i));
    if(n != i){
      std::swap(A[i],A[n]);
      heapify(n);
    }
 }
