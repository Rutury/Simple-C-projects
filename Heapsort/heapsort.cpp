#include  "heapsort.h"

using namespace std;

void swap(vector<int>& v, int i, int j) {
    int k = v[i];
    v[i] = v[j];
    v[j] = k;
}

void drown(vector<int>& v, int i, int n) {
    if (2 * i + 1 >= n) return;
    if (2 * i + 2 == n) {
        int l = 2 * i + 1;
        if (v[l] > v[i]) swap(v, l, i);
        return;
    }
    
    int l = 2 * i + 1, r = 2 * i + 2, toSwap = v[l] > v[r] ? l : r;
    if (v[toSwap] > v[i]) {
        swap(v, i, toSwap);
        drown(v, toSwap, n);
    }
}

void makeHeap(vector<int>& v) {
    int n = v.size();
    for (int i = (n - 1) / 2; i >= 0; i--)
        drown(v, i, n);
}

void heapSort(vector<int>& v) {
    makeHeap(v);
    for (int n = v.size(); n > 0; n--) {
        swap(v, 0, n - 1);
        drown(v, 0, n - 1);
    }
}
