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
void MPointer<T>::operator=(MPointer *myPtr) {
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
void MPointer<T>::operator*(T* data){

}