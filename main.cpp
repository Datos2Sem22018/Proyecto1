#include <iostream>
#include "LinkedList/LinkedList.h"
#include "MPointerGC/MPointerGC.h"
using namespace std;

int main() {
    MPointerGC* s = MPointerGC::getInstance(); // Ok
    MPointerGC* r = MPointerGC::getInstance();
    /* The addresses will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
    cout << "Hell World!, Mariano version 2.0, Hagan Pull kbrones salu2"
            ""<< endl;
    return 0;
}