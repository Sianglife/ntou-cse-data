#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2){
        return 2;
    }
    return fib(n - 1) + fib(n - 2);
}

int findNearFibIndex(int n) {
    for(int cnt = 1; ;cnt++) {
        int f = fib(cnt);
        if(f > n) {
            return cnt - 1;
        } 
        if(f == n) {
            return cnt;
        }
    }
}

int main() {
    int n;
    cout << findNearFibIndex(4);
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        // cout << findNearFibIndex
    }
}