#include <bits/stdc++.h>
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

void FibonacciHeap::insert(int n){
	nodo * nuevo = new nodo;
	sz+=1;

	if(min==nullptr){
		nuevo->left= nuevo;
		nuevo->right =nuevo;
		nuevo->valor = n;
		//nuevo->parent = NULL;
		//nuevo->child =NULL;
		min=nuevo;
	}else{
		min-> left -> right = nuevo;
		nuevo->left= min->left;
		nuevo -> right =min;
		nuevo->valor = n;
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

    nodo *auxRight = min->right;

    nodo *auxLeft = f->min->left;

    min->right = f->min;

    f->min->left = min;

    auxRight->left = auxLeft;

    auxLeft->right = auxRight;

    min = min->valor < f->min->valor?min:f->min;
}

/*
void FibonacciHeap::unir(FibonacciHeap * f){

	if(f->getMin() <= min->valor ){
		min->left->right = f->min->right;
		f->min->right->left = min->left;
		min->left=f->min;
		f->min->right= min;
		min=f->min;
		sz+=1;
	}else{
		min->left->right = f->min->right;
		f->min->right->left = min->left;
		min->left=f->min;
		f->min->right= min;
		sz+=1;

	}
}*/

int FibonacciHeap::size(){
	return sz;
}
