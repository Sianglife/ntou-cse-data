#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<pair<char, int>> v;
    map<char, int> m;
    string tmp;

    // Input lines
    while(n--) {
        getline(cin, tmp);
        for(size_t it = 0; it < tmp.size(); it++) {
            char c = tmp[it];
            if(c >= 'A' && c <= 'Z') {
                m[c]++;
            } else if (c >= 'a' && c <= 'z') {
                m[c - 'a' + 'A']++;
            }
        }
    }

    // Sort
    for(auto it = m.begin(); it != m.end(); it++) {
        v.push_back(pair<char, int>(it->first, it->second));
    }
    sort(v.begin(), v.end(), cmp);

    // Output
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << it->first << " " << it->second << '\n';
    }

    return 0;    
}