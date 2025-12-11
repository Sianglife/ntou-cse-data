#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<bool> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(true);
        } else if (s[i] == ')') {
            if(st.empty()) {
                return false;
            }
            
            if(st.top() == true) {
                st.pop();
            } else {
                return false;
            }
        } else if (s[i] == '[') {
            st.push(false);
        } else if (s[i] == ']') {
            if(st.empty()) {
                return false;
            }
            
            if(st.top() == false) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    int n;
    cin >> n;
    getchar();
    while(n--) {
        string str;
        getline(cin, str);
        if (str == "" || isValid(str)) {
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
    }
    return 0;
}