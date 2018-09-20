#ifndef MPOINTER_NODE_H
#define MPOINTER_NODE_H
#include <iostream>

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node (T var);
};


#endif //MPOINTER_NODE_H
