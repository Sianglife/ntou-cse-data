#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
using namespace std;

class Number {
private:  
    int number;  
public:  
    Number(int n) { number = n;}  
    int getNumber();  
    shared_ptr<Number> next;
    shared_ptr<Number> previous;
};  
  
int Number::getNumber() {  
    return number;  
}  
  
shared_ptr<Number> head;  
shared_ptr<Number> tail;  
  
void sortDLL() {
}  
  
void printDLLNumber() {  
}  
  
void readInput(vector & v) {  
    string line, token;  
  
    getline(cin, line);  
    stringstream ss(line);  
  
    int count = 0;  
    while (getline(ss, token, ' ')) {  
        v.push_back(stoi(token));  
    }  
}  
  
void makeDLL(vector v) {  
}  
  
int main(int argc, char * argv[]) {  
  
    vector v;  
    readInput(v);  
    if (v.size() == 0) {  
        cout << endl;  
        return 0;  
    }  
    makeDLL(v);  
    sortDLL();  
    printDLLNumber();  
}