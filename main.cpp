#include <iostream>
#include <thread>
#include <unistd.h>
#include "MPointer/MPointer.h"
#include "MPointerGC/MPointerGC.h"
#include "LinkedList/LinkedList.h"
using namespace std;

int main() {

    MPointerGC* mPointerGC = MPointerGC::getInstance();
    thread t1(mPointerGC->executeMPGC);
    MPointer<int> mPtr = MPointer<int>::New();


    for(int i=0; i<100 ; i++){
        cout<<"Desde el main"<<endl;
        usleep(1000000);
    }


    t1.join();



    return 0;
}