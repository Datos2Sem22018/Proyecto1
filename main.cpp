#include <iostream>
#include "LinkedList.h"
using namespace std;

#include "MPointerGC.cpp"
int main() {
    MPointerGC* s = MPointerGC::getInstance(); // Ok
    MPointerGC* r = MPointerGC::getInstance();

    /* The addresses will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
    cout << "Hell World!, Mariano version 2.0"
            ""<< endl;




    return 0;
}