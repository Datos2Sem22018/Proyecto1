#ifndef MPOINTER_LIBRARY_H
#define MPOINTER_LIBRARY_H
#include <iostream>
#include <typeinfo>
#include "RC.h"
#include "../MPointerGC/MPointerGC.h"

template <class T>
class MPointer {
private:
    // atributos de la clase
    T* data;
    RC* reference;
    int ID;
    //""""""""""""""""""""""""
public:
    /////////////////////////////////
    //Constructor de la clase
    MPointer();
    //Destructor de la clase
    ~MPointer();
    //Asignacion de Memoria por atributo de MPointer
    static MPointer New();
    //Sobrecarga de metodos de MPointer
    MPointer<T>& operator = (MPointer* myPtr);
    void operator * (T value);
    T operator &();
    // metodo para asignar el ID
    void setID();
    int getID();
};
////////////////////////////////////////////////////////////////////
/**
 * Contructor de la clase
 * @tparam T
 */
template<class T>
MPointer<T>::MPointer() {
    //guardar el espacio de memoria
    data = static_cast< T* >( malloc(sizeof(T)) );

    //Asigna el ID correspondiente
    setID();

    reference = new RC();
    reference->addRef();
    MPointerGC::getInstance()->listMemory.add(long(this));
}
////////////////////////////////////////////////////////////////////
/**
 * Destructor de la clase
 * @tparam T
 */
template <class T>
MPointer<T>::~MPointer() {
    if(reference->release() == 0)
    {
        delete data;
        delete reference;
    }
}
////////////////////////////////////////////////////////////////////
/**
 * crea una asignacion de memoria para un dato insertado en MPointer
 * @tparam T
 * @return
 */
template <class T>
MPointer<T> MPointer<T>::New() {
    MPointer<T>* myPtr = new MPointer();
    return *myPtr;
}
////////////////////////////////////////////////////////////////////
/**
 * Sobrecarga del operador "="
 * @tparam T
 * @param myPtr : valor a verificar
 * @return : Valido o Invalido
 */
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
////////////////////////////////////////////////////////////////////

/**
 * Sobrecarga del operador "&"
 * retorna el valor de Mpointer
 * @tparam T
 * @return :valor del Mpointer
 */
template <class T>
T MPointer<T>::operator&() {
    return *data;
}

////////////////////////////////////////////////////////////////////
/**
 * Sobrecarga del operador "*"
 * asigna el valor a MPointer
 * @tparam T
 * @param value : valor a agregar
 */
template <class T>
void MPointer<T>::operator*(T value){
    *data = value;
}
////////////////////////////////////////////////////////////////////

template <class T>
void MPointer<T>::setID() {
    ID = MPointerGC::getInstance()->getID();
}

////////////////////////////////////////////////////////////////////
template <class T>
int MPointer<T>::getID() {
    return ID;
}
////////////////////////////////////////////////////////////////////

#endif