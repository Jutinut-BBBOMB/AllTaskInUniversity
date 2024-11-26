#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(int argc, char** argv){
 string filename = "my_activities.txt";
 ofstream fout(filename.c_str(), ios::out);
 if (!fout) {
 cerr << "Error: open file for output failed!" << endl;
 abort(); // in <cstdlib> header
 }
 string activity;
 fout << "My_yesterday_activities:" << endl;
    for(int i=1; i<=3;i++){
        cout << "enter activity" << i << ":";
        getline(cin, activity);
        fout << activity << endl;
    }
 fout.close();
 return 0;
}