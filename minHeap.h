#include <vector>

using namespace std;

class minHeap{

    private:

    vector<int>* heap;
    int realSize,MaxSize;

    void swap(int a,int b);
    void upHeap(int pos);
    void downHeap();
    void setSize(int s);

    public: 
    
    minHeap(int n);
    ~minHeap();
    void unirMinHeap(minHeap *mh);
    vector<int> *getVec();
    void insert(int x);
    void reordenar(int i);
    void removeMin();
    int getMin();
    int size();
    void imprimir();

    
    



    
};