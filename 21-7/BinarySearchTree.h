/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  BinarySearchTree.h - Assignment 07 (Binary Search Tree)
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include <iostream>
#include <vector>

  class BinarySearchTree {
   public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool search(int key);
    void insert(int key);
    bool delete_node(int key);
    int predecessor(int key);
    int successor(int key);
    std::vector<int> inorder();
    std::vector<int> preorder();
    std::vector<int> postorder();
    std::vector<int> return_min();
    std::vector<int> return_max();

   private:
    struct Node {
      int value;
      Node* left;
      Node* right;
      Node* parent;
      Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
      }
    };
    Node* root;
    Node* node_lookup(int key);
    int size;
    int min();
    int max();
    int next_submax(Node* x);
    int next_submin(Node* x);
    std::vector<int> list;
    void inTraversal(Node* x);
    void preTraversal(Node* x);
    void postTraversal(Node* x);

  };
#endif
