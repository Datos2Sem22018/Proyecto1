//
// Created by karla on 22/09/18.
//

#include "MPointerGC.h"
MPointerGC* MPointerGC::instance = 0;

MPointerGC* MPointerGC::getInstance()
{
    if (instance == 0)
    {
        instance = new MPointerGC();
    }

    return instance;
}

MPointerGC::MPointerGC()
{}
