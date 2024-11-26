// จุติณัฏฐ์ รัตนะมงคลกุล 6609650228


#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    removeAllIndices();
}

void BST::printEmployee(Employee* emp) {
    cout << "ID:" << emp->ID << ", Salary:" << emp->salary << ", Age:" << emp->age << endl;
}

void BST::read_employee(string filename) {
    ifstream file(filename);
    int id, age, salary;
    while (file >> id >> salary >> age) {
        employees.push_back(Employee(id, age, salary));
    }
    file.close();
}

void BST::addNode(Employee* e) {
    Node* newNode = new Node(e);
    if (!root) {
        root = newNode;
        return;
    }
    Node* current = root;
    Node* parent = nullptr;
    while (current) {
        parent = current;
        if (e->ID < current->emp->ID) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (e->ID < parent->emp->ID) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void BST::build_tree_index() {
    for (auto& emp : employees) {
        addNode(&emp);
    }
    cout << "BST has been constructed." << endl;
}

void BST::deleteIndex(int ID) {
    
}

int BST::getHeight(Node* node) {
    if (node == nullptr) return -1;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return 1 + std::max(leftHeight, rightHeight);
}

int BST::getHeight() {
    return getHeight(root);
}

void BST::removeAllIndices(Node* node) {
    if (node) {
        removeAllIndices(node->left);
        removeAllIndices(node->right);
        delete node;
    }
}

void BST::removeAllIndices() {
    removeAllIndices(root);
    root = nullptr;
    cout << "All indices have been deleted" << endl;
}

void BST::inOrder(Node* node) {
    if (!node) return;
    inOrder(node->left);
    printEmployee(node->emp);
    inOrder(node->right);
}

void BST::inOrder() {
    inOrder(root);
}

void BST::shuffleData() {
    random_shuffle(employees.begin(), employees.end());
    cout << "Shuffling Done." << endl;
}
