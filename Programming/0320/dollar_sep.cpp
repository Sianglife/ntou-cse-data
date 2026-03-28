// AC
#include<iostream>
#include<array>
using namespace std;

int main() {
    int n;
    int units[] {1000, 500, 200, 100, 50, 10, 5, 1};
    cin >> n;

    while (n--) {
        array<int, 8> cnts = {0};
        int amount;
        cin >> amount;

        int index = 0;
        while(amount > 0) {
            while(units[index] <= amount) {
                amount -= units[index];
                cnts[index]++;
            }
            index++;
        }

        for(int i = 0; i < 8; i++) {
            cout << cnts[i];
            if (i == 7) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}