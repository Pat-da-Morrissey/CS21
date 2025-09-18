/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 01 (Review: LinkedList; Stacks; Queues)
  The purpose of this program is to take in input from stdin and pass in each line into a stack which will put it into a LinkedList. 
  Once the list has been made it will print out the data by deleting the front of each node.
  Code Status: Compiles, No warnings, working, needs to test large files
*/

#include <iostream>
#include <string>
#include "stack.h"

int main(int argc, char *argv[]) {
  std::string input;

  stack List;
  if(std::getline(std::cin, input)){ // fails if the input is blank
    List.push_front(input); // gets the first input then passes into the stack
    while(std::getline(std::cin, input)){ // input is the buffer
      if(!std::cin.fail()){
        List.push_front(input);
      }
    }
  }
  while (!List.isEmpty()){
    std::cout << List.pop_front() << std::endl;
  }
  return 0;
}
