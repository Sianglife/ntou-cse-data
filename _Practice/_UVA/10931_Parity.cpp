#include<bits/stdc++.h>
using namespace std;

int bit_size(int n) {
    // Return bit length of int n
    int i;
    for(i = 0; pow(2, i) <= n; i++) {
        // cout << pow(2, i) << '\n';
    }
    return i;
}

int main() {
    int i;
    // cout << bit_size(1) << "  " << bit_size(2) << "  " << bit_size(4)<< '\n';
    while(cin >> i && i) {
        cout << "The parity of ";
        bitset<32> bt(i);
        for(int j = bit_size(i) - 1; j >= 0; j--) {
            cout << bt[j];
        }
        cout << " is " << bt.count() << " (mod 2).\n";
    }
}