#include "MPointer.h"

template <class T>
MPointer<T>::MPointer() {

}

template <class T>
MPointer<T>::~MPointer() {

}

template <class T>
MPointer<T> MPointer<T>::New() {
    MPointer* myPtr = new MPointer;
    new T;
    return *myPtr;
}

template <class T>
MPointer<T>& MPointer<T>::operator=(MPointer<T> *myPtr) {
    if (typeid(myPtr).name() == typeid(this).name()) {
        if (typeid(myPtr->data).name() == typeid(this->data).name()) {
            std::cout << "Operator works" << std::endl;
            return *this;
        }
    } else {
        std::cout << "Doesn't work" << std::endl;
    }
}