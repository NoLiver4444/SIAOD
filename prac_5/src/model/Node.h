#ifndef NODE_H_
#define NODE_H_

template <typename Key, typename Value>
struct Node {
  Key key;
  Value value;
  Node *parent;
  Node *left;
  Node *right;
  int height = 0;

  Node(Key key, Value value);
  Node(Key key, Value value, Node *parent);

  bool eqNode(Node *other);
};

#endif