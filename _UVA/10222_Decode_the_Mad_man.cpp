#include<bits/stdc++.h>
using namespace std;

map<char, char> table;

void init() {
    table[' '] = ' ';
    string str = "`1234567890-=";
    for(size_t it = 2; it < str.size(); it++) {
        table[str[it]] = str[it - 2];
    }

    str = "qwertyuiop[]\\";
    for(size_t it = 2; it < str.size(); it++) {
        table[str[it]] = str[it - 2];
    }
    
    str = "asdfghjkl;'";
    for(size_t it = 2; it < str.size(); it++) {
        table[str[it]] = str[it - 2];
    }

    str = "zxcvbnm,./";
    for(size_t it = 2; it < str.size(); it++) {
        table[str[it]] = str[it - 2];
    }
}

char convert(char c) {
    return table[c];
}

int main() {
    init();
    string str;
    while(getline(cin, str)) {
        for(size_t it = 0; it < str.size(); it++) {
            cout << convert(str[it]);
        }
        cout << "\n";
    }
    return 0;
}