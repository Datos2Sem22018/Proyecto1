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

bool MPointer::operator=(MPointer *myPtr) {
    if (typeid(myPtr).name() == typeid(this).name()) {
        if (typeid(myPtr->data).name() == typeid(this->data).name()) {
            return true;
        }
    } else {
        return false;
    }
}