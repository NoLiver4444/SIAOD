#ifndef HASH_H_
#define HASH_H_

#include "../model/node.h"
#include <vector>

class HashTable {
private:
    std::vector<Node> table;
    int size;
    int capacity;

    int hashFunction(int key);
    void reHash();
public:

};

#endif