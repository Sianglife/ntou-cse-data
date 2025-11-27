#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    int g, n, i, j;
    while(cin >> n && n) {
        g = 0;
        for(i = 1;i < n; i++) {
            for(j = i + 1; j <= n; j++) {
                g += gcd(i, j);
            }
        }
        cout << g << '\n';
    }
    return 0;
}