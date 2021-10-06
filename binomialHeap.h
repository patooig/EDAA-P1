#include <bits/stdc++.h>

using namespace std;

//  Basado en la información de:
//  https://www.cs.toronto.edu/~anikolov/CSC265F16/binomial-heaps.pdf

struct Nodo{

    int valor;

    int degree;
    Nodo *parent;
    Nodo *child;
    Nodo *sibling;

    Nodo(){
        degree = 0;
        parent = nullptr;
        child = nullptr;
        sibling = nullptr;
    }
};

class binomialHeap{

private:

    Nodo *head;

public:

    binomialHeap();
    ~binomialHeap();
    void insert(int x);
    int getMin();
    void link(Nodo *x, Nodo*y);
    void unionBinomial(binomialHeap bh);
    void imprimir();

};
