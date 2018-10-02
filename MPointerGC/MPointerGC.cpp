//
// Created by karla on 22/09/18.
//
#include <unistd.h>
#include "MPointerGC.h"


///parte del Singleton///////////////////////
MPointerGC::MPointerGC() {

}

MPointerGC* MPointerGC::instance = 0;

MPointerGC* MPointerGC::getInstance() {
    if (instance == 0){
        instance = new MPointerGC();
        instance++;
    }else{
        std::cout<<"Instancia ya creada"<<std::endl;
    }
    return instance;

}

/*template<class T>
void MPointerGC::setDirMemo(MPointer<T> mPtr) {
    listMemory.add(&mPtr);
}*/
