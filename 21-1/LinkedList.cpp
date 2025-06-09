/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  LinkedList.cpp - Assignment 01 (Review: Linked Lists; Stacks; Queues)
*/

#include <iostream>
#include <string>
#include "LinkedList.h"


  LinkedList::LinkedList() { // Default Constructor
    head = NULL;
    tail = NULL;
  };

  LinkedList::~LinkedList() {
   while (this->head) {            // for every head
      Node *old_head = this->head; // find the last head
      this->head = old_head->next; // reassign the next
      delete old_head;             // delete
    }
  }

  void LinkedList::insert_rear(std::string data) { // adds data to the tail regardless of size
    Node *new_node = new Node{data};
    if (size == 0) {
      this->head = this->tail = new_node;
    } else {
      this->tail->next = new_node;
      new_node->prev = this->tail;
      this->tail = new_node;
    }
    ++size;
  } 

  void LinkedList::insert_front(std::string data) { // adds data to the head regardless of size
    Node *new_node = new Node{data};
    if (size == 0) {
      this->head = this->tail = new_node;
    } else {
      new_node->next = this->head;
      this->head->prev = new_node;
      this->head = new_node;
    }
    ++size;   
  }

  std::string LinkedList::remove_rear() { // removes data from the tail
    if (size == 0) {
      throw std::logic_error("The List is empty");
    }
    if (size == 1) {
      std::string first_node_data = this->head->data;
      delete head;
      this->head = this->tail = nullptr;
      --size;
      return first_node_data;
    }
    if (size > 1) {
      std::string node_data = this->head->data;
      Node *fin_delet = this->tail;
      this->tail->prev->next = nullptr;
      this->tail = this->tail->prev;
      delete fin_delet;
      --size;
      return node_data;
    }
    return "Empty List";
  }

  std::string LinkedList::remove_front() { // removes data from the head
    if (size == 0) {
      throw std::logic_error("The List is empty");
    }
    if (size == 1) {
      std::string first_node_data = this->head->data;
      delete head;
      this->head = this->tail = nullptr;
      --size;
      return first_node_data;
    }
    if (size > 1) {
      std::string node_data = this->head->data;
      Node *fin_delet = this->head;
      this->head->next->prev = nullptr;
      this->head = this->head->next;
      delete fin_delet;
      --size;
      return node_data;
    }
    return "Empty List";
  }

  bool LinkedList::is_empty() { // How does this work?
    return size == 0;
  }

  size_t LinkedList::lsize() { // returns the size
    return size;
  }






