#include "pq.h"
#include <iostream>
using namespace std;

int main() {
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
