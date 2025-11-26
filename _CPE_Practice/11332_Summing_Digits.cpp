#include<bits/stdc++.h>
using namespace std;

int f(long long int num) {
    if (num == 0) {
        return 0;
    }
    return num % 10 + f(num / 10);
}

int main() {
    long long int n, tmp;
    while(cin >> n) {
        if (n == 0) {
            return 0;
        }
        tmp = f(n);
        while(tmp >= 10) {
            tmp = f(tmp);
        }        
        cout << tmp << '\n';
    }
}