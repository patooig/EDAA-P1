#include "binomialHeap.h"
#include <climits>
#include <iostream>

using namespace std;

binomialHeap::binomialHeap(){

    head = nullptr;
	sz = 0;

}

binomialHeap::~binomialHeap(){
    
}

int binomialHeap::size(){
	return sz;
}

/*Al momento de insertar debemos crear UN BINOMIAL TREE
  con el único nodo, asignar grado y comparar el grado
  de la raiz de los binomial trees.

  Dos binomial trees no pueden tener el mismo grado */
void binomialHeap::insert(int x){

    binomialHeap *bh = new binomialHeap();
    Nodo * n_node = new Nodo();
    n_node->valor = x;
    bh->head = n_node;
    if(head!=nullptr) unionBinomial(bh);
    else head = n_node;
    sz++;

    // crear binomial tree

    // cout<<endl<<head->valor<<endl;

}

// Para obtener el menor valor recorre desde el nodo 'head' hasta
// el último de sus hermanos, comprobando quien tiene el mínimo valor
int binomialHeap::getMin(){

    Nodo *x = head;
    int min = x->valor;

    while(x != nullptr){

        //cout<<endl<<x->valor<<endl;

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
	y->degree = y->degree + 1;
    //cout<<x->valor<<", "<<y->valor<<endl;
}

//Método para unir dos binomialHeap.
void binomialHeap::unionBinomial(binomialHeap *bh){

    //Se obtienen los 'head' de los binomialHeap
	Nodo* nodoH1 = head;
	Nodo* nodoH2 = bh->head;

   // cout<<nodoH1->valor<<", "<<nodoH2->valor<<endl;

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

//	cout<<endl<<aux->valor<<endl;

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

     //   cout<<"entra h1\n";

		while(nodoH1 != nullptr){

			aux->sibling = nodoH1;
			nodoH1 = nodoH1->sibling;
			aux = aux->sibling;
		}
	}

	//Si el nodo existe
	if(nodoH2 != nullptr){

     //   cout<<"entra h2\n";
		while(nodoH2 != nullptr){

			aux->sibling = nodoH2;
			nodoH2 = nodoH2->sibling;
			aux = aux->sibling;
		}
	}

	aux = temp;
	Nodo* prev = nullptr;
	Nodo* next = aux->sibling;

  //  cout<<aux->valor<<", "<<next->valor<<endl;

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

					temp = next;
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

    sz = sz + bh->size();
}
