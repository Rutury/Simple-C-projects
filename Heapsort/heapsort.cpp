#include  "heapsort.h"

using namespace std;

void makeHeap(vector<int>& v) {
    
}

void drown(vector<int>& v, int n) {

}

void heapSort(vector<int>& v) {
    makeHeap(v);
    for (int n = v.size(); n > 0; n--)
        drown(v, n);
}
