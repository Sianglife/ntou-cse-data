#include<iostream>
#include<functional>
using namespace std;

void proc(function<void(void)> func) { // high order function: other function as parameter.
    func();
    cout << endl;
}

void func1() {
    cout << "ABC";
}

int main() {
    proc(func1);
    proc([]{cout << "DEF";});
}