/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  Breadth-FirstSearch.cpp - Assignment 8 (Breadth-First Search)
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <set>
#include "Breadth-FirstSearch.h"

  BFS::BFS(std::vector<std::vector<int>> &A) {
    size = A.size();
    p.resize(size, std::vector<std::pair<int, int>>(size));
    d.resize(size, std::vector<int>(size));
    colour.resize(size, std::vector<std::string>(size));

    PathFinder(A);
  }

  BFS::~BFS() {}

  void BFS::PathFinder(std::vector<std::vector<int>> &A) {
    std::pair<int, int> init (-1, -1);
    for(std::size_t i = 0; i < A.size(); ++i) { // initize the BFS
      for(std::size_t k = 0; k < A[i].size(); ++k) {
        colour[i][k] = "white";
        p[i][k] = init;
        d[i][k] = -1;
      }
    }
    std::pair<int, int> cur (0, 0);
    colour[0][0] = "grey"; // initialize the source
    d[0][0] = 0;
    p[0][0] = cur;
    std::queue<std::pair<int, int>> Q;
    Q.push(cur);
    while(!Q.empty()) { // do the search
      cur = Q.front();
      Q.pop();
      int value = A[cur.first][cur.second];
      std::vector<std::pair<int,int>> prairie = AdjacencyList(cur, value);

      for(std::size_t i = 0; i < prairie.size(); ++i) {
        if (prairie[i].first >= 0 && prairie[i].second >= 0 && prairie[i].first < colour.size() && prairie[i].second < colour[prairie[i].first].size()) { // bounds check
          if(colour[prairie[i].first][prairie[i].second] == "white") {
            colour[prairie[i].first][prairie[i].second] == "grey";
            d[prairie[i].first][prairie[i].second] = d[cur.first][cur.second] + 1;
            p[prairie[i].first][prairie[i].second] = cur;
            std::pair<int, int> nex (prairie[i].first, prairie[i].second);
            Q.push(nex);
          }
        }
      }
      colour[cur.first][cur.second] = "black";
    }
    print_path();
  }

  std::vector<std::pair<int,int>> BFS::AdjacencyList(std::pair<int, int> index, int value) {
    std::vector<std::pair<int,int>> path;
    std::pair<int, int> discovery;
    if(wRight.find(value) == wRight.end()) {
      discovery = std::make_pair(index.first, index.second + 1);
      path.push_back(discovery);
    }
    if(wLeft.find(value) == wLeft.end()) {
      discovery = std::make_pair(index.first, index.second - 1);
      path.push_back(discovery);
    }
    if(wTop.find(value) == wTop.end()) {
      discovery = std::make_pair(index.first - 1, index.second);
      path.push_back(discovery);
    }
    if(wBottom.find(value) == wBottom.end()) {
      discovery = std::make_pair(index.first + 1, index.second);
      path.push_back(discovery);
    }
    return path;
  }

  std::vector<std::string> BFS::shortest_path() {
    std::vector<std::string> path;
    std::string coords;
    int row = size -1; // y-axis
    int colum = size -1; // x-axis
    while(d[row][colum] > 0) {
      coords = "(" + std::to_string(colum) + ", " + std::to_string(row) + ")";
      path.push_back(coords);
      int prev_row = row;
      row = p[row][colum].first;
      colum = p[prev_row][colum].second;
    }
    path.push_back("(0, 0)");
    return path;
  }

  void BFS::print_path() {
    std::vector<std::string> journey = shortest_path();
    for(int i = journey.size()-1; i >= 0; --i) {
      std::cout << journey[i] << std::endl;
    }
  }

