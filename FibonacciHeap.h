#include <bits/stdc++.h>
using namespace std;

struct nodo{

	int valor;
	nodo * left;
	nodo * right;
	//nodo * child;
	//nodo * parent;
	//int ranking;
	// no se ocupa ranking, los nodos child y parent porque no se hace el delete, por lo que no se mueven los
	// nodos hacia "abajo". :D
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