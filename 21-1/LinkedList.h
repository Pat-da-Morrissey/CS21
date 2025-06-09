/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  LinkedList.h - Assignment 01 (Review: Linked Lists; Stacks; Queues)
*/

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <string>

  class LinkedList{ // Creates a class where LinkedLists can be made

    private:
      struct Node { // Creates the nodes for the LinkedList
        std::string data;
	Node* next;
	Node* prev;
      };
      Node* head;
      Node* tail;
      size_t size = 0;
    public:

      LinkedList(); // Constructor
      ~LinkedList(); // Destructor

      void insert_rear(std::string data); // adds data to the tail of the list
      void insert_front(std::string data); // adds data to the head of the list
      std::string remove_rear(); // removes the current tail of the list
      std::string remove_front(); // removes the current head of the list
      bool is_empty(); //checks if empty
      size_t lsize(); // returns the size of the list

  };


#endif
