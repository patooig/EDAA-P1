#include <bits/stdc++.h>
#include "binomialHeap.h"

using namespace std;

binomialHeap::binomialHeap(){

    head = NULL;

}

void binomialHeap::insert(int x){


}

int binomialHeap::getMin(){

    Nodo *y = NULL;
    Nodo *x = head;
    int min = INT_MAX;

    while(x != NULL){

        if(x->valor < min){

            min = x->valor;
            y = x;
        }

        x = x->sibling;
    
    } 
    return min;

}  
