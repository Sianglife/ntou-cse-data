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

void moveFront(shared_ptr<Number> &current) {
    /*
    1 2 3 4 5
    1 3 2 4 5
    3:              
    pre:2       1
    next:4      2

    2: 
    pre: 1      3
    next: 3     4

    1:
    pre: null   null
    next: 2     3

    4:
    pre: 3      2
    next: 5     5

    */
    // current 往前一
    // current.previous
}
  
void sortDLL() {
    shared_ptr<Number> current;
    current = head;
    while (current->next != NULL) {
        if (current->next->getNumber() < current->getNumber()) {
            shared_ptr<Number> large, small, tmp;
            large = current;
            small = current->next;
            // Swap Order
            /*
            large:
            p = n
            n = small.n

            small:
            p = large.p
            n = p
            */
            tmp = large;
            tmp->previous = tmp->next;
            tmp->next = small->next;
            small->next = small->previous;
            small->previous = large->previous;
            large = tmp;            
        }
        current = current->next;
    }
}  
  
void printDLLNumber() {
    shared_ptr<Number> current;
    current = head;
    while (current->next != NULL) {
        cout << current->getNumber() << " ";
        current = current->next;
    }
    cout << current->getNumber() << " ";
}  
  
void readInput(vector<int> & v) {  
    string line, token;  
  
    getline(cin, line);  
    stringstream ss(line);  
  
    int count = 0;  
    while (getline(ss, token, ' ')) {  
        v.push_back(stoi(token));  
    }  
}  
  
void makeDLL(vector<int> v) {
    shared_ptr<Number> current, previous, next;
    previous = NULL;
    head = make_shared<Number>(v[0]);
    current = head;
    next = NULL;

    for (int i = 1; i < v.size(); i++) {
        next = make_shared<Number>(v[i]);
        current->next = next;
        current->previous = previous;

        previous = current;
        current = next;
    }
    current->next = NULL;
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