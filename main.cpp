/**
 *  Includes
 */

#include <iostream>
#include <thread>
#include <unistd.h>
#include "MPointer/MPointer.h"
#include "MPointerGC/MPointerGC.h"
#include "LinkedList/LinkedList.h"
using namespace std;

static void executeMPGC() {
    MPointerGC::getInstance();
    for(int i=0; i<5; i++){
        std::cout<<"Execcuting MPointerGC"<<std::endl;
        usleep(5000000);
    }
}

int main() {
    /**
 * clase principal de la ejecucion de Mpointer.
 * @return
 */
    MPointer<int>* myPtr = new MPointer<int>();
    MPointer<int>* myPtr2 = new MPointer<int>();
    MPointer<int>* myPtr3 = new MPointer<int>();
    MPointerGC::getInstance()->listMemory.printList();
    cout << myPtr->getID() << endl;
    cout << myPtr2->getID() << endl;
    cout << myPtr3->getID() << endl;
    return 0;
}