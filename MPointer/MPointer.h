#ifndef MPOINTER_LIBRARY_H
#define MPOINTER_LIBRARY_H
#include <iostream>
#include <typeinfo>

template <class T>
class MPointer {
private:
    T* data;
public:
    MPointer();
    ~MPointer();
    static MPointer New();
    MPointer<T>& operator = (MPointer* myPtr);
    int operator
};

#endif