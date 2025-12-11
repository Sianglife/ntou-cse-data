#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int cnt = 0;
    while(cin >> n) {
        cnt++;
        bool sum_used[21000] = {0};
        int num[n];
        for(int i = 0; i < n; i++) {
            cin >> num[i];
        }

        for(int i = 0; i < n; i++) {
            for(int space = 0; space < n; space++) {
                if (i + space > n - 1) {
                    break;
                }

                int sum = num[i] + num[i + space];
                if (sum_used[sum] == true) {
                    cout << "Case #" << cnt << ": It is not a B2-Sequence.\n\n";
                }
            }
        }
        cout << "Case #" << cnt << ": It is a B2-Sequence.\n\n";
    }
}