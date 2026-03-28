// AC
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // get digit
    int cnt;
    for (cnt = 1; cnt < n; cnt *= 10);
    // cout << cnt;

    // 
    int x; // current digit
    while(n > 0) {
        cnt /= 10;
        x = n / cnt;
        cout << x << endl;

        n = n % cnt;
    }

    return 0;
}