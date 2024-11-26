//Jutinut Ratanamongkonkul 6609650228

#include "heap.h"
#include "pq.h"
#include <iostream>
using namespace std;

int main() {
    //--No1--//
    cout << "Testing Heap Class..." << endl;

    vector<int> arr = {1, 2, 4, 8, 16, 32, 64, 128};
    Heap h(arr);

    cout << "Heap created from array: ";
    h.printHeap();

    cout << "Is valid heap? " << (h.isHeapValid() ? "Yes" : "No") << endl;

    cout << "Inserting 200..." << endl;
    h.insertItem(200);
    h.printHeap();


    cout << "Root element: " << h.getRoot() << endl;

    cout << "Removing root..." << endl;
    h.removeRoot();
    h.printHeap();

    //--No2--//
    PriorityQueue pq;
    cout << "Inserting 45, 12, 78, 34, 56, 89, 23 into Priority Queue." << endl;
    pq.Insert(45);
    pq.Insert(12);
    pq.Insert(78);
    pq.Insert(34);
    pq.Insert(56);
    pq.Insert(89);
    pq.Insert(23);

    
    cout << "Max: " << pq.Max() << endl;

    
    cout << "Extracting max: " << pq.ExtractMax() << endl;

    
    pq.Insert(100);
    cout << "Max after inserting 100: " << pq.Max() << endl;

    
    cout << "Modifying 34 to 101..." << endl;
    pq.Modify(34, 101);
    cout << "Max after modification: " << pq.Max() << endl;


    return 0;
}


