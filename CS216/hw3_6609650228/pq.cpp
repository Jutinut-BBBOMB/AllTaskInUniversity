//Jutinut Ratanamongkonkul 6609650228


#include "pq.h"
#include <algorithm>


PriorityQueue::PriorityQueue() : heap() {}


void PriorityQueue::Insert(int x) {
    heap.insertItem(x);
}


int PriorityQueue::Max() const {
    return heap.getRoot();
}


int PriorityQueue::ExtractMax() {
    return heap.removeRoot();
}


void PriorityQueue::Modify(int x, int newx) {
    std::vector<int>& data = heap.getData(); 

   
    auto it = std::find(data.begin() + 1, data.end(), x); 
    if (it == data.end()) {
        throw std::runtime_error("Value not found in Priority Queue");
    }

    int index = std::distance(data.begin(), it); 
    data[index] = newx; 

  
    heap.constructHeap(); 
}
