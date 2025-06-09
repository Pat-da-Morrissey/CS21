/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 05 (Hash Table)
  The purpose of this assignment is to: Create a hash and a user interface that will insert, delete, search, and clear the hash. My code will also have the ability to load and save files containing information that can be hashed again. This hash utilizes the multiplication method to generate hash values when the user is promted a key for each value they want to hash.
  Code Status: Complies, runs, works fine with basic tests
*/


#include <iostream>
#include <string>
#include "hash.h"


int main() {
  int input = -1;
  std::string temp;
  int hash_size = 178000;
  hashTable data(hash_size);

  while(input != 7) {
    std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ";
    std::getline(std::cin, temp);
    input = std::stoi(temp);
    
    if(input == 1) {
      std::string filename;
      std::cout << "read hash table - filename? ";
      std::getline(std::cin, filename);
      data.hash_load(filename);
    }
    if(input == 2) {
      int key;
      std::string value;
      std::string input;
      std::string key_temp;
      std::cout << "input new record:" << std::endl;
      std::getline(std::cin, input);
      for (int i = 0; i < input.size(); ++i) {
        if(i < input.find_first_of(' ')){
          key_temp += input[i];
        }
        else if(i > input.find_first_of(' ')) {
          value += input[i];
        }
      }
      key = std::stoi(key_temp);
      data.hash_insert(key, value);
    }
    if(input == 3) {
      int key;
      std::string input;
      std::cout << "delete record - key? ";
      std::getline(std::cin, input);
      key = std::stoi(input);
      std::string value = data.hash_delete(key);
      if(value == ""){
        std::cout << "Delete not found: " << key << std::endl;
      } else {
        std::cout << "Delete: " << key << " " << value << std::endl;
      }
    }
    if(input == 4) {
      int key;
      std::string input;
      std::cout << "search for record - key? ";
      std::getline(std::cin, input);
      key = std::stoi(input);
      std::string scan = data.search(key);
      if(scan == ""){
        std::cout << "Search not found: " << key << std::endl;
      } else {
        std::cout << "Found: " << key << " " << scan << std::endl;
      }
    }
    if(input == 5) {
      std::cout << "clearing has table." << std::endl;
      data.hash_clear();
    }
    if(input == 6) {
      std::string filename;
      std::cout << "write hash table - filename? ";
      std::getline(std::cin, filename);
      data.hash_save(filename);
    }
  }


  return 0;
} 
