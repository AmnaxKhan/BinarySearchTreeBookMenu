#ifndef NODE_H
#define NODE_H

#include "Book.h"

class Node{
    public: 
        Book title; 
        Node *Left; 
        Node *Right; 
};

#endif