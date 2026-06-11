#include<iostream>
using namespace std;

int main() {
    try {
        throw 20;
    } catch (int e) {
        cout << e << endl;
    }
}