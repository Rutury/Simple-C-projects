#include <iostream>
#include <vector>
#include <algorithm>
#include "heapsort.h"

using namespace std;

bool test(vector<int>& v) {
    vector<int> stdV(v), myV(v);
    sort(stdV.begin(), stdV.end());
    heapSort(myV);
    if (myV.size() != stdV.size()) return false;
    for (int i = 0; i < int(stdV.size()); i++) {
        if (myV[i] != stdV[i]) return false;
    }
    return true;
}

void printVector(const vector<int>& v) { for (int i : v) cout << i << ' '; }

int main() {
    vector<vector<int>> testCases = {
        {4, 3, 2, 1}, {}, {-3}, {1, 2}, {2, 1}, {1, 2, 3}, {3, 2, 1}, {1, 2, 3, 4}, {4, 3, 2, 1}, {1, 1}, {1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1, 1},
        {33,73,1,69,15,17,74,20,67,96,95,53,43,61,23,8,60,71,97,83,18,35,57,68,87,62,6,34,31,81,70,84,59,86,16,90,10,100,75,82,2,45,24,50,32,36,47,92,88,29,58,98,55,41,85,27,76,52,64,46,40,38,63,99,44,25,42,5,4,28,66,56,78,54,7,51,13,14,37,26,48,21,39,22,89,77,49,79,72,91,80,93,3,12,11,9,19,94,65,30},
        {48,49,41,48,42,38,15,33,7,20,39,37,34,23,4,42,17,24,22,19,25,26,19,47,50,44,19,39,16,7,5,12,37,2,31,2,44,22,15,4,47,13,20,40,2,24,33,22,50,10,2,41,30,12,34,50,28,27,20,16,49,34,22,43,46,32,40,16,18,37,7,50,6,38,42,46,3,32,37,26,9,29,9,6,38,35,30,43,36,48,23,10,7,20,46,46,50,18,22,44,19}
    };
    int right = 0, wrong = 0;
    for (vector<int>& v : testCases) {
        if (test(v)) {
            right++;
        } else {
            wrong++;
            vector<int> myV(v), stdV(v);
            sort(stdV.begin(), stdV.end());
            heapSort(myV);

            cout << "Error!!!\nTest\n";
            printVector(v);
            cout << "\nMy ans\n";
            printVector(myV);
            cout << "\nstd ans\n";
            printVector(stdV);
            cout << endl << endl;
        }
    }
    cout << "Tests done, " << right << "/" << right + wrong << " tests passed" << endl;
}