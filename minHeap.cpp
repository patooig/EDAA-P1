#include <vector>
#include <iostream>
#include "minHeap.h"

using namespace std;

minHeap::minHeap(int n){
    heap = new vector<int>;
    realSize = 0;
    maxSize = n;
    heap->assign((n+1),INT32_MAX);
    heap->at(0) = INT32_MIN;
}

minHeap::~minHeap(){
    delete heap;
}

void minHeap::insert(int x){       // Insertamos en la ultima posicion y debemos
    if(realSize<maxSize){          // subir el nodo si es menor.
        realSize++;    
        heap->at(realSize) = x;
        upHeap(realSize);
    } 
}

void minHeap::upHeap(int pos){     //Hijo verifica su padre, si es menor se intercambia
    int padre = pos/2;             // así de forma iterativa hasta llegar a la raiz.
    while(padre>=1){
        if(heap->at(padre)>heap->at(pos)){
            swap(padre,pos);
            pos = padre;
            padre = padre/2;
        }else break; 
        
        
    }
}

int minHeap::getMin(){            //Devuelve el mínimo
    if(realSize>0)return heap->at(1); 
    else return -1;
}

int minHeap::size(){            // Devuekve el número de elementos insertados en el vector
    return realSize;
}

int minHeap::getrealSize(){     // Devuelve el valor del tamaño real del vector
    return maxSize;
}


void minHeap::unirMinHeap(minHeap * mh){ 
    vector<int> * hp_nuevo = new vector<int>;       // Creamos nuevo heap
    int sz = getrealSize() + mh->getrealSize();     // Tamaño del nuevo minHeap
    hp_nuevo->assign((sz+1),INT32_MAX);             // Rellenamos 
    hp_nuevo->at(0) = INT32_MIN;

    vector<int> * hp_mh;                            // Vector auxiliar para acceder al mh
 
    for (int i = 1; i <= size() ; i++){             // Inserto los elementos que tengo en el head
        hp_nuevo->at(i) = heap->at(i);
    }
    hp_mh = mh->getVec();
    for (int i = 1; i <= mh->size(); i++){          // Inserto los elementos que tengo en mh
    
        hp_nuevo->at(i+size()) = hp_mh->at(i);
    }

    realSize = size()+mh->size();                   // Reasignamos los nuevos valores a la variables
    maxSize = sz;

    delete mh;
    delete heap;
    heap = hp_nuevo;                    

    for (int i = (sz/2); i>=1; i--)                 // El nuevo heap no cumple con la propiedad de min,
    {                                               // se deben reordenar los elementos
        reordenar(i);                     
    }                                      
   
}

void minHeap::reordenar(int padre){             //Verifica si los hijos del nodo contienen 
    bool h1 = true, h2 = true;                  //elementos menores a el
    int hijo1 = 2*padre;
    int hijo2 = 2*padre+1;
    int hijomenor = padre;

    if(padre == realSize) return;
    if(hijo1 > realSize){                           //Verificamos si el hijo izq exist
        h1 = false;
    } 
    if(hijo2 > realSize){                           //Verificamos si el hijo derecho exist
        h2 = false;
    } 
    if(!h1 && !h2)return;                           // Si no existe ninguno, termina
    
                                                    
    if (h1 && heap->at(hijo1) < heap->at(padre)){   // Si el menor esta en el hijo 1
        hijomenor = hijo1;
    }
    
    if (h2 && heap->at(hijo2) < heap->at(hijomenor)){// Si el menor esta en el hijo 2
        hijomenor = hijo2;
    }
    
    if (padre!=hijomenor){                           // Si cambia el valor del menor, debemos hacer el swap
        swap(padre, hijomenor);                      // y volver a reordenar para el nodo de abajo de forma recursiva
        reordenar(hijomenor);
    }
}

void minHeap::swap(int pos1, int pos2){             //Intercambia posiciones
    int aux = heap->at(pos2);
    heap->at(pos2) = heap->at(pos1);
    heap->at(pos1) = aux;
}

void minHeap::imprimir(){

    for (int i = 1; i <= size(); i++)
    {
        cout << heap->at(i) << " ";
    }
    cout<<endl;
}

vector<int> * minHeap::getVec(){    // Retorna un puntero al vector de los elementos
    return heap;
}



