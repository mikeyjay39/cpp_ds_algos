//
// Created by michael on 7/7/21.
//

#include <algorithm>
#include <vector>


#ifndef DS_ALGOS_MYMAXHEAP_H
#define DS_ALGOS_MYMAXHEAP_H

#endif //DS_ALGOS_MYMAXHEAP_H

using namespace std;

template<typename T>
class MyMaxHeap {
public:
    void insert(T t);
    void print();
    T pop();


private :
    vector<T> elements;
};

template<typename T>
void MyMaxHeap<T>::insert(T t) {
    elements.push_back(t);
    unsigned long currentPosition = elements.size() - 1;
    unsigned long parentPosition = 0;
    bool keepGoing = true;

    while (keepGoing) {
        parentPosition = max((int)(currentPosition - 1) / 2, 0);
        T parentElement = elements.at(parentPosition);
        T insertedElement = elements.at(currentPosition);

        if (insertedElement > parentElement) {
            elements.at(parentPosition) = insertedElement;
            elements.at(currentPosition) = parentElement;
            currentPosition = parentPosition;
            keepGoing = true;
        } else {
            keepGoing = false;
        }
    }
}

template<typename T>
void MyMaxHeap<T>::print() {
    for (T t : elements) {
        cout << t << endl;
    }
}

template<typename T>
T MyMaxHeap<T>::pop() {

    if (elements.size() < 1) {
        return -1;
    }

    T result = elements.at(0);

    if (elements.size() == 1) {
        return result;
    }

    int currentPosition = 0;
    bool keepGoing = elements.size() > 1;
    T lastElement = elements.at(elements.size() - 1);
    elements.pop_back();
    elements.at(currentPosition) = lastElement;

    while (keepGoing) {
        int childPosition1 = (currentPosition * 2) + 1;
        int childPosition2 = (currentPosition * 2) + 2;
        int maxChildPosition = childPosition1;
        T currentElement = elements.at(currentPosition);
        T child1;
        T child2;
        T maxChild;

        if (childPosition1 < elements.size()) {
            child1 = elements.at(childPosition1);
            maxChild = child1;
        }

        if (childPosition2 < elements.size()) {
            child2 = elements.at(childPosition2);

            if (child2 > child1) {
                maxChild = child2;
                maxChildPosition = childPosition2;
            }
        }

        if (maxChildPosition < elements.size() && maxChild > currentElement) {
            elements.at(currentPosition) = maxChild;
            elements.at(maxChildPosition) = currentElement;
            currentPosition = maxChildPosition;
        } else {
            keepGoing = false;
        }
    }

    return result;
}

