/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  stack.h - Assignment 01 (Review: Linked Lists; Stacks; Queues)
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "LinkedList.h"

  class stack{

   private:
  
    LinkedList List;
 
   public:

    stack() {}; // creates a empty default constructor/stack
    void push_front(std::string data); // pushes data to the top of the stack
    std::string pop_front();  // pops data from the top of the stack and returns the data
    bool isEmpty(); // checks if empty

  };

#endif
