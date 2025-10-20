#include "Node.h"

template <typename Key, typename Value>
Node<Key, Value>::Node(Key key, Value value) : key(key), value(value) {}

template <typename Key, typename Value>
Node<Key, Value>::Node(Key key, Value value, Node *parent)
    : key(key),
      value(value),
      parent(parent),
      left(nullptr),
      right(nullptr),
      height(0) {}

template <typename Key, typename Value>
bool Node<Key, Value>::eqNode(Node *other) {
    return this->value == other->value && this->key == other->key;
}