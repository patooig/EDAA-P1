#include <vector>
#include <iostream>
#include "minHeap.h"
#include "FibonacciHeap.h"
#include "binomialHeap.h"

using namespace std;

int main(){

    clock_t start;
	double t;

    int n;

    vector<int> v;

    while(cin>>n){

        v.push_back(n);
    }

    int m = v.size();

    minHeap *mH = new minHeap(m);

    binomialHeap *bH = new binomialHeap();

    start = clock();
    for(int i=0; i<m; i++){

        mH->insert(v.at(i));
    }
    t= (double)(clock()-start)/CLOCKS_PER_SEC;

    cout<<"MinHeap:\n";
    cout<<t<<endl;
    cout<<"min: "<<mH->getMin()<<endl;
    cout<<mH->size()<<endl;


    start = clock();
    for(int i=0; i<m; i++){

        bH->insert(v.at(i));
    }
    t= (double)(clock()-start)/CLOCKS_PER_SEC;

    cout<<"\nBinomialHeap:\n";
    cout<<t<<endl;
    cout<<"min: "<<bH->getMin()<<endl;
    cout<<bH->size()<<endl;
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

*/
    return 0;
}
