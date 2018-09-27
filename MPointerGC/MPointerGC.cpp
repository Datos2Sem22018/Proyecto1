//
// Created by karla on 22/09/18.
//
#include <unistd.h>
#include "MPointerGC.h"


///parte del Singleton///////////////////////
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

/////////////////////////////////////////////
void MPointerGC::executeMPGC() {

    MPointerGC* mPointerGC = MPointerGC::getInstance();
    for(int i=0; i<5; i++){
        std::cout<<"Execcuting MPointerGC"<<std::endl;
        usleep(5000000);
    }
}
