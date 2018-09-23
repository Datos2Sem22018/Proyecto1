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
    void operator = (MPointer* myPtr);
    void operator * (T* data);
    T* operator &();
};

#endif