#include<bits/stdc++.h>
using namespace std;

int cnt;

int algo(int n) {
    cnt++;
    if (n == 1) {
        return cnt;
    }
    if (n % 2 == 1) {
        return algo(3 * n + 1);
    } else {
        return algo(n / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j, maxi, tmp, a, b;
    while(cin >> i >> j) {
        if (i > j) {
            a = j;
            b = i;
        } else {
            a = i;
            b = j;
        }
        
        maxi = 0;

        for(int c=a; c<=b; c++) {
            cnt = 0;
            tmp = algo(c);
            maxi = max(tmp, maxi);
        }
        cout << i << " " << j << " " << maxi << "\n";
    }
}