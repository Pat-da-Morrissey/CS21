/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 06 (Maze Generation with Union Sets)
  The purpose of this assignment is to: Create a square maze from taking in a size from commandline input. From here each index in the maze is walled up, by utilizing a disjoint set that corresponds to each 
  square, union 2 neighboring boxes and destroy their wall. Keep on doing this until you one have 1 disjoint set left which means that every box is accessible on the maze. The result is random and unique maze 
  from a start and ending point.
  Code Status: Compiles and runs but not complete. It sometimes produces a correct maze othertimes not, when it doesn't it gets stuck in a infinite loop. I beleive it gets stuck in an infinite loop if the 
  randomly selected index can't find a nieghbor to break it's wall. However more testing and fixing is needed.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <ctime>
#include "maze.h"

int main(int argc, char *argv[]) {
  if(argc < 2) {
    std::cout << "Error! Please insert a size!" << std::endl;
    return 1;
  }
  if(std::atoi(argv[1]) < 3) {
    std::cout << "Error! Invalid maze size!" << std::endl;
    return 2;
  }
  std::srand(time(0));
  int size = std::atoi(argv[1]);
  Maze Game_1(size);
  Game_1.SolveMaze();
  Game_1.PrintMaze();
  return 0;
}
