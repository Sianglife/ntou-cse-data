#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    map<char, int> mp;
    while(cin >> a >> b) {
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                if (a[i] == b[j]) {
                    mp[a[i]]++;
                    break;
                }
            }
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            while(it->second > 0) {
                cout << it->first;
                it->second--;
            }
        }
        cout << '\n';
        mp.clear();
    }
    
}