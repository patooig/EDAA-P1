#include "binomialHeap.h"
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

binomialHeap::binomialHeap(){

    head = nullptr;
	sz = 0;

}

binomialHeap::~binomialHeap(){
	/*
	La idea para implementar el destructor es:
		Guardar en una queue todos las raices de los árboles.
		Se accede al front y se le pregunta si posee hijos,
		si es así se va iterando hasta llegar al último hijo.
		Este último hijo no tendra hermano, asi que se vuelve al padre y se 
		elimina el hijo, ya eliminado, se guarda el hijo y se va al nodo del
		hermano, se borra el hijo y ahora el hijo = hermano
		Ya desde el hijo se itera nuevamente si posee hijos y se repite el paso anterior,
		Ya una vez habremos llegado al root, hijo deberá ser igual al root, 
		entonces se compara con el front de la queue, y si coinciden 
		se almacena en una variable aux, se realiza pop al queue y se elimina aux.

	*/
	// POSIBLE DESTRUCTOR BINOMIAL HEAP
	/*
	Nodo * raiz = head;
	queue<Nodo*>raices;
	while(raiz!=nullptr){ // Almaceno las raices de los arboles
		raices.push(raiz);
		raiz = raiz->sibling;
	}
	while(1){
		Nodo * hijo = raices.front()->child;
		cout <<"Raiz front" << raices.front()->valor<<endl;
			while(hijo!=nullptr){ // Tiene hijo ?
				hijo = hijo->child;
				while(hijo->child==nullptr){  // Ultimo nodo, Tiene hermano?
					if(hijo->sibling== nullptr){						 // No tiene hermano
						hijo = hijo->parent;	 // Se sube al nodo padre
						Nodo * aux = hijo->child;// Y se borra su hijo.
						hijo->child = nullptr;
						cout <<"borro"<<endl;
						delete aux; 
					}
					if(hijo->sibling!=nullptr){ // Tiene hermano
						Nodo * temp = hijo;			// Se guarda el hermano
						Nodo * aux = hijo->sibling;
						cout << "Borro hermano anterior"<<endl;
						delete temp;	// Luego al nodo actual se le dice que no tiene hermano
						hijo = aux;		// y se avanza al hermano
					}
				}
			}
		// No tiene hijo
			Nodo * aux;
			aux = raices.front();
			cout << "hago delete"<<endl;
			raices.pop();
			delete aux;
			if(raices.empty() == true) break;
		}*/
		
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
}

// Para obtener el menor valor recorre desde el nodo 'head' hasta
// el último de sus hermanos, comprobando quien tiene el mínimo valor
int binomialHeap::getMin(){

    Nodo *x = head;
    int min = x->valor;

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
	y->degree = y->degree + 1;
}

//Método para unir dos binomialHeap.
void binomialHeap::unionBinomial(binomialHeap *bh){

    //Se obtienen los 'head' de los binomialHeap
	Nodo* nodoH1 = head;
	Nodo* nodoH2 = bh->head;

    //Nodo menor grado
	Nodo* x = nullptr;

    //Nodo head temporal
	Nodo* tempHead = nullptr;

    //Se realiza el MERGE de los binomial Heap, desde el menor grado
    //hasta el mayor grado
	if(nodoH1->degree <= nodoH2->degree){

		x = nodoH1;
		nodoH1 = nodoH1->sibling;
	}

	else{

		x = nodoH2;
		nodoH2 = nodoH2->sibling;
	}

    //Se guarda el nodo de menor grado
	tempHead = x;

    //Se recorren las raíces de los binomial trees para
    //unir desde los de menor grado hasta el de mayor grado
	while(nodoH1 != nullptr && nodoH2 != nullptr){

		if(nodoH1->degree <= nodoH2->degree){

            //Se une nodoH1 como hermano de "x"
			x->sibling = nodoH1;
			nodoH1 = nodoH1->sibling;
		}

		else{
            //Se une nodoH2 como hermano de "x"
			x->sibling = nodoH2;
			nodoH2 = nodoH2 -> sibling;
		}

		//Se avanza hacia el hermano de "x"
		x = x->sibling;
	}

	//Si quedan raíces por unir
	if(nodoH1 != nullptr){

        //Se unen las raíces al binomialHeap
		while(nodoH1 != nullptr){

			x->sibling = nodoH1;
			nodoH1 = nodoH1->sibling;
			x = x->sibling;
		}
	}

	//Si quedan raíces por unir
	if(nodoH2 != nullptr){

        //Se unen las raíces al binomialHeap
		while(nodoH2 != nullptr){

			x->sibling = nodoH2;
			nodoH2 = nodoH2->sibling;
			x = x->sibling;
		}
	}

	//Se recupera el binomialTree con menor grado
	x = tempHead;

    //prev -> child = x
    Nodo* prev = nullptr;

    //next = hermano del nodo x
	Nodo* next = x->sibling;

    //Se recorren todas las ráices
	while(next != nullptr){

        //Si las raíces tienen distinto grado
        //o next tiene hermano y tiene el mismo grada que x (3 raíces con mismo grado)
		if(x->degree != next->degree || (next->sibling != nullptr && next->sibling->degree == x->degree)){

            prev = x;
			x = next;
		}

		else {

            //Si el valor de x es menor a la siguiente raiz
			if(x->valor <= next->valor){

                //Hermano de next es ahora hermano de x
				x->sibling = next->sibling;

                //Se unen los nodos, con x como padre
				link(next, x);
			}

			else {

                //Si prev es nulo, ahora next es head temporal
				if(prev == nullptr){

					tempHead = next;
                }

				else{

                    //Hermano de prev ahora es next
					prev->sibling = next;
				}

				//Se unen los nodos con next como padre
				link(x, next);

                //avanza a la siguiente raíz
				x = next;
			}
		}

		//Se avanza con la siguiente raíz
		next = x->sibling;
	}

	//Se obtiene head
	head = tempHead;

    //Se incrementa el tamaño del binomialHeap
    sz = sz + bh->size();
}
