/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  heap.h - Assignment 02 (Integer Minimun Heap and Priority Queues)
*/

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <utility>
#include <string>

  // integer minimum heap with PQ 
  class intMinHeap{
    public:
      intMinHeap(int init_capacity);  // empty heap wth this capacity
      ~intMinHeap();  // clean up allocated memory  
      std::pair<int *, int> heapsort();  // return sorted array and size from heap
      std::string toString();  
      bool heapinsert(int); // add element to heap; return success 
      int minimum();  // return value of A[root]
      int extractmin(); // return and remove A[root]
      void decreasekey(int i, int k);  // A[i] decreased to k
      bool isEmpty();
      bool isFull();
  
    private:
      int minOf3(int curr, int left_bound, int right_bound) { // return the smallest value of the 3 with bounds check!
        int min = curr;
          if(left_bound < size && A[left_bound] < A[min]) {
            min = left_bound;
          }
          if(right_bound < size && A[right_bound] < A[min]) {
            min = right_bound;
          }
          return min;
      }

      int left(int i) {return (i * 2) +1;}
      int right(int i) {return (i * 2) +2;}
      int parent(int i) {return (i - 1) /2;}	
      
      inline void buildheap(); // converts the array into a heap through heapify
      inline void heapify(int i);  // checks for violations and corrects them

      int *A;  // array of integers - data
      int capacity; // size of array A
      int size; // data size in array
  };

#endif
