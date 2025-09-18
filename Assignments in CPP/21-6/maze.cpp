/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  maze.cpp - Assignment 06 (Maze Generation with Union Sets)
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <string>
#include <vector>
#include <utility>
#include "maze.h"
#include "disjoint_set.h"


  Maze::Maze(int size) : Solver(size*size) {
    board_length = size;
    total_size = board_length * board_length;
    board = new int*[size];
    for(int i = 0; i < size; ++i) {
      board[i] = new int[size];
    }
    BuildMaze();
  }

  Maze::~Maze() {
    for(int i = 0; i < board_length; ++i) {
      delete[] board[i];
    }
    delete[] board;
  }

  void Maze::SolveMaze() {
    std::vector<int> order;
    for(int i = 0; i < total_size; ++i) { // creates an order inputs
      order.push_back(i);
    }
    std::mt19937 seed(rand() % total_size);
    std::shuffle(order.begin(), order.end(), seed); // randomizes it and resuffles it
    while(Solver.numSets() > 1) {
      for(int index : order) {
        if(index >= 0 && index < total_size) {
          int row = index/board_length;
          int colum = index%board_length;
          int side = findNeighbor(index);
          if(side == 8) {
            if(board[row][colum] >= 0) {
              int neighbor = index - board_length;
              Solver.Union(index, neighbor);
              board[row][colum] -= 8;
              board[neighbor/board_length][neighbor%board_length] -= 2;
            }
          }
          if(side == 2) {
            if(board[row][colum] >= 0) {
              int neighbor = index + board_length;
              Solver.Union(index, neighbor);
              board[row][colum] -= 2;
              board[neighbor/board_length][neighbor%board_length] -= 8;
            }
          }
          if(side == 4) {
            if(board[row][colum] >= 0) {
              int neighbor = index - 1;
              Solver.Union(index, neighbor);
              board[row][colum] -= 4;
              board[neighbor/board_length][neighbor%board_length] -= 1;
            }
          }
          if(side == 1) {
            if(board[row][colum] >= 0) {
              int neighbor = index + 1;
              Solver.Union(index, neighbor);
              board[row][colum] -= 1;
              board[neighbor/board_length][neighbor%board_length] -= 4;
            }
          }
        }
      }
    }
  }

  void Maze::BuildMaze() { // intial condition for the board
    for(int i = 0; i < board_length; ++i) {
      for(int j = 0; j < board_length; ++j) {
        board[i][j] = 15;
      }
    }
    board[0][0] -= 4; // destroys the first wall
    board[board_length-1][board_length-1] -= 1; // destroy the last wall
  }

  void Maze::PrintMaze() {
    for(int i = 0; i < board_length; ++i) {
      for(int j = 0; j < board_length; ++j) {
        int value = board[i][j];
        if(value >= 0 && value <= 15 ) {
          std::stringstream convert;
          convert << std::hex << value;  // Convert to hexadecimal
          std::string hexStr = convert.str();
          std::cout << hexStr;
        } else {
          std::cout << " ";
        }
      }
      std::cout << std::endl;
    }
  }

  int Maze::findNeighbor(int index) { // returns a side of a legal neighbor
    std::vector<int> side = {8, 4, 2, 1};
    int neighbor;
    std::mt19937 seed(rand() % total_size);
    std::shuffle(side.begin(), side.end(), seed);
    for(int i : side) {
      if(i == 8) { // top
        neighbor = index - board_length;
        if(isLegal(index, neighbor)) {
          return 8;
        }
      }
      if(i == 2) { // bottom
        neighbor = index + board_length;
        if(isLegal(index, neighbor)) {
          return 2;
        }
      }
      if(i == 4) { // left
        neighbor = index - 1;
        if(isLegal(index, neighbor)) {
          return 4;
        }
      }
      if(i == 1){ // right
        neighbor = index + 1;
        if(isLegal(index, neighbor)) {
          return 1;
        }
      }
    }
    return -1;
  }

  bool Maze::isLegal(int index, int neighbor) { // checks if the neighbor is legal
    if(neighbor < 0 || neighbor > total_size - 1) {
      return false; // make sure it's within bounds
    }
    for(int i = 0; i < board_length; ++i) {  // checks the side walls
      int right_edge = (total_size - 1) - (board_length * i);
      if(index == right_edge && neighbor > right_edge) {
        return false;
      }
      int left_edge = (total_size - board_length) - (board_length * i);
      if(index == left_edge && neighbor < left_edge) {
        return false;
      }
    }
    if(Solver.Find(index) == Solver.Find(neighbor)) {
      return false;
    }
    return true;
  }
