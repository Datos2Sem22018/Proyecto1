#ifndef MPOINTER_LIBRARY_H
#define MPOINTER_LIBRARY_H
#include <iostream>
#include <typeinfo>

template <class T>
class MPointer {
private:
    T* data;
public:
    MPointer() = default;
    ~MPointer() = default;
    static MPointer New();
    MPointer<T>& operator = (MPointer* myPtr);
    void operator * (T* value);
    T* operator &();
};

template <class T>
MPointer<T> MPointer<T>::New() {
    auto* myPtr = new MPointer;
    new T;
    return *myPtr;
}
template <class T>
MPointer<T>& MPointer<T>::operator=(MPointer *myPtr) {
    if (typeid(myPtr).name() == typeid(this).name()) {
        if (typeid(myPtr->data).name() == typeid(this->data).name()) {
            std::cout << "Operator works" << std::endl;
        }
    } else {
        std::cout << "Doesn't work" << std::endl;
    }
}
template <class T>
T* MPointer<T>::operator&() {
    return *data;
}

template <class T>
void MPointer<T>::operator*(T* value){
    data = value;
}

#endif