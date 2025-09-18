/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 08 (Breadth-First Search)
  The purpose of this assignment is to: Create a Breadth First Search algorithm that will take in a generated maze and search the maze based on the reachable connecting squares. The search will record the 
  distance traveled at each square, it's parent square, and it's status colour. One the search is complete the program will find the shortest path by starting at the last index (maze exit) and follow it's 
  each square's parent untill it gets to the start printing out the path of coords. 
  Code Status: Complies, runs, works! No memory leaks!
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Breadth-FirstSearch.h"


int to_num(int input) {
  input -= '0';
  if(input >= 0 && input < 10)
     return input;
  if(input > 40)
    return input - 39;
  return input - 7;
}

int main() {
  std::string input;
  std::vector<std::vector<int>> A;
  int row = 0;
  while(getline(std::cin, input)) {
    if (input.empty()) { // no input
      std::cout << "No file inputed!" << std::endl;
      return 2;
    }
    if(A.size() != input.size()) { // intially builds the box
      A.resize(input.size());
    }
    if(A.size() < 3) { // can't have anything lower then a 3x3 maze
      std::cout << "Invalid Maze! Please try again!" << std::endl;
      return 1;
    }
    for(std::size_t i = 0; i < input.size(); ++i) { // fills in the box w/ maze
      A[row].push_back(to_num(input[i]));
    }
    row++;
  }
  BFS ShortestPath(A);

  return 0;
}
