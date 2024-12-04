///Jutinut Ratanamongkonkul SID:6609650228
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;


struct HashNode {
    string term;               
    vector<int> lineNumbers;   
};

const int TABLE_SIZE = 1001; 
HashNode hashTable[TABLE_SIZE];
int totalCollisions = 0; 


int hashFunction(const string &word) {
    int key = 0;
    for (char c : word) {
        key += c; 
    }
    return (key * key) % TABLE_SIZE; 
}


void insertWord(const string &word, int line) {
    int hashKey = hashFunction(word); 
    int originalKey = hashKey;

    
    while (!hashTable[hashKey].term.empty() && hashTable[hashKey].term != word) {
        hashKey = (hashKey + 1) % TABLE_SIZE;
        totalCollisions++; 
        if (hashKey == originalKey) {
            cerr << "Hash Table is full! Cannot insert: " << word << endl;
            return;
        }
    }

  
    if (hashTable[hashKey].term.empty()) {
        hashTable[hashKey].term = word;
    }
    hashTable[hashKey].lineNumbers.push_back(line);
}


void searchWord(const string &word) {
    int hashKey = hashFunction(word); 
    int originalKey = hashKey;

    while (!hashTable[hashKey].term.empty()) {
        if (hashTable[hashKey].term == word) {
            
            cout << "Found \"" << word << "\" at line(s): ";
            for (int line : hashTable[hashKey].lineNumbers) {
                cout << line << " ";
            }
            cout << endl;
            return;
        }
        
        cout << "Collision with: " << hashTable[hashKey].term << endl;
        hashKey = (hashKey + 1) % TABLE_SIZE;

        if (hashKey == originalKey) {
            break; 
        }
    }

   
    cout << "Word \"" << word << "\" not found!" << endl;
}

int main() {
    ifstream file("data.txt"); 
    if (!file) {
        cerr << "Error: Cannot open file data.txt" << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;

    
    while (getline(file, line)) {
        lineNumber++;

       
        line.erase(remove_if(line.begin(), line.end(), [](char c) {
            return ispunct(c);
        }), line.end());
        transform(line.begin(), line.end(), line.begin(), ::tolower);

        stringstream ss(line);
        string word;
        while (ss >> word) {
            insertWord(word, lineNumber); 
        }
    }
    file.close();

    
    cout << "Hash Table:" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!hashTable[i].term.empty()) {
            cout << i << ": " << hashTable[i].term << " -> lines: ";
            for (int line : hashTable[i].lineNumbers) {
                cout << line << " ";
            }
            cout << endl;
        }
    }

    cout << "Total Collisions: " << totalCollisions << endl;

    
    string query;
    while (true) {
        cout << "Enter a word to search (or \"exit\" to quit): ";
        cin >> query;
        if (query == "exit") break;

        
        searchWord(query);
    }

    return 0;
}
