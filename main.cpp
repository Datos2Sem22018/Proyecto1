#include <iostream>
#include <thread>
#include "MPointer/MPointer.h"
#include "MPointerGC/MPointerGC.h"
#include "LinkedList/LinkedList.h"
using namespace std;

int main() {

    MPointerGC* mPointerGC;
    mPointerGC->executeMPGC();

    auto* list = new LinkedList<int>();
    list->add(12);
    list->add(14);
    list->add(16);
    list->printList();
    cout << list->size << endl;
    cout << list->get(1) << endl;



    return 0;
}