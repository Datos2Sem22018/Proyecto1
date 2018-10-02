#include <iostream>
#include <thread>
#include <unistd.h>
#include "MPointer/MPointer.h"
#include "MPointerGC/MPointerGC.h"
#include "LinkedList/LinkedList.h"
using namespace std;

int main() {
    MPointerGC* s = MPointerGC::getInstance();
    MPointer<int>* myPtr = new MPointer<int>();
    MPointer<int>* myPtr2 = new MPointer<int>();
    MPointer<int>* myPtr3 = new MPointer<int>();
    s->listMemory.printList();
    s->listReferences.printList();
    return 0;
}