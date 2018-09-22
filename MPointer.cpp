#include "MPointer.h"

template <class T>
MPointer::MPointer() {

}

template <class T>
MPointer::~MPointer() {

}

template <class T>
MPointer MPointer::New() {
    MPointer* myPtr = new MPointer;
    new T;
    return *myPtr;
}

void MPointer::operator=(MPointer *myPtr) {
    if (typeid(myPtr).name() == typeid(this).name()) {
        if (typeid(myPtr->data).name() == typeid(this->data).name()) {
            std::cout << "Operator works" << std::endl;
        }
    } else {
        std::cout << "Doesn't work" << std::endl;
    }
}