#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    char tmp;
    while(cin >> str) {
        for(int i = str.size() - 1; i >=0; i--) {
            cout << str[i];
        }
        tmp = getchar();
        if (tmp == '\n') {
            cout << tmp;
        } else if (tmp == ' ') {
            cout << tmp;
        }
    }
    return 0;
}