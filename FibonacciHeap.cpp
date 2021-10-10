#include <iostream>
#include "FibonacciHeap.h"

using namespace std;


FibonacciHeap::FibonacciHeap(){
	min=nullptr;
	sz = 0;
}

FibonacciHeap:: ~FibonacciHeap(){
	nodo * aux = min;
	aux->left->right = nullptr;
	while(aux!= nullptr){
		if(aux->right != nullptr){
			nodo * tmp = aux;
			aux=aux->right;
			delete tmp;
		}
		if(aux->right == nullptr){
			delete aux;
			break;
		}
	}
}

//Imprime los valores de todo el heap, desde min hacia la derecha
void FibonacciHeap::imprimir(){
	nodo *aux = min;
	int i = 1;
	while(aux!= nullptr && i<=size()){
		if(aux->right != nullptr){
			i++;
			cout<<aux->valor<<endl;
			aux=aux->right;
		}
	}
}

//Inserta un nuevo valor
void FibonacciHeap::insert(int n){
	nodo * nuevo = new nodo;
	sz+=1;

    //Si es el primer elemento insertado
	if(min==nullptr){
        //Se referencia a si mismo los punteros
        //left y right y se designa como min
		nuevo->left= nuevo;
		nuevo->right =nuevo;
		nuevo->valor = n;
		min=nuevo;
	}else{
        //La parte derecha del nodo a la izquierda de min queda
        //referenciado a nuevo
		min-> left -> right = nuevo;
        //el nodo a la izquierda de min queda a la izquierda de nuevo
		nuevo->left= min->left;
        //min queda a la derecha de nuevo
		nuevo -> right =min;
        //Se asigna el valor al nuevo nodo
		nuevo->valor = n;

        //nuevo queda a la izquierda de min
		min->left = nuevo;

        //Se comprueba si el nuevo elemento insertado
        //es menor al mínimo actual
        if (nuevo->valor < min->valor)
            min = nuevo;
	}
}

//Devuelve el menor valor
int FibonacciHeap::getMin(){
	return min->valor;
}

void FibonacciHeap::unir(FibonacciHeap * f){

    //Se guarda el nodo derecho de min
    nodo *auxRight = min->right;

    //Se guarda el nodo izquierdo de f->min
    nodo *auxLeft = f->min->left;

    //El lado derecho de min apunta a f->min
    min->right = f->min;

    //el lado izquierdo de f->min apunta a min
    f->min->left = min;

    //El lado izquierdo del antiguo nodo derecho de min apunta
    //al antigo nodo izquierdo de f->min
    auxRight->left = auxLeft;

    //El lado derecho del antiguo nodo izquierdo de f->getMin
    //apunta al antiguo lado derecho de min
    auxLeft->right = auxRight;

    //min se determina entre los min de los fibonacciHeap
    min = min->valor < f->min->valor?min:f->min;

    //Se incrementa el tamaño del fibonacciHeap
	sz = sz + f->size();
}

//Retorna la cantidad de elementos de fibonacciHeap
int FibonacciHeap::size(){
	return sz;
}
