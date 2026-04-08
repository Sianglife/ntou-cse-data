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

void reversePrintDLLNumber() {
    // iterate from tail to head
    shared_ptr<Number> current = tail;
    while (current != head) {
        cout << current->getNumber() << " ";
        current = current->previous;
    }

    cout << current->getNumber() << endl; // Print the head node (last one printed)
}  
  

void readInput(vector<int> & v) {  
    string line, token;  
  
    getline(cin, line);  
    stringstream ss(line);  // To split the input by space
  
    while (getline(ss, token, ' ')) {  
        v.push_back(stoi(token));  
    }  
}  
  
void makeDLL(vector<int> v) {
    shared_ptr<Number> current, previous, next; // temp pointer for iteration
    previous = NULL; 
    head = make_shared<Number>(v[0]);
    current = head;

    for (int i = 1; i < v.size(); i++) {
        next = make_shared<Number>(v[i]); // build next one
        // Assign the current node's properties
        current->next = next; 
        current->previous = previous;

        // Move the pointer forward
        previous = current;
        current = next;
    }
    // The last node's property
    current->next = NULL;
    current->previous = previous;
    tail = current;
}  
  
int main(int argc, char * argv[]) {    
    vector<int> v;  
    readInput(v);  
    if (v.size() == 0) {  
        cout << endl;  
        return 0;  
    }  
    makeDLL(v);
    reversePrintDLLNumber();
}