#include <bits/stdc++.h>
#include "FibonacciHeap.h"

using namespace std;


FibonacciHeap::FibonacciHeap(){
	min=nullptr;
}
FibonacciHeap:: ~FibonacciHeap(){
	//eliminar los nodos
	nodo * aux = min;
	while(aux!= nullptr){
		if(aux->right != nullptr){
			nodo * tmp = aux;
			aux=aux->right;
			delete tmp;
		}
	}
}
void FibonacciHeap::insert(int n){

	if(min==NULL){
		nodo * nuevo = new nodo;
		nuevo->left= nuevo;
		nuevo->right =nuevo;
		//nuevo->parent = NULL;
		//nuevo->child =NULL;
		min=nuevo;
	}else{
		nodo * nuevo = new nodo;
		min-> left -> right = nuevo;
		nuevo->left= min->left;
		nuevo -> right =min;
		//nuevo ->parent = NULL;
		//nuevo->child =NULL;
		min->left = nuevo;

        if (nuevo->valor < min->valor)
            min = nuevo;
	}
}
int FibonacciHeap::getMin(){
	return min->valor;
}
void FibonacciHeap::unir(FibonacciHeap * f){

	if(f->getMin() <= min->valor ){
		min->left->right = f->min;
		f->min->left = min->left;
		f->min->right= min;
		min->left = f->min;
		min= f->min;

	}else{
		min->left->right = f->min;
		f->min->left = min->left;
		f->min->right= min;
		min->left = f->min;
	}
}