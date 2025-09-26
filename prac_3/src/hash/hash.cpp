#include "hash.h"

HashTable::HashTable() : size(0), capacity(capacity) {
    table.resize(capacity, nullptr);
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        Node *current = table[i];

        while (current != nullptr) {
            Node *next = current->next;
            delete[] current;
            current = next;
        }
    }
}

int HashTable::hashFunction(int key) {
    return key % capacity;
}

void HashTable::reHash() {
    int oldCapacity = capacity;
    capacity *= 2;
    
    vector<Node*> newTable(capacity, nullptr);

    for (int i = 0; i < oldCapacity; ++i) {
        Node *current = table[i];

        while (current != nullptr) {
            Node *next = current->next;

            int new_index = hashFunction(current->data.isbn);

            current->next = newTable[newIndex];
            newTable[newIndex] = current;

            current = next;
        }
    }

    table = newTable;
}

bool HashTable::insert(const Book &book) {
    if (search(book.isbn) != nullptr) {
        return false;
    }

    int index = hashFunction(book.isbn);

    Node *new_node = new Node(book);

    new_node->next = table[index];
    table[index] = new_node;

    ++size;

    double loadFactor = (double)size / capacity;
    
    if (loadFactor > LOAD_FACTOR_THRESHOLD) {
        reHash();
    }

    return true;
}

Book *HashTable::search(int isbn) {

}