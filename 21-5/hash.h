/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  hash.h - Assignment 05 (Hash Table)
*/

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

  class hashTable{
   public:
    hashTable(int size); // build a table
    ~hashTable();
    void hash_insert(int key, std::string value); // insert copy of record
    std::string hash_delete(int key); // delete a record
    std::string search(int key) {
      int hash_key = hash_generate(key); 
      int index = find(key, hash_key);
      if(index != -1) {
        std::pair <int, std::string> data;
        data = A[hash_key][index];
        return data.second;
      }
      return "";
    }
    void hash_load(std::string filename);
    void hash_save(std::string filename);
    void hash_clear();
 
   private:
    int find(int key, int hash_key);  // returns index
    int hash_generate(int key) { // hash value for a key
      int index = (int)(m*(key*c - (int)(key*c)));
      return index;
    }
    int m;
    const double c = 0.618034;
    std::vector<std::pair<int, std::string>> *A;
  };

#endif
