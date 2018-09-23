//
// Created by karla on 22/09/18.
//
#include "MPointerGC.h"
MPointerGC* MPointerGC::instance = NULL;

MPointerGC::MPointerGC() {
    reference = new RC();
    reference->addRef();
}

MPointerGC* MPointerGC::getInstance() {
    if (!instance){
        instance = new MPointerGC();
    }
    return instance;
}

void MPointerGC::MPointerDelete() {
    if (reference->release() == 0) {
        delete reference;
    } else {
        reference->release();
    }
}