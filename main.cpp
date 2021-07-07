#include <iostream>
#include <cassert>
#include "MyMaxHeap.h"

int main() {
    cout << "Hello, World!" << endl;
    vector<int> ints;
    ints.push_back(1);
    ints.push_back(10);
    ints.push_back(5);
    ints.push_back(15);
    ints.push_back(2);
    ints.push_back(35);
    ints.push_back(15);

    MyMaxHeap<int> maxHeap;

    for (int i : ints) {
        maxHeap.insert(i);
    }

    maxHeap.print();
    cout << "Popping elements. Should print in order" << endl;
    int prev = INT32_MAX;

    for (int i = 0; i < 8; i++) {
        int element = maxHeap.pop();
        cout << element << endl;
        assert(prev >= element);
        prev = element;
    }
    return 0;
}
