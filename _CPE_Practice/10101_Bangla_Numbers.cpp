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

// TODO: 拿99999999999999試，會發現輸出>99，要再處理

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int number_base[4] = {n4, n3, n2, n1};
    string text_base[4] = {t4, t3, t2, t1};
    int cnt=0;
    long long int n, mod, tmp;
    while(cin >> n) {
        cnt++;
        cout << "   " << cnt << ".";
        for(int i=0; i<4;) {
            while (n >= number_base[i]) {
                tmp = n / number_base[i];
                if (tmp <= 99) {
                    n = n % number_base[i];
                    cout << " " << tmp << " " << text_base[i];
                } else {
                    while (n > 99) {
                        n = n % number_base[i];
                        cout << " " << tmp << " " << text_base[i];

                    }
                } 
            }
            i++;
            continue;
        }
        if (n != 0) {
            cout << " " << n << "\n";
            return 0;
        }
    }
}