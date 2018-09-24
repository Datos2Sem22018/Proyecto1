//
// Created by karla on 22/09/18.
//
#include <unistd.h>
#include "MPointerGC.h"
#include "../MPointer/MPointer.h"

MPointerGC* MPointerGC::instance = 0;

MPointerGC* MPointerGC::getInstance()
{
    if (instance == 0){
        instance = new MPointerGC();
    }

    return instance;
}
template <class T>
void MPointerGC::setDirMemo(MPointer<T> myPtr) {
    listMemory.add(&myPtr);

}

void MPointerGC::execute() {
    for(int i=0; i<10; i++){
        std::cout<<"Execcuting MPointerGC"<<std::endl;
        usleep(1000000);
    }
}


