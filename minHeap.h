#ifndef MIN_HEAP
#define MIN_HEAP

#include <vector>

class minHeap{

    private:

    std::vector<int>* heap;
    int realSize,maxSize;
    void swap(int a,int b);
    void upHeap(int pos);
    int getrealSize();
    void reordenar(int i);
    std::vector<int> *getVec();

    public: 
    
    minHeap(int n);
    ~minHeap();
    void unirMinHeap(minHeap *mh);
    void insert(int x);
    int getMin();
    int size();
    void imprimir();
};

#endif
