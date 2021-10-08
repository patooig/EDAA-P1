#include <vector>

using namespace std;

class minHeap{

    private:

    vector<int>* heap;
    int realSize,MaxSize;
    void swap(int a,int b);
    void upHeap(int pos);
    int getrealSize();
    void reordenar(int i);
    vector<int> *getVec();

    public: 
    
    minHeap(int n);
    ~minHeap();
    void unirMinHeap(minHeap *mh);
    void insert(int x);
    int getMin();
    int size();
    void imprimir();

    
    



    
};