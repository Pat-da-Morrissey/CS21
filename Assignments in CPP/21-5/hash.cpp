/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  hash.cpp - Assignment 05 (Hash Table)
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include "hash.h"

  hashTable::hashTable(int size){
    m = size;
    A = new std::vector<std::pair<int, std::string>>[m];
  }

  hashTable::~hashTable() {
    delete[] A;
  }

  void hashTable::hash_insert(int key, std::string value) {
    int hash_key = hash_generate(key);
    std::pair<int, std::string> data = std::make_pair(key, value);
    A[hash_key].push_back(data);
  }

  std::string hashTable::hash_delete(int key) {
    int hash_key = hash_generate(key);
    std::string value;
    std::pair <int, std::string> data;
    int index = find(key, hash_key);   
    if(index != -1) {
      data = A[hash_key][index];
      value = data.second;
      int temp = A[hash_key].size()-1;
      A[hash_key][temp].swap(A[hash_key][index]);
      A[hash_key].pop_back();
      return value;
    }
    return "";
  }

  void hashTable::hash_load(std::string filename) {
    std::ifstream fin(filename);
    int key;
    std::string input;
    while(std::getline(fin, input)) {
      std::string key_temp;
      std::string value;
      for (int i = 0; i < input.size(); ++i) {
       if(i < input.find_first_of(' ')) {
          key_temp += input[i];
        } else if (i > input.find_first_of(' ')) {
          value += input[i];
        }
      }
      key = std::stoi(key_temp);
      hash_insert(key, value);
    }
    fin.close();
  }

  void hashTable::hash_save(std::string filename) {
    std::ofstream fout(filename);
    if(fout.is_open()){
      for(int i = 0; i < m; ++i){
        for(int index = 0; index < A[i].size(); ++index) {
          std::pair<int, std::string> data = A[i][index];
          fout << std::setfill('0') << std::setw(9) << data.first 
          << " " << data.second << std::endl;
        }
      }
    } else {
      std::cout << "Error opening file! Please try again" << std::endl;
    }
    fout.close();
  }

  void hashTable::hash_clear() {
    for(int i = 0; i < m; ++i) {
      A[i].clear();
    }
  }

  inline int hashTable::find(int key, int hash_key) {
    if(A[hash_key].size() > 0) {
      for(int i = 0; i < A[hash_key].size(); ++i) {
        std::pair <int, std::string> data = A[hash_key][i];
        if(data.first == key) {
          return i;
        }
      }
    }
    return -1;
  }