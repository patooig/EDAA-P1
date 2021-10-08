#include <bits/stdc++.h>
using namespace std;

class FibonacciHeap(){
// WENA PO LARVA
	FibonacciHeap:: FibonacciHeap(){
		min=NULL;
	}
	FibonacciHeap:: ~FibonacciHeap(){
		//eliminar los nodos
	}
	void FibonacciHeap::insert(int n){

		if(min==null){
			nodo * nuevo = new nodo;
			nodo->left= nuevo;
			nodo -> rigth =nuevo;
			nodo ->parent = NULL;
			nodo->child =NULL;
			min=nuevo;
		}else{

			nodo * nuevo = new nodo;
			nodo->left= nuevo;
			nodo -> rigth =nuevo;
			nodo ->parent = NULL;
			nodo->child =NULL;
		}
	}
	int FibonacciHeap::getMin(){
		return min->valor;

	}

}