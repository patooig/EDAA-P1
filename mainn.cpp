#include <vector>
#include <iostream>
#include "minHeap.h"

using namespace std;

int main(){
    
    minHeap * mh = new minHeap(3);
    //HOLA LEO

	//HOLA PATO
    mh->insert(10);
    mh->insert(5);
    mh->insert(102);
    mh->imprimir();
    cout << mh->getMin() << endl;
    return 0;
}

//Probando la edición

//Cualquier Cosa
