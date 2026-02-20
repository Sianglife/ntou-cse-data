#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, sum;
    cin >> n;
    for(int j = 1; j <= n; j++) {
        cin >> a >> b;
        sum = 0;
        for(int i = a; i <= b; i++) {
            if(i % 2 == 1) {
                sum += i;
            }
        }
        cout << "Case " << j << ": " << sum << '\n';
    }
}