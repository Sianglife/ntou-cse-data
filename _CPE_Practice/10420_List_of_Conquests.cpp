#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    map<string, int> m;

    while(n--) {
        string tmp, country;
        cin >> country >> tmp >> tmp;
    
        if (m.find(country) != m.end()) {
            // Founded
            m[country] += 1;
        } else {
            m.insert(pair<string, int>(country, 1));
        }
    }
    
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
    return 0;
}
