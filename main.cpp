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
/**
 * clase principal de la ejecucion de Mpointer.
 * @return
 */
int main() {
    //Pruebas a la creacion del CG
    MPointerGC* mPointerGC;

    /*ejecucion del Thread*/
    thread t1(mPointerGC->executeMPGC);

    //Pruebas a  la creacion de una instancia de MPointer
    MPointer<int>* mPtr = new MPointer<int>();
    cout << &mPtr << endl;

    MPointer<int>* mPtr2 = new MPointer<int>();
    cout<< &mPtr2<<endl;
    mPtr2->operator*(5);
    int x = mPtr2->operator&();
    cout << x << endl;


    for(int i=0; i<15 ; i++){
        cout<<"Desde el main"<<endl;
        usleep(1000000);
    }



    //Activacion del thread
    t1.join();
    return 0;
}