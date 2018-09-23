//
// Created by karla on 22/09/18.
//

#ifndef PROYECTO1_MPOINTERGC_H
#define PROYECTO1_MPOINTERGC_H


#include <iostream>
#include "RC.h"

class MPointerGC
{
private:
    /* Here will be the instance stored. */
    static MPointerGC* instance;
    RC* reference;

    /* Private constructor to prevent instancing. */
    MPointerGC();

public:
    /* Static access method. */
    static MPointerGC* getInstance();
    void MPointerDelete();
};


#endif //PROYECTO1_MPOINTERGC_H
