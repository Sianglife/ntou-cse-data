#include<bits/stdc++.h>
using namespace std;

// TODO - TLE

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, ans, n;
    string tmp_str;
    int tmp_int;
    vector<int> vc;
    while(cin >> x) {
        cin.ignore();
        getline(cin, tmp_str);
        stringstream ss(tmp_str);
        while(ss >> tmp_int) {
            vc.push_back(tmp_int);
        }

        ans = 0;
        n = 0;
        for(int i = vc.size() - 1; i > 0; i--) {
            // cout << vc[n] << "x^" << i << "=" << i * vc[n] * (int)pow(x, i - 1) << '\n';
            ans += i * vc[n] * (int)pow(x, i - 1);
        }

        cout << ans << '\n';
    }
}