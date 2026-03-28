#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int notes[] = {1000, 500, 200, 100, 50, 10, 5, 1};
    int number;
    while(n--) {
        cin >> number;
        vector<int> count(8, 0);
        while(number > 0) {
            for (int i = 0; i < 8; i++) {
                if (number >= notes[i]) {
                    count[i]++;
                    number -= notes[i];
                    break;
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            if (i == 7) {
                cout << count[i] << endl;
            } else {
                cout << count[i] << " ";
            }
        }
    }
}