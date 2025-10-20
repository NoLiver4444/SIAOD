#include "AVL_Tree.h"

template <typename Key, typename Value>
AVL_Tree<Key, Value>::AVL_Tree() : root(nullptr) {}

template <typename Key, typename Value>
AVL_Tree<Key, Value>::AVL_Tree(const AVL_Tree &other) {
  root = copy_Tree(other.root, nullptr);
}

template <typename Key, typename Value>
AVL_Tree<Key, Value>::AVL_Tree(AVL_Tree &&other) noexcept {
  root = other.root;
  other.root = nullptr;
}

template <typename Key, typename Value>
AVL_Tree<Key, Value>::~AVL_Tree() {
  clear();
}

template <typename Key, typename Value>
void AVL_Tree<Key, Value>::clear() {
  if (root == nullptr) {
    return;
  }

  removeTree(root);
}

template <typename Key, typename Value>
void AVL_Tree<Key, Value>::removeTree(Node *node) {
  if (node == nullptr) {
    return;
  }

  removeTree(node->left);
  removeTree(node->right);

  delete node;
}

template <typename Key, typename Value>
bool AVL_Tree<Key, Value>::eqTree(AVL_Tree *other) {
  Iterator this_it = begin();
  Iterator other_it = other->begin();
  Iterator this_end = end();
  Iterator other_end = other->end();

  while (this_it != this_end && other_it != other_end) {
    if (!(this_it.current_node->eq_Node(other_it.current_node))) {
      return false;
    }
    ++this_it;
    ++other_it;
  }

  return this_it == this_end && other_it == other_end;
}

template <typename Key, typename Value>
void AVL_Tree<Key, Value>::copyTree(Node *copy_node, Node *parent) {
  if (copy_node != nullptr) {
    Node *new_node = new Node(copy_node->Key, copy_node->value);
    new_node->left = copyTree(copy_node->left, new_node);
    new_node->right = copyTree(copy_node->right, new_node);
    new_node->parent = parent;

    return new_node;
  }
}

template <typename Key, typename Value>
typename AVL_Tree<Key, Value>::Iterator AVL_Tree<Key, Value>::begin() {
  return AVL_Tree::Iterator(get_min(root));
}

template <typename Key, typename Value>
typename AVL_Tree<Key, Value>::Iterator AVL_Tree<Key, Value>::end() {
  if (root == nullptr) return begin();

  Node *last_node = get_max(root);
  Iterator test(nullptr, last_node);
  return test;
}

template <typename Key, typename Value>
AVL_Tree<Key, Value>::Node *AVL_Tree<Key, Value>::get_min(Node *node) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->left != nullptr) {
        get_min(node->left);
    }

    return node;
}

template <typename Key, typename Value>
AVL_Tree<Key, Value>::Node *AVL_Tree<Key, Value>::get_max(Node *node) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->right != nullptr) {
        get_max(node->right);
    }

    return node;
}