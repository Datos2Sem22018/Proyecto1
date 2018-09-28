#ifndef MPOINTER_LIBRARY_H
#define MPOINTER_LIBRARY_H
#include <iostream>
#include <typeinfo>
#include "RC.h"
#include "../MPointerGC/MPointerGC.h"

class MPointerGC;

template <class T>
class MPointer {
private:
    T* data;
    RC* reference;
public:
    //Constructor de la clase
    MPointer();
    //Destructor de la clase
    ~MPointer();
    //Asigacion de Memoria por atributo de MPointer
    static MPointer New();
    //Sobrecarga de metodos de MPointer
    MPointer<T>& operator = (MPointer* myPtr);
    void operator * (T* value);
    T operator &();
    MPointerGC* instance;
};

template <class T>
MPointer<T>::MPointer() {
    reference = new RC();
    reference->addRef();
    instance->listMemory.add(&(*this));
}

template <class T>
MPointer<T>::~MPointer() {
    if(reference->release() == 0)
    {
        delete data;
        delete reference;
    }
}

template <class T>
MPointer<T> MPointer<T>::New() {
    auto* myPtr = new MPointer();
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
T MPointer<T>::operator&() {
    return *data;
}

template <class T>
void MPointer<T>::operator*(T* value){
    data = value;
}

#endif