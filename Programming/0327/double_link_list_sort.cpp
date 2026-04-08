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

void swap(shared_ptr<Number> a, shared_ptr<Number> b) {    
    shared_ptr<Number> tmp, tmp_previous, tmp_next;
    if (a->previous != NULL)
        a->previous->next = b;
    else
        head = b; // If a is head, update head to b
    if (b->next != NULL)
        b->next->previous = a;
    else
        tail = a; // If b is tail, update tail to a
    tmp_previous = a->previous; 
    a->next = b->next;
    a->previous = b;
    b->next = a;
    b->previous = tmp_previous;

}

void printDLLNumber() {
    shared_ptr<Number> current;
    current = head;
    while (current->next != NULL) {
        cout << current->getNumber() << " ";
        current = current->next;
    }
    cout << current->getNumber();
}  

void sortDLL() {
    shared_ptr<Number> inner_pos, outer_pos = head; // Items after outer_pos are sorted
    while(outer_pos != tail) {
        inner_pos = head; // innter_pos is current cmp front place
        while(inner_pos != tail) {
            if (inner_pos->getNumber() > inner_pos->next->getNumber()) {
                // cout << "swap " << inner_pos->getNumber() << " and " << inner_pos->next->getNumber() << endl;
                swap(inner_pos, inner_pos->next);
                // printDLLNumber();
            }
            inner_pos = inner_pos -> next;
        }
        outer_pos = outer_pos -> next;
    }
    // cout << "sorted" << endl;
    // printDLLNumber();    
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
    sortDLL();
    printDLLNumber();  
}