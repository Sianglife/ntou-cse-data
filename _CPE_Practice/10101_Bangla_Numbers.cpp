#include<bits/stdc++.h>
#define t4 "kuti"
#define n4 10000000
#define t3 "lakh"
#define n3 100000
#define t2 "hajar"
#define n2 1000
#define t1 "shata"
#define n1 100
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mod, tmp;
    while(cin >> n) {
        cout << "ABC";
        tmp = n / n4;
        cout << tmp << "ABC";
        if (tmp != 0) {
            cout << tmp << " " << t4;
        }
    }


}