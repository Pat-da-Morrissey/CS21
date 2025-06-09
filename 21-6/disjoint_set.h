/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  disjoint_set.h - Assignment 06 (Maze Generation with Union Sets)
*/

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <iostream>
#include <vector>

  class DisjointSet{
   public:
    DisjointSet(int n);
    ~DisjointSet();
    void Union(int x, int y);
    int Find(int x);
    int numSets();

   private:
    inline void Link(int x, int y);
    inline void MakeSet(int x);
    std::vector<int> parent;
    std::vector<int> rank;    
    int curr_sets;
  };

#endif
