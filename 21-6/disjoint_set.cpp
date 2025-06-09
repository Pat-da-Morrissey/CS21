/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  disjoint_set.cpp - Assignment 06 (Maze Generation with Union Sets)
*/

#include <iostream>
#include "disjoint_set.h"

  DisjointSet::DisjointSet(int n) {
    curr_sets = n;
    for(int i = 0; i < n; ++i) {
      MakeSet(i); 
    }
  }

  DisjointSet::~DisjointSet() {}

  void DisjointSet::Union(int x, int y) {
    if(x >= 0 && x < parent.size() && y >= 0 && y < parent.size()) {
      Link(x,y);
    }
  }

  int DisjointSet::Find(int x) { // w/ path path compression
    if(x >= 0 && x < parent.size()) { //bounds check
      if(x != parent[x]) {
        parent[x] = Find(parent[x]);
      }
      return parent[x];
    }
    return -1;
  }

  int DisjointSet::numSets() { return curr_sets; }

  void DisjointSet::Link(int x, int y) {
    if(x >= 0 && x < parent.size() && y >= 0 && y < parent.size()) {
      int xFind = Find(x);
      int yFind = Find(y);
      if(xFind != yFind) {
        if(rank[xFind] > rank[yFind]) {
          parent[yFind] = xFind;
        } else {
          parent[xFind] = yFind;
          if (rank[xFind] == rank[yFind]) {
            rank[yFind]++;
          }
        }
        curr_sets--; // decreases the number of sets as they become attached to eachother
      }
    }
  }

  void DisjointSet::MakeSet(int i) {
    parent.push_back(i);
    rank.push_back(0);
  }


