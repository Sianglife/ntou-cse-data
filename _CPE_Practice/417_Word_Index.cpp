#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<string> q;
    vector<string> v;
    
    // len 1
    for(int i = 'a'; i <= 'z'; i++) {
        q.push(string(1, i));
        v.push_back(string(1, i));
    }

    while(!q.empty()) {
        string prefix = q.front();
        q.pop();
        
        for(int i = 'a'; i <= 'z'; i++) {
            if (prefix.back() >= i) {
                continue;
            }
            string tmp = prefix + string(1, i);
            // cout << tmp << "\n";
            if(tmp.size() > 5) {
                continue;
            }
            q.push(tmp);
            v.push_back(tmp);
        }
    }


    string s;
    while(cin >> s) {
        int maxi = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] < maxi) {
                cout << 0 << '\n';
                maxi = -2;
                break;
            }
            maxi = s[i];
        }
        if (maxi == -2) {
            continue;
        }
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == s) {
                cout << i + 1 << '\n';
            }
        }
    }

}