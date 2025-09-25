#include "hash.h"

int HashTable::hashFunction(int key) {
    return key % capacity;
}

void HashTable::reHash() {
    
}