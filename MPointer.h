        #ifndef MPOINTER_LIBRARY_H
#define MPOINTER_LIBRARY_H
#include <iostream>
#include <typeinfo>
#include "RC.h"
#include "MPointerGC.h"

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

    MPointer();//Constructor de la clase
    ~MPointer();//Destructor de la clase
    static MPointer New();//Asignacion de Memoria por atributo de MPointer

    //Sobrecarga de metodos de MPointer
    void operator = (const MPointer &myPtr);
    void operator = (const int &value);

    T& operator * ();
    T& operator &();

    // metodo para asignar el ID
    void setID();
    int getID();

    void setData(T *data);
};
////////////////////////////////////////////////////////////////////
/**
 * Contructor de la clase
 * @tparam T
 */
template<class T>
MPointer<T>::MPointer() {
    data = static_cast< T* >( malloc(sizeof(T)) );//guardar el espacio de memoria
    setID();//Asigna el ID correspondiente
    reference = new RC();
    reference->addRef();
    MPointerGC::getInstance()->listMemory.add((long)this);
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
        MPointerGC::getInstance()->listMemory.remove((long)this);
    } else {
        reference->release();
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
void MPointer<T>::operator=(const MPointer &myPtr) {
    if (typeid(myPtr).name() == typeid(this).name()) {
        this->data=myPtr->data;
        &this=&myPtr;
    } else {
        std::cout << "Doesn't work" << std::endl;
    }
}


///////////////////////////////////////////////////////////////////
template <class T>
void MPointer<T>::operator=(const int &value){
    std::string typeM = typeid(this->data).name();
    std::string typoT= typeid(value).name();
    if(typeM[1]== typoT[0]){
        *data = value;
    }else{
        printf("Doesn't Work\n");
    }
}

///////////////////////////////////////////////////////////////////

/**
 * Sobrecarga del operador "&"
 * retorna el valor de Mpointer
 * @tparam T
 * @return :valor del Mpointer
 */
template <class T>
T& MPointer<T>::operator&() {
    std::cout<<*data<<std::endl;
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
T& MPointer<T>::operator*(){
    return *data;
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
template<class T>
void MPointer<T>::setData(T *data) {
    MPointer::data = data;
}

#endif
