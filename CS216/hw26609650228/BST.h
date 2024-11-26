// จุติณัฏฐ์ รัตนะมงคลกุล 6609650228



#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Employee {
    int ID;
    int age;
    int salary;

    Employee(int id, int ag, int srl) {
        ID = id;
        age = ag;
        salary = srl;
    }
};

struct Node {
    Employee* emp;
    Node* left;
    Node* right;

    Node(Employee* e) {
        emp = e;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    vector<Employee> employees;
    Node* root;

    void addNode(Employee* e);
    void deleteIndex(int ID);
    int getHeight(Node* node);
    void removeAllIndices(Node* node);
    void inOrder(Node* node);
    void printEmployee(Employee* emp);
    
public:
    BST();
    ~BST();
    void read_employee(string filename);
    void build_tree_index();
    void shuffleData();
    int getHeight();
    void removeAllIndices();
    void inOrder();
};

#endif
