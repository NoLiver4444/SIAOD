#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include "../Iterator/Iterator.h"

template <typename Key, typename Value>
class AVL_Tree {
 protected:
  struct Node;
  class Iterator;
  Node *root;

  void copyTree(Node *copy_node, Node *parent);

  void removeTree(Node *node);

 public:
  AVL_Tree();
  AVL_Tree(const AVL_Tree &other);
  AVL_Tree(AVL_Tree &&other) noexcept;
  ~AVL_Tree();

  Iterator begin();
  Iterator end();

  Node *get_min(Node *node);
  Node *get_max(Node *node);

  void clear();

  bool eqTree(AVL_Tree *other);
};

#endif