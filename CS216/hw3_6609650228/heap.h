//Jutinut Ratanamongkonkul 6609650228

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>

class Heap {
private:
    std::vector<int> data; 
    int heapSize;          

    int getParentIndex(int i) const;  
    int getLeftChildIndex(int i) const; 
    int getRightChildIndex(int i) const; 
    void restoreHeapProperty(int i); 

public:
    Heap(); 
    Heap(const std::vector<int>& initData); 

    bool isHeapValid() const;       
    void constructHeap();           
    void insertItem(int item);      
    int getRoot() const;            
    int removeRoot();               

    void printHeap() const;

    public:
    std::vector<int>& getData();
    
};

#endif

