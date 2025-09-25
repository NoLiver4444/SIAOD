#ifndef NODE_H_
#define NODE_H_

#include "book.h"

struct Node
{
    Book data;
    Node *next;

    Node(const Book &book);
};


#endif