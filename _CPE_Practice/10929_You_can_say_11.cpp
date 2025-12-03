#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while(cin >> str && str != "0") {
        int odd = 0, even = 0;
        for(int i = 0; i < str.size(); i++) {
            if (i % 2 == 1) {
                odd += str[i] - '0';
            } else {
                even += str[i] - '0';
            }
        }
        if (abs(even - odd) % 11 == 0) {
            cout << str << " is a multiple of 11.\n";
        } else {
            cout << str << " is not a multiple of 11.\n";
        }
    }
    return 0;
}