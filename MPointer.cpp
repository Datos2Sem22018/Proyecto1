#include "MPointer.h"

template <class T>
void MPointer::New() {
    MPointer* myPtr = new MPointer;
    this->data = new T;
}

template <class T>
T & MPointer::operator=(MPointer *myPtr) {
    if (typeid(T).name() == typeid(this).name()) {
        if (typeid(myPtr->data).name() == typeid(this->data).name()) {
            return true;
        }
    } else {
        return false;
    }
}

template <class T>
MPointer::~MPointer() {

}