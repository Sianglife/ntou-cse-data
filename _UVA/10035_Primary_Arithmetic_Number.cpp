#include<bits/stdc++.h>
using namespace std;

int getFinalDigit(int n) {
    return n % 10;
}

int getCarry(int a, int b, int carry) {
    if (a == 0 && b == 0) {
        return 0;
    }

    int addi = getFinalDigit(a) + getFinalDigit(b) + carry;
    if (addi >= 10) {
        return 1 + getCarry(a/10, b/10, 1);
    } else {
        return getCarry(a/10, b/10, 0);
    }
}

int main() {
    long long int a, b;
    unsigned int tmp;
    while(cin >> a >> b) {
        if (a == 0 && b == 0) {
            return 0;
        }
        
        tmp = getCarry(a, b, 0);
        if (tmp == 0) {
            cout << "No carry operation.\n";
        } else if (tmp == 1) {
            cout << "1 carry operation.\n";
        } else {
            cout << tmp << " carry operations.\n";
        }
    }
}