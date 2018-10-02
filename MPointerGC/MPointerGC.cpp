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
    }else{
        std::cout<<"Instancia ya creada"<<std::endl;
    }
    return instance;

}

int MPointerGC::getID() {
    int ID = rand()%1000;
    if(listID.searchB(ID)){
        ID=getID();
    }else
        return ID;
}

void MPointerGC::executeMPGC() {
    for(;;){
        std::cout<<"Execcuting MPointerGC"<<std::endl;
        usleep(5000000);
    }
}
