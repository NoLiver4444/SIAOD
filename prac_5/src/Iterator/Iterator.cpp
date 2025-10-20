#include "Iterator.h"

template <typename Key, typename Value>
Iterator<Key, Value>::Iterator() : current_node(nullptr), past_node(nullptr) {}

template <typename Key, typename Value>
Iterator<Key, Value>::Iterator(Node<Key, Value> *current_node,
                               Node<Key, Value> *past_node)
    : current_node(current_node), past_node(past_node) {}

template <typename Key, typename Value>
Iterator<Key, Value> &Iterator<Key, Value>::operator++() {

}

template <typename Key, typename Value>
Iterator<Key, Value> &Iterator<Key, Value>::operator--() {
    
}

template <typename Key, typename Value>
bool Iterator<Key, Value>::operator!=(const Iterator &other) const {
    return current_node != other->current_node;
}

template <typename Key, typename Value>
bool Iterator<Key, Value>::operator==(const Iterator &other) const {
    return current_node == other->current_node;
}