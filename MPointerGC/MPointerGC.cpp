//
// Created by karla on 22/09/18.
//
#include "MPointerGC.h"
MPointerGC* MPointerGC::instance = NULL;

MPointerGC* MPointerGC::getInstance() {
    if (!instance){
        instance = new MPointerGC();
    }
    return instance;
}
