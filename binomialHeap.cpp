#include <bits/stdc++.h>
#include "binomialHeap.h"

using namespace std;

binomialHeap::binomialHeap(){

    head = NULL;

}

/*Al momento de insertar debemos crear UN BINOMIAL TREE
  con el único nodo, asignar grado y comparar el grado
  de la raiz de los binomial trees.

  Dos binomial trees no pueden tener el mismo grado */
void binomialHeap::insert(int x){
    // crear binomial tree

}

/* void createBinomialTree(int x){
    // Quiza una struct que se llame así

    typedef struct{ 
        Node * root;
    }binomialTree

    Node * n_node = new Node();
    // Asignar valores del nodo, padre,hijo, hermanos..valor.//

    binomialTree * bt1 = new binomialTree();
    bt1->root = n_node; //o &n_node; ???

    o iterar a partir del heap y buscar sus hermanos para ver 
    el grado de cada uno 

    luego
    n_node->sibling = head;
    head = n_node;
    
    //Luego comparar con los otros binomialTree, accediendo a la raiz
    //de cada uno 

    // Debemos tener un conteo de cuantos binomialTree poseemos, y al momento del merge 
       se decrementa en 1.
}
*/

int binomialHeap::getMin(){

    Nodo *x = head;
    int min = INT_MAX;

    while(x != NULL){

        if(x->valor < min){

            min = x->valor;
        }

        x = x->sibling;
    
    } 
    return min;

}  
