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
    MPointerGC();
    /* Static access method. */
public:
    static MPointerGC* getInstance();
    int getID();
    LinkedList<long> listMemory;
    LinkedList<int> listReferences;
};


#endif //PROYECTO1_MPOINTERGC_H