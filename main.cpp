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
    thread t1(executeMPGC);
    MPointer<int>* myPtr = new MPointer<int>();
    cout << "Working" << endl;
    cout << &myPtr << endl;
    MPointerGC::getInstance()->listMemory.printList();
    for(int i=0; i<100 ; i++){
        cout<<"Desde el main"<<endl;
        usleep(1000000);
    }
    t1.join();
    return 0;
}