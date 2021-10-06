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

    while(x != nullptr){

        if(x->valor < min){

            min = x->valor;
        }

        x = x->sibling;
    
    } 
    return min;
}  

//y->valor <= x->valor
void binomialHeap::link(Nodo *x, Nodo *y){
/*
	1 p[y] ← z
	2 sibling[y] ← child[z]
	3 child[z] ← y
	4 degree[z] ← degree[z] + 1*/

	x->parent = y;
	x->sibling = y->child;
	y->child = x;
	y->degree = y->degree + 1; // y->degree++;
}

void binomialHeap::unionBinomial(binomialHeap bh){
/*
	1 H ← M AKE -B INOMIAL -H EAP ()
2 head[H ] ← B INOMIAL -HEAP -M ERGE (H1 , H2 )
3 free the objects H 1 and H 2 but not the lists they point to
4 if head[H ] = NIL
5
 then return H
6 prev-x ← NIL
7 x ← head[H ]
8 next-x ← sibling[x]
9 while next-x = NIL
10
 do if (degree[x] = degree[next-x]) or
(sibling[next-x] = NIL and degree[sibling[next-x]] = degree[x])
11
 then prev-x ← x
 ✄ Cases 1 and 2
12
 x ← next-x
 ✄ Cases 1 and 2
13
 else if key[x] ≤ key[next-x]
14
 then sibling[x] ← sibling[next-x]
 ✄ Case 3
15
 B INOMIAL -L INK (next-x, x)
 ✄ Case 3
16
 else if prev-x = NIL
 ✄ Case 4
17
 then head[H ] ← next-x
 ✄ Case 4
18
 else sibling[prev-x] ← next-x
 ✄ Case 4
19
 B INOMIAL -L INK (x, next-x)
 ✄ Case 4
20
 x ← next-x
 ✄ Case 4
21
 next-x ← sibling[x]
22 return H
*/

	Nodo* nodoH1 = head;
	Nodo* nodoH2 = bh.head;
	Nodo* aux = nullptr;
	Nodo* temp = nullptr;

	if(nodoH1->degree <= nodoH2->degree){

		aux = nodoH1;
		nodoH1 = nodoH1->sibling;
	}

	else{

		aux = nodoH2;
		nodoH2 = nodoH2->sibling;
	}

	temp = aux;

	while(nodoH1 != nullptr && nodoH2 != nullptr){

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

	if(nodoH1 != nullptr){

		while(nodoH1 != nullptr){

			aux->sibling = nodoH1;
			nodoH1 = nodoH1->sibling;
			aux = aux->sibling;
		}
	}

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
