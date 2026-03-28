// AC
#include<iostream>
using namespace std;

void print_space(int cnt) {
    for(int i = 0; i < cnt; i++) {
        cout << " ";
    }
}

void print_char(int cnt) {
    for(int i = 0; i < cnt; i++) {
        cout << "*";
    }
}

int main() {
    int n;
    cin >> n;
    int maxc = (2 * n) - 1; // largest line char count

    for(int char_cnt = 1; char_cnt <= maxc; char_cnt += 2) {
        int space_cnt = (maxc - char_cnt) / 2;

        print_space(space_cnt);
        print_char(char_cnt);
        // print_space(space_cnt);

        cout << endl;
    }
}