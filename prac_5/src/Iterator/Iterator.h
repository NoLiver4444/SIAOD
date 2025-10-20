#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "../model/Node.h"

template <typename Key, typename Value>
class Iterator {
 protected:
  Node *current_node;
  Node *past_node;

 public:
  Iterator();
  Iterator(Node<Key, Value> *current_node,
           Node<Key, Value> *past_node = nullptr);

    Iterator &operator++();
    Iterator &operator--();
    
    bool operator!=(const Iterator &other) const;
    bool operator==(const Iterator &other) const;
};

#endif