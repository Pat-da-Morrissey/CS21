/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 07 (Binary Search Tree)
  The purpose of this assignment is to: Create a program that takes in any integear values and stores it in a binary search tree. From here the user can search for the stored element, delete it, print it with
  3 different traversal modes, and determine the max and min values of the tree. The tree is situated where the each value (except the child branches) will have a predecessor value to its left and a successor
  value to it's right forming the tree. The user can also check these values for an existing key.
  Code Status: Complies, runs, and passed several test cases
*/
#include <iostream>
#include <string>
#include <vector>
#include "BinarySearchTree.h"

int main() {
  std::string input;
  BinarySearchTree myTree;

  while(std::getline(std::cin, input)){
    if(input[0] != '#') { // ignor all lines that start with #
      if(input == "min") { // simple check for 1 word commands
        std::vector<int> isMin = myTree.return_min();
        if(isMin.empty()) {
          std::cout << "tree empty" << std::endl;
        } else {
          std::cout << "min is " << isMin[0] << "." << std::endl; // What if empty tree?
        }
      } else if (input == "max") {
        std::vector<int> isMax = myTree.return_max();
          if(isMax.empty()) {
            std::cout << "tree empty" << std::endl;
          } else {
            std::cout << "max is " << isMax[0] << "." << std::endl;
          }
      } else if(input == "inorder") {
        std::cout << "inorder traversal:" << std::endl;
        std::vector<int> order = myTree.inorder();
        for(std::size_t i = 0; i < order.size(); ++i) {
          std::cout << order[i];
          if(i < order.size() - 1)
            std::cout << " ";
        }
        std::cout << std::endl;
      } else if(input == "postorder") {
        std::cout << "postorder traversal:" << std::endl;
        std::vector<int> order = myTree.postorder();
        for(std::size_t i = 0; i < order.size(); ++i) {
          std::cout << order[i];
          if(i < order.size() - 1)
            std::cout << " ";
        }
        std::cout << std::endl;
      } else if(input == "preorder") {
        std::cout << "preorder traversal:" << std::endl;
        std::vector<int> order = myTree.preorder();
        for(std::size_t i = 0; i < order.size(); ++i) {
          std::cout << order[i];
          if(i < order.size() - 1)
            std::cout << " ";
        }
        std::cout << std::endl;
      } else { // for command with value commands
        std::string command;
        std::string temp_val;
        for(std::size_t i = 0; i < input.size(); ++i) {
          if(i < input.find_first_of(' ')) {
            command += input[i];
          } else if (i > input.find_first_of(' ')) {
            temp_val += input[i];
          }
        }
        int key = std::stoi(temp_val);
        if(command == "insert") {
          myTree.insert(key);
          std::cout << "inserted " << key << "." << std::endl;
        } else if (command == "search") {
          if(myTree.search(key)) {
            std::cout << key << " found." << std::endl;
          } else {
            std::cout << key << " not found." << std::endl;
          }
        } else if (command == "delete") {
          bool is_removed = myTree.delete_node(key);
          if(is_removed) { // returns true if deleted
            std::cout << "deleted " << key << "." << std::endl;
          } else {
            std::cout << "delete " << key << " - not found." << std::endl;
          }
        } else if (command == "successor") {
          if(myTree.successor(key) == key) { // no successor
            std::cout << "no successor for " << key << "." << std::endl;
          } else if (myTree.successor(key) == key - 1) { // not in tree
            std::cout << key << " not in tree." << std::endl;
          } else { // in tree
            std::cout << key << " successor is " << myTree.successor(key) << "." << std::endl;
          }
        } else if (command == "predecessor") {
          if(myTree.predecessor(key) == key) { // no predecessor
            std::cout << "no predecessor for " << key << "." << std::endl;
          } else if (myTree.predecessor(key) == key + 1) { // not in tree
            std::cout << key << " not in tree." << std::endl;
          } else { // in tree
            std::cout << key << " predecessor is " << myTree.predecessor(key) << "." << std::endl;
          }
        }
      }
    }
  }


  return 0;
}
