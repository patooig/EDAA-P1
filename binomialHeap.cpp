#include <bits/stdc++.h>
#include "binomialHeap.h"

using namespace std;

binomialHeap::binomialHeap(){

    head = nullptr;

}

void binomialHeap::imprimir(){
    Nodo * raiz = head ;
    Nodo * child = raiz->child;

    if(raiz!=nullptr) cout << raiz->valor << endl;
    //Imprimir los hijos del head
    while (child!=nullptr)
    {
        cout << child->valor << " " ;
        child = child->sibling;
    }
    raiz = raiz->sibling;
    
}

binomialHeap::~binomialHeap(){
    
}

/*Al momento de insertar debemos crear UN BINOMIAL TREE
  con el único nodo, asignar grado y comparar el grado
  de la raiz de los binomial trees.

  Dos binomial trees no pueden tener el mismo grado */
void binomialHeap::insert(int x){
    binomialHeap bh ;
    Nodo * n_node = new Nodo();
    n_node->valor = x;
    bh.head = n_node;
    if(head!=nullptr) unionBinomial(bh);
    else head = n_node;
    // crear binomial tree

}

// Para obtener el menor valor recorre desde el nodo 'head' hasta
// el último de sus hermanos, comprobando quien tiene el mínimo valor
int binomialHeap::getMin(){

    Nodo *x = head;
    int min = INT_MAX;

    while(x != nullptr){

        if(x->valor < min){

            min = x->valor;
        }

        x = x->sibling;
    
    } 
    return min;
}  

//y->valor <= x->valor
//Método para unir dos binomial heap del mismo grado, donde
//el valor del nodo 'y' es menor o igual al valor del nodo 'x'
void binomialHeap::link(Nodo *x, Nodo *y){

	x->parent = y;
	x->sibling = y->child;
	y->child = x;
	y->degree = y->degree + 1; // y->degree++;
}

//Método para unir dos binomialHeap.
void binomialHeap::unionBinomial(binomialHeap bh){

    //Se obtienen los 'head' de los binomialHeap
	Nodo* nodoH1 = head;
	Nodo* nodoH2 = bh.head;

    //Nodos auxiliares
	Nodo* aux = nullptr;
	Nodo* temp = nullptr;

    //aux corresponde al nodo con menor grado
	if(nodoH1->degree <= nodoH2->degree){

		aux = nodoH1;
		nodoH1 = nodoH1->sibling;
	}

	else{

		aux = nodoH2;
		nodoH2 = nodoH2->sibling;
	}

	temp = aux;

    //Se recorren los binomial heaps
	while(nodoH1 != nullptr && nodoH2 != nullptr){

        //Busca el árbol que está al extremo derecho
		if(nodoH1->degree <= nodoH2->degree){

			aux->sibling = nodoH1;
			nodoH1 = nodoH1->sibling;
		}

		else{
			aux->sibling = nodoH2;
			nodoH2 = nodoH2 -> sibling;
		}

		aux = aux->sibling;
	}

	//Si el nodo existe
	if(nodoH1 != nullptr){


		while(nodoH1 != nullptr){

			aux->sibling = nodoH1;
			nodoH1 = nodoH1->sibling;
			aux = aux->sibling;
		}
	}

	//Si el nodo existe
	if(nodoH2 != nullptr){

		while(nodoH2 != nullptr){

			aux->sibling = nodoH2;
			nodoH2 = nodoH2->sibling;
			aux = aux->sibling;
		}
	}

	aux = temp;
	Nodo* prev = nullptr;
	Nodo* next = aux->sibling;

	while(next != nullptr){

		if(aux->degree != next->degree || (next->sibling != nullptr && next->sibling->degree == aux->degree)){

			prev = aux;
			aux = next;
		}

		else {

			if(aux->valor <= next->valor){

				aux->sibling = next->sibling;
				link(next, aux);
			}

			else {

				if(prev == nullptr){

					head = next;
			}

				else{

					prev->sibling = next;
				}

				link(aux, next);
				aux = next;
			}
		}

		next = aux->sibling;
	}

	head = temp;
}
