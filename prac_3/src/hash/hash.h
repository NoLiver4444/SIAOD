#ifndef HASH_H_
#define HASH_H_

#include <vector>

#include "../model/node.h"

class HashTable {
 private:
  std::vector<Node> table;
  int size;
  int capacity;

  const double LOAD_FACTOR_THRESHOLD = 0.75;

  int hashFunction(int key);
  void reHash();

 public:
  HashTable(int capacity = 10);
  ~HashTable();

  bool insert(const Book &book);
  Book *search(int isbn);
  bool remove(int isbn);
};

#endif