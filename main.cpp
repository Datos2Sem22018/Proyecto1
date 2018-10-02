#include <iostream>
#include <thread>
#include <unistd.h>
#include "MPointer/MPointer.h"
#include "MPointerGC/MPointerGC.h"
#include "LinkedList/LinkedList.h"
using namespace std;

int main() {
    /**
 * clase principal de la ejecucion de Mpointer.
 * @return
 */
    MPointerGC* mPointerGC = MPointerGC::getInstance();
    cout << &mPointerGC << endl;
    thread t1(mPointerGC->executeMPGC);
    MPointer<int>* mPtr = new MPointer<int>;
    cout << &mPtr << endl;
    for(int i=0; i<100 ; i++){
        cout<<"Desde el main"<<endl;
        usleep(1000000);
    }
    mPointerGC->listMemory.printList();
    t1.join();
    return 0;
}