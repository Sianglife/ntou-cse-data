#include<bits/stdc++.h>
using namespace std;

bool isSquare(long long n) {
    return (long long)sqrt(n) == sqrt(n);    
}

int main() {
    long long a, b, sum;
    while(cin >> a >> b && a || b) {
        sum = 0;
        for(int i = a; i <= b; i++) {
            sum += isSquare(i);
        }
        cout << sum << '\n';
    }
    return 0;
}