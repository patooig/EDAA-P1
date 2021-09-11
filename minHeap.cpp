//MIN HEAP
#include <vector>
#include <iostream>
#include "minHeap.h"

using namespace std;

minHeap::minHeap(int n){
    realSize = 0;
    MaxSize = n;
    heap.assign((n+1),INT32_MAX); // Con que numero lo relleno? es importante?
    heap[0] = INT32_MIN;
}

minHeap::~minHeap(){

}

void minHeap::insert(int x){
    if(realSize<MaxSize){ // Existe espacio disp ??
     // Insertamos en el ultimo lugar disp.
        realSize++;
        heap[realSize] = x;
        //heap.push_back(x);
        upHeap(realSize);
    } 
}

void minHeap::removeMin(){
    heap[1] = heap[realSize];
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
            if(heap[hijo1]<heap[hijo2])hijomenor=hijo1;
            else hijomenor=hijo2;
            if(heap[padre]>heap[hijomenor])swap(padre,hijomenor);
            padre = hijomenor;
        }
        else if(h1 && ~h2){  // Si existe el hijo izq nomas
            if(heap[padre]>heap[hijo1])swap(padre,hijo1);
            padre = hijo1;
        }
        else if(~h1 && h2){  // Si existe el hijo derecho nomas
            if(heap[padre]>heap[hijo2])swap(padre,hijo2);
            padre = hijo2;
        }
    }
    
}

void minHeap::upHeap(int pos){
    int padre = pos/2;
    while(padre>=1){
        if(heap[padre]>heap[pos]){
            swap(padre,pos);
            pos = padre;
            padre = padre/2;
        }else break; 
        
        
    }
}

int minHeap::getMin(){
    if(realSize>0)return heap[1];  // Si existe elemento, debe ser el que esta en el root
    else return -1;
}

int minHeap::size(){
    return realSize;
}

void minHeap::swap(int pos1, int pos2){
    int aux = heap[pos2];
    heap[pos2] = heap[pos1];
    heap[pos1] = aux;
}

void minHeap::imprimir(){

    for (int i = 1; i <= realSize; i++)
    {
        cout << heap[i] << " ";
    }
    cout<<endl;
}



