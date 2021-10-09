#include <vector>
#include <iostream>
#include "minHeap.h"
#include "FibonacciHeap.h"

using namespace std;

int main(){
/*
    minHeap * mh = new minHeap(10);

    mh->insert(10);
    mh->insert(5);
    mh->insert(102);
    
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

    mh->insert(69);
    mh->insert(1);
    mh->imprimir();
    delete mh;
*/
    
    FibonacciHeap * fh = new FibonacciHeap();
    fh->insert(10);
    fh->insert(1);
    fh->insert(102);
    fh->insert(100);
   // fh->insert(5);
    cout <<" fibo min:" <<fh->getMin()<<endl;
    fh->imprimir();
    cout << endl;

    FibonacciHeap * fhh = new FibonacciHeap();
    fhh->insert(16);
    fhh->insert(12);
    fhh->insert(11);
    fhh->insert(0);
    fhh->imprimir();
    cout << endl;
    fh->unir(fhh);
    fh->imprimir();

    cout << "Min. despues de unir " << fh->getMin() << endl;
    //fhh->imprimir();
   // delete fh;
    delete fhh;
    return 0;
}
