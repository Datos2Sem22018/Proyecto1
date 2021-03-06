/**
 *  Includes
 */

#include <iostream>
#include <thread>
#include <unistd.h>
#include "MPointer.h"
#include "MPointerGC.h"
#include "LinkedList.h"

using namespace std;
/**
 * clase principal de la ejecucion de Mpointer.
 * @return
 */
int main() {

    // Pruebas a Linked List
    LinkedList<int> l1 = LinkedList<int>();
    l1.add(23);
    l1.add(34);
    l1.printList();

    //Pruebas a la creacion del CG
    MPointerGC* mPointerGC;

    /*ejecucion del Thread*/
    thread t1(mPointerGC->executeMPGC);

    //Pruebas a  la creacion de una instancia de MPointer
    MPointer<int>* mPtr = new MPointer<int>();
    cout << &mPtr << endl;
    *mPtr = 3;
    mPtr->operator&();
    //int valor = &mPtr;

    cout<<&mPtr<<endl;


    MPointer<int>* mPtr2 = new MPointer<int>();
    //mPtr2 = 8;

    //int valor = &mPtr;

    cout<< mPtr2<<endl;
    mPtr = mPtr2;

    cout << mPtr << endl;


    for(int i=0; i<15 ; i++){
        cout<<"Desde el main"<<endl;
        usleep(1000000);
    }



    //Activacion del thread
    t1.join();
    return 0;
}
