/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 02 (Integer Minimun Heap and Priority Queues)
  The purpose of this assignment is to: Create a min heap that can store integers up to any size (in this case 2400000) and be able to store it in an array.
  After taking in input from a text file it will go into the heap and start to sort itself through the decrease key function. When certain inputs are put in 
  (0, -1, -2) the function will preform certain tasks from printing the array, extracting the min, and even resorting the array through heapsort into a new array.
  Code Status: Code passes sample test case without memory leaks! More testing underway
*/

#include <iostream>
#include <string>
#include "heap.h"

int main(int argc, char *argv[]) {
  std::string input;
  intMinHeap myHeap(2400000); // empty heap with size 240000

  while(std::getline(std::cin, input)) {
    int data = std::stoi(input);
    if(data == 0) { 
      std::cout << myHeap.toString() << std::endl;
    } else if(data == -1) {
      std::cout << "extract min: " << myHeap.extractmin() << std::endl;
    } else if(data == -2) {
      std::pair<int* , int> sort = myHeap.heapsort();
      std::cout << "sorted array: [";
      for(int i = 0; i < sort.second; ++i) {
        std::cout << sort.first[i];
        if(i < sort.second-1){
          std::cout << ", ";
        }
      }
      std::cout << "]" << std::endl;
      delete[] sort.first;
    } else {
      std::cout << "insert: " << data << std::endl;
      myHeap.heapinsert(data);
    }
  }

  return 0;
}
