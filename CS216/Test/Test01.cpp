#include<iostream>
#include<iomanip>

using namespace std;

int main (){
	
	double x = 15.2;
	double y = 34.3434343;
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << setw(6) << x << endl;
	cout << setw(7) << y << endl;
	
	

	return 0; 
}
