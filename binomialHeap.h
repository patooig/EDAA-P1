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

        parent = NULL;
        child = NULL;
        sibling = NULL;
    }
}

class binomialHeap{

private:

    Nodo *head;

public:

    binomialHeap();
    ~binomialHeap();
    void insert(int x);
    int getMin();

}
