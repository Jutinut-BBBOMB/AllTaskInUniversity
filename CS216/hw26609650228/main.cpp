// จุติณัฏฐ์ รัตนะมงคลกุล 6609650228

#include <iostream>
#include "BST.h"
using namespace std;
int main(){
BST bst;
bst.read_employee("Employees-Ordered.txt");
bst.build_tree_index();
cout << "The height of BST: " << bst.getHeight() << endl;
bst.removeAllIndices();
int sN = 5;
cout << "... Try shuffling a number of times ..." << endl;
for (int i=0;i<sN;i++) {
cout << "#" << i + 1 << " shuffle ..." << endl;
bst.shuffleData();
bst.build_tree_index();
cout << "The height of BST: " << bst.getHeight() << endl;
bst.removeAllIndices();
}
bst.build_tree_index();
bst.inOrder();
return 0;
}