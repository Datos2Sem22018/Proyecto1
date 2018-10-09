//
// Created by zuckerberg on 02/10/18.
//

#ifndef MPOINTER_INIT_HASHENTRY_H
#define MPOINTER_INIT_HASHENTRY_H

#include <iostream>
using namespace std;

template <class T>
class HashEntry {
public:
    T value;
    HashEntry(T value) {
        this->value = value;
    }
};


#endif //MPOINTER_INIT_HASHENTRY_H
