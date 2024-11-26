//Jutinut Ratanamongkonkul 6609650228

#include "heap.h"
#include <iostream>
using namespace std;


Heap::Heap() : heapSize(0) {}


Heap::Heap(const std::vector<int>& initData) : data(initData) {
    heapSize = initData.size();
    data.insert(data.begin(), 0); 
    constructHeap();
}


int Heap::getParentIndex(int i) const {
    return i / 2;
}


int Heap::getLeftChildIndex(int i) const{
    return 2 * i;
}


int Heap::getRightChildIndex(int i) const{
    return 2 * i + 1;
}


void Heap::restoreHeapProperty(int i){
    int largest = i;                
    int left = getLeftChildIndex(i);  
    int right = getRightChildIndex(i); 

    if (left <= heapSize && data[left] > data[largest]) {
        largest = left;
    }
    if (right <= heapSize && data[right] > data[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]); 
        restoreHeapProperty(largest);
    }
}



bool Heap::isHeapValid() const {
    for (int i = 1; i <= heapSize / 2; ++i) {
        if ((getLeftChildIndex(i) <= heapSize && data[i] < data[getLeftChildIndex(i)]) ||
            (getRightChildIndex(i) <= heapSize && data[i] < data[getRightChildIndex(i)])) {
            return false;
        }
    }
    return true;
}


void Heap::constructHeap() {
    for (int i = heapSize / 2; i >= 1; --i) {
        restoreHeapProperty(i);
    }
}


void Heap::insertItem(int item) {
    heapSize++;
    data.push_back(item);

    int i = heapSize;
    while (i > 1 && data[getParentIndex(i)] < data[i]) {
        swap(data[i], data[getParentIndex(i)]);
        i = getParentIndex(i);
    }
}


int Heap::getRoot() const {
    if (heapSize == 0) {
        throw runtime_error("Heap is empty!");
    }
    return data[1];
}


int Heap::removeRoot() {
    if (heapSize == 0) {
        throw runtime_error("Heap is empty!");
    }

    int root = data[1];
    data[1] = data[heapSize];
    data.pop_back();
    heapSize--;

    restoreHeapProperty(1);

    return root;
}


void Heap::printHeap() const {
    for (int i = 1; i <= heapSize; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

std::vector<int>& Heap::getData() {
    return data;
}

