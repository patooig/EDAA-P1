#include <bits/stdc++.h>
using namespace std;

struct nodo{

	int valor;
	nodo * left;
	nodo * right;
};

class FibonacciHeap{

private:
	nodo * min;
	int sz;

public:
	FibonacciHeap();
	~FibonacciHeap();
	void insert(int n);
	int getMin();
	void unir(FibonacciHeap *f);
	void imprimir();
	int size();

};
