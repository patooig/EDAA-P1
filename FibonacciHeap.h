#include <bits/stdc++.h>
using namespace std;

struct nodo{

	int valor;
	nodo * left;
	nodo * right;
	nodo * child;
	nodo * parent;
	int ranking;

};

class FibonacciHeap{

private:
	nodo * min;

public:
	FibonacciHeap();
	~FibonacciHeap();
	void insert(int n);
	int getMin();
	

};