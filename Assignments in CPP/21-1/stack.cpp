/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  stack.cpp - Assignment 01 (Review: Linked Lists; Stacks; Queues)
*/

#include "stack.h"
#include <iostream>
#include <string>

  void stack::push_front(std::string data){
    List.insert_front(data);
  }

  std::string stack::pop_front(){
    return List.remove_front();
  }

  bool stack::isEmpty(){
    return List.is_empty();    
  }
  
