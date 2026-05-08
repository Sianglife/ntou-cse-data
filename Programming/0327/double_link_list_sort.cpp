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

shared_ptr<Number> splitMid(shared_ptr<Number> start) {
    shared_ptr<Number> slow = start;
    shared_ptr<Number> fast = start;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    shared_ptr<Number> second = slow->next;
    slow->next = nullptr;
    if (second) {
        second->previous = nullptr;
    }
    return second;
}

shared_ptr<Number> mergeSorted(shared_ptr<Number> left, shared_ptr<Number> right) {
    if (!left) return right;
    if (!right) return left;

    shared_ptr<Number> newHead;
    if (left->getNumber() <= right->getNumber()) {
        newHead = left;
        left = left->next;
    } else {
        newHead = right;
        right = right->next;
    }
    newHead->previous = nullptr;

    shared_ptr<Number> cur = newHead;
    while (left && right) {
        if (left->getNumber() <= right->getNumber()) {
            cur->next = left;
            left->previous = cur;
            left = left->next;
        } else {
            cur->next = right;
            right->previous = cur;
            right = right->next;
        }
        cur = cur->next;
    }

    if (left) {
        cur->next = left;
        left->previous = cur;
    } else if (right) {
        cur->next = right;
        right->previous = cur;
    }

    return newHead;
}

shared_ptr<Number> mergeSortDLL(shared_ptr<Number> start) {
    if (!start || !start->next) {
        return start;
    }

    shared_ptr<Number> second = splitMid(start);
    shared_ptr<Number> left = mergeSortDLL(start);
    shared_ptr<Number> right = mergeSortDLL(second);

    return mergeSorted(left, right);
}

void printDLLNumber() {
    if (!head) {
        cout << endl;
        return;
    }

    shared_ptr<Number> current = head;
    while (current->next != nullptr) {
        cout << current->getNumber() << " ";
        current = current->next;
    }
    cout << current->getNumber() << endl;
}  

void sortDLL() {
    if (!head || !head->next) {
        return;
    }

    head = mergeSortDLL(head);

    shared_ptr<Number> cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    tail = cur;
}  
  

void readInput(vector<int> & v) {  
    string line;  
  
    getline(cin, line);  
    stringstream ss(line);
    int num;
  
    while (ss >> num) {
        v.push_back(num);
    }  
}  


void makeDLL(vector<int> v) {
    shared_ptr<Number> current, previous, next; // temp pointer for iteration
    previous = nullptr; 
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
    current->next = nullptr;
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