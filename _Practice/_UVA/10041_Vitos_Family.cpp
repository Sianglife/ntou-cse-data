#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int n, r, pos, sum;
    int relative[500];
    cin >> n;
    while(n--) {
        sum = 0;
        cin >> r;
        for(int i=0; i<r; i++) {
            cin >> relative[i];
        }
        
        sort(relative, relative + r);
        
        if(r % 2 == 0) {
            pos = (relative[r/2-1] + relative[r/2]) / 2;
        } else {
            pos = relative[r/2];
        }

        for(int i=0; i<r; i++) {
            sum += abs(relative[i] - pos);
        }
        cout << sum << endl;
    }    
    return 0;
}