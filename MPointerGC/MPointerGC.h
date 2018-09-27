//
// Created by karla on 22/09/18.
//

#ifndef PROYECTO1_MPOINTERGC_H
#define PROYECTO1_MPOINTERGC_H


#include <iostream>
#include "../LinkedList/LinkedList.h"

class MPointerGC
{


private:
    /* Here will be the instance stored. */
    static MPointerGC* instance;
    /* Private constructor to prevent instancing. */
    MPointerGC() = default;


public:
    /* Static access method. */
    static MPointerGC* getInstance();
    static void executeMPGC();
    LinkedList<int> listMemory;
};


#endif //PROYECTO1_MPOINTERGC_H