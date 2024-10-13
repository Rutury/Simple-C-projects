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
        {},
        {}
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