#include <iostream>
using namespace std;
int* rectangleArea2(int* w, int& h){
 int* result = (int*) malloc (sizeof(int));
 *result = *w*h;
 w++; h++;
 return result;
}
int main(int argc, char **argv){
 int a = 7, b = 3;
 int* x = rectangleArea2(&a, b);
 cout << x << " " << *x << endl;
 cout << a << " " << b << endl;
 return 0;
}