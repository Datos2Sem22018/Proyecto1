#include <iostream>
#include "MPointer/MPointer.h"
#include "MPointerGC/MPointerGC.h"
#include "LinkedList/LinkedList.h"
using namespace std;

int main() {
    MPointerGC* s = MPointerGC::getInstance(); // Ok
    MPointerGC* r = MPointerGC::getInstance();
    /* The addresses will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
    cout << "Hell World!, Mariano version 2.0, Hagan Pull kbrones salu2"
            ""<< endl;
    auto* list = new LinkedList<int>();
    list->add(12);
    list->add(14);
    list->add(16);
    list->printList();
    cout << list->size << endl;



    return 0;
}