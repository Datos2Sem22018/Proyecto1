#ifndef MPOINTER_LIBRARY_H
#define MPOINTER_LIBRARY_H
#include <iostream>
#include <typeinfo>

template <class T>
class MPointer {
private:
    T* data;
public:
    T& operator new();
    T& operator =(MPointer *myPtr);
    ~MPointer();
};

#endif