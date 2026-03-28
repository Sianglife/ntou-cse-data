// AC
#include<iostream>
using namespace std;

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2); 
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << fib(i);
        if (i == (n - 1)) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}