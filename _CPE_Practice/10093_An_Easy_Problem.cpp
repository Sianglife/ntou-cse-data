#include<bits/stdc++.h>
using namespace std;

int main() {
    char input;
    while(cin >> input) {
        if(input >= '1' && input <= '9') {
            cout << input - '0' + 1;
        } else if(input >= 'A' && input <= 'Z') {
            cout << input - 'A' + 11;
        } else if(input >= 'a' && input < 'z') {
            cout << input - 'a' + 37;
        } else if(input == 'z') {
            cout << "such number is impossible!";
        }
        // TODO - such number is impossible!
        cout << '\n';
    }
    return 0;
}