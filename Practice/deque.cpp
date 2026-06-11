#include<deque>
#include<iostream>
using namespace std;

int main() {
    deque<int> d = {1, 2, 3, 4};

    deque<int>::iterator it;
    for (auto it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}
