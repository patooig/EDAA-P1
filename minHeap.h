#include <vector>

using namespace std;

class minHeap{

    private:
    vector<int> heap;
    void upHeap(int pos);
    int realSize,MaxSize;
    void swap(int a,int b);
    void downHeap();

    public: 
    minHeap(int n);
    ~minHeap();
    void unirMinHeap(minHeap *mh);
    vector<int> getVec();
    void insert(int x);
    void removeMin();
    int getMin();
    int size();
    void imprimir();
    
    



    
};