//
// Created by karla on 01/10/18.
//

#ifndef PROYECTO1_NODEDOUBLE_H
#define PROYECTO1_NODEDOUBLE_H


#include <iostream>

template <class T>
class NodeDouble {
public:
    T data;
    NodeDouble* previous;
    NodeDouble* next;
    NodeDouble<T> (T var);
};

template <class T>
NodeDouble<T>::NodeDouble(T var) {
    this->data = var;
    this->next = nullptr;
    this->previous = nullptr;
}


#endif //PROYECTO1_NODEDOUBLE_H
