/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  Breadth-FirstSearch.h - Assignment 8 (Breadth-First Search)
*/

#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>

  class BFS{
   public:
    BFS(std::vector<std::vector<int>> &A);
    ~BFS();
    void PathFinder(std::vector<std::vector<int>> &A);

   private:
    int size;
    void print_path();
    std::vector<std::string> shortest_path();
    std::vector<std::pair<int,int>> AdjacencyList(std::pair<int, int> index, int value);
    std::vector<std::vector<std::pair<int, int>>> p;
    std::vector<std::vector<int>> d;
    std::vector<std::vector<std::string>> colour;
    //Sets of maze values with Walls
    std::set<int> wRight = {1, 3, 5, 7, 9, 11, 13, 15};
    std::set<int> wLeft = {4, 5, 6, 7, 12, 13, 14, 15};
    std::set<int> wTop = {8, 9, 10, 11, 12, 13, 14, 15};
    std::set<int> wBottom = {2, 3, 6, 7, 10, 11, 14, 15};

  };

#endif
