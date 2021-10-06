//MIN HEAP
#include <vector>
#include <iostream>
#include "minHeap.h"

using namespace std;

minHeap::minHeap(int n){
    heap = new vector<int>;
    realSize = 0;
    MaxSize = n;
    heap->assign((n+1),INT32_MAX);
    heap->at(0) = INT32_MIN;
}

minHeap::~minHeap(){

}

void minHeap::setSize(int s){
    realSize = s;
}

void minHeap::insert(int x){
    if(realSize<MaxSize){ 
                       
        realSize++;    // Insertamos en el ultimo lugar disp.
        heap->at(realSize) = x;
        upHeap(realSize);
    } 
}

void minHeap::removeMin(){
    heap->at(1) = heap->at(realSize);
    realSize--;
    downHeap();
}

void minHeap::downHeap(){
    int padre = 1;
    int hijo1;
    int hijo2;
    int hijomenor;
    bool h1 = true, h2 = true;
    while (padre<realSize)
    {
        hijo1 = padre*2;   // Verificar si existen
        hijo2 = padre*2+1; // Verificar si existen
        if(hijo1 > realSize){
            h1 = false;
        } 
        if(hijo2 > realSize){
            h2 = false;
        } 
        if(h1&&h2){ // Si existen ambos hijos
            if(heap->at(hijo1)<heap->at(hijo2))hijomenor=hijo1;
            else hijomenor=hijo2;
            if(heap->at(padre)>heap->at(hijomenor))swap(padre,hijomenor);
            padre = hijomenor;
        }
        else if(h1 && ~h2){  // Si existe el hijo izq 
            if(heap->at(padre)>heap->at(hijo1))swap(padre,hijo1);
            padre = hijo1;
        }
        else if(~h1 && h2){  // Si existe el hijo derecho 
            if(heap->at(padre)>heap->at(hijo2))swap(padre,hijo2);
            padre = hijo2;
        }
    }
    
}

void minHeap::upHeap(int pos){
    int padre = pos/2;
    while(padre>=1){
        if(heap->at(padre)>heap->at(pos)){
            swap(padre,pos);
            pos = padre;
            padre = padre/2;
        }else break; 
        
        
    }
}

int minHeap::getMin(){
    if(realSize>0)return heap->at(1);  // Si existe elemento, debe ser el que esta en el root
    else return -1;
}

int minHeap::size(){
    return realSize;
}

// Despues de unir no se puede insertar pq el nuevo se llena //

void minHeap::unirMinHeap(minHeap * mh){ 
    vector<int> * hp_nuevo;
    vector<int> * hp_mh;

    int sz = size() + mh->size();

    minHeap * nuevo_mh = new minHeap(sz);
    
    hp_nuevo = nuevo_mh->getVec();
    for (int i = 1; i <= size() ; i++)  // Inserto en el nuevo heap el this->vector
    {
        hp_nuevo->at(i) = heap->at(i);
    }
    hp_mh = mh->getVec();
    for (int i = 1; i <= mh->size(); i++)  // Inserto en el nuevo heap el mh->vector
    {
        hp_nuevo->at(i+size()) = hp_mh->at(i);
    }

    nuevo_mh->setSize(sz);              // El nuevo heap tiene size
    heap = hp_nuevo;                    // queremos que hp_nuevo sea nuestro this
    
}

void minHeap::swap(int pos1, int pos2){
    int aux = heap->at(pos2);
    heap->at(pos2) = heap->at(pos1);
    heap->at(pos1) = aux;
}

void minHeap::imprimir(){

    for (int i = 1; i <= realSize; i++)
    {
        cout << heap->at(i) << " ";
    }
    cout<<endl;
}

vector<int> * minHeap::getVec(){
    return heap;
}



