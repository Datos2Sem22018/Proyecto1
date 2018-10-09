//
// Created by karla on 22/09/18.
//
#include <unistd.h>
#include "MPointerGC.h"


///parte del Singleton///////////////////////
MPointerGC::MPointerGC() {

}

MPointerGC* MPointerGC::instance = nullptr;

MPointerGC* MPointerGC::getInstance() {
    if (instance == nullptr){
        instance = new MPointerGC();
    }
    return instance;

}

int MPointerGC::getID() {
    int ID = rand()%1000000;
    listID.add(ID);
    return ID;
}

void MPointerGC::executeMPGC() {
    for(;;){
        std::cout<<"Execcuting MPointerGC"<<std::endl;
        usleep(5000000);
    }
}
