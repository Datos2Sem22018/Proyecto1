#ifndef MPOINTER_NODE_H
#define MPOINTER_NODE_H
#include <iostream>

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T> (T var);
};

template <class T>
Node<T>::Node(T var) {
    this->data = var;
    this->next = nullptr;
}


#endif //MPOINTER_NODE_H
