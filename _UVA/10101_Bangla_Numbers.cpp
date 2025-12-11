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

int number_base[4] = {n4, n3, n2, n1};
string text_base[4] = {t4, t3, t2, t1};

void transfer_output(long long int n) {
    long long int tmp;
    if (n == 0) {
        cout << " " << n;
    }
    for(int i=0; i<4;) {
        while (n >= number_base[i]) {
            // cout << "\n'" << n << "'\n";
            tmp = n / number_base[i];
            if (tmp > 99) {
                transfer_output(tmp);                
                n = n % number_base[i];                
                cout << " " << text_base[i];
                continue;
            }
            n = n % number_base[i];
            cout << " " << tmp << " " << text_base[i];
        }
        i++;
        continue;
    }
    if (n != 0) {
        cout << " " << n;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0;
    long long int n;
    while(cin >> n) {
        cnt++;
        cout << "   " << cnt << ".";
        transfer_output(n);
        cout << "\n";
    }
}