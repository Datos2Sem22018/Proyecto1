//
// Created by karla on 22/09/18.
//

#ifndef PROYECTO1_MPOINTERGC_H
#define PROYECTO1_MPOINTERGC_H


#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../MPointer/MPointer.h"

class MPointerGC
{
private:
    /* Here will be the instance stored. */
    static MPointerGC* instance;
    /* Private constructor to prevent instancing. */
    MPointerGC() = default;
    //template <class T>
    //static void setDirMemo(MPointer<T> mPointer);
public:
    /* Static access method. */
    static MPointerGC* getInstance();
    static void executeMPGC();
    static LinkedList<int> listMemory;
};


#endif //PROYECTO1_MPOINTERGC_H