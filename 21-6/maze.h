/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  maze.h - Assignment 06 (Maze Generation with Union Sets)
*/

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include "disjoint_set.h"

  class Maze{
   public:
    Maze(int size);
    ~Maze();
    void SolveMaze();
    void PrintMaze();

   private:
    bool isLegal(int index, int neighbor);
    void BuildMaze();
    int findNeighbor(int index);
    int **board;
    int board_length;
    int total_size;
    DisjointSet Solver;
  };

#endif
