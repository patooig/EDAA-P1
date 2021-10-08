#include <vector>
#include <iostream>
#include "minHeap.h"

using namespace std;

int main(){
    
    minHeap * mh = new minHeap(10);

    mh->insert(10);
    mh->insert(5);
    mh->insert(102);
    mh->insert(1);
    mh->imprimir();
    cout << mh->getMin() << endl;

    minHeap * mhh = new minHeap(10);
    mhh->insert(8);
    mhh->insert(7);
    mhh->insert(4);
    mhh->insert(2);
    mhh->imprimir();
    mh->unirMinHeap(mhh);
    mh->imprimir();
    
    return 0;
}

//Probando la edición

//Cualquier Cosa
// Holi
