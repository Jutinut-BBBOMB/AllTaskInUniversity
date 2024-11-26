//Jutinut Ratanamongkonkul 6609650228


#ifndef PQ_H
#define PQ_H

#include "heap.h"

class PriorityQueue {
private:
    Heap heap; 

public:
    PriorityQueue(); 

    void Insert(int x);       
    int Max() const;          
    int ExtractMax();         
    void Modify(int x, int newx); 
};

#endif
