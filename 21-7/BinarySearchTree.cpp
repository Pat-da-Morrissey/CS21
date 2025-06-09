/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  BinarySearchTree.cpp - Assignment 07 (Binary Search Tree)
*/

#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

  BinarySearchTree::BinarySearchTree() {
    size = 0;
    root = nullptr;
  }
  
  BinarySearchTree::~BinarySearchTree() {
    while(root) { // a bit slow but gets the job done
     delete_node(min());
    }
  }

  bool BinarySearchTree::search(int key) {
    Node* x = node_lookup(key);
    if(x == nullptr){
      return false;
    }
    return true;
  }

  void BinarySearchTree::insert(int key) {
    Node* prev = nullptr;
    Node* temp = root;
    while(temp) {
      prev = temp; // prev finds the previous node
      if(key < temp->value) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }
    size++;
    Node* input = new Node{key};
    input->parent = prev;
    if(prev == nullptr) { // if the tree is empty
      root = input;
      return;
    }
    if(input->value < prev->value) {
      prev->left = input;
    } else {
      prev->right = input;
    }
    return;
  }

  bool BinarySearchTree::delete_node(int key) {
    Node* cur = node_lookup(key);
    Node* temp;
    Node* x;
    if(cur == nullptr){ // couldn't find the node
      return false;
    }
    if(cur->left == nullptr || cur->right == nullptr) {
      temp = cur;
    } else {
      temp = node_lookup(successor(cur->value));
    }
    if(temp->left != nullptr) {
      x = temp->left;
    } else {
      x = temp->right;
    }
    if(x != nullptr) {
      x->parent = temp->parent;
    }
    if(temp->parent == nullptr) {
      root = x;
    } else if (temp == temp->parent->left) {
      temp->parent->left = x;
    } else {
      temp->parent->right = x;
    }
    if(temp != cur) {
      cur->value = temp->value;
    }
    delete temp;
    return true;
  }


  std::vector<int> BinarySearchTree::return_min() {
    std::vector<int> minimum;
    if(size == 0) {
      return minimum;
    }
    minimum.push_back(min());
    return minimum;
  }

  int BinarySearchTree::min() {
    Node* x = root;
    while(x->left != nullptr){
      x = x->left;
    }
    return x->value;
  }

  std::vector<int> BinarySearchTree::return_max() {
    std::vector<int> maximum;
    if(size == 0) {
      return maximum;
    }
    maximum.push_back(max());
    return maximum;
  }

  int BinarySearchTree::max() {
    Node* x = BinarySearchTree::root;
    while(x->right != nullptr){
      x = x->right;
    }
    return x->value;
  }

  int BinarySearchTree::predecessor(int key) {
    Node* x = node_lookup(key);
    if(x == nullptr) {
      return key + 1; /////////////// if not in tree return something that would be a predecessor to key
    }
    if(x->left != nullptr) { 
      return next_submax(x);
    }
    Node* temp = x->parent;
    while(temp != nullptr && x == temp->left) {
      x = temp;
      temp = temp->parent;
    }
    if(temp != nullptr) {
      return temp->value;
    }
    return key; // no predecessor
  }

  int BinarySearchTree::next_submax(Node* x) {
    x = x->left;
    while(x->right != nullptr){
      x = x->right;
    }
    return x->value;
  }

  int BinarySearchTree::successor(int key) {
    Node* x = node_lookup(key);
    if(x == nullptr) {
      return key - 1; /////////////// if not in tree return something that would be a successor to key
    }
    if(x->right != nullptr) {
      return next_submin(x);
    }
    Node* temp = x->parent;
    while(temp != nullptr && x == temp->right) {
      x = temp;
      temp = temp->parent;
    }
    if(temp != nullptr) {
      return temp->value;
    }
    return key; // no sucessor
  }

  int BinarySearchTree::next_submin(Node* x) {
    x = x->right;
    while(x->left != nullptr){
      x = x->left;
    }
    return x->value;
  }

  std::vector<int> BinarySearchTree::inorder() {
    list.clear();
    if(size == 0)
      return list;
    Node* x = root;
    inTraversal(x);
    return list;
  }

  void BinarySearchTree::inTraversal(Node* x) {
    if(x == nullptr)
      return;
    inTraversal(x->left);
    list.push_back(x->value);
    inTraversal(x->right); 
  }

  std::vector<int> BinarySearchTree::preorder() {
    list.clear();
    if(size == 0)
      return list;
    Node* x = root;
    preTraversal(x);
    return list;
  }

  void BinarySearchTree::preTraversal(Node* x) {
    if(x == nullptr)
      return;
    list.push_back(x->value);
    preTraversal(x->left);
    preTraversal(x->right);
  }

  std::vector<int> BinarySearchTree::postorder() {
    list.clear();
    if(size == 0)
      return list;
    Node* x = root;
    postTraversal(x);
    return list;
  }

  void BinarySearchTree::postTraversal(Node* x) {
    if(x == nullptr)
      return;
    postTraversal(x->left);
    postTraversal(x->right);
    list.push_back(x->value);
  }

  BinarySearchTree::Node* BinarySearchTree::node_lookup(int key) {
    Node* x = root;
    while(x != nullptr && x->value != key) {
      if(key < x->value) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    return x; // return null if doesn't exist
  }








