#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void input(vector<int> &v) {
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    return;
}

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    vector<int> v;  
    input(v);

    sort(v.begin(), v.end());

    // print(v);

    double mid;
    int size = v.size();
    if (size % 2) {
        // odd
        mid = v[size / 2];
    } else {
        // even
        mid = (v[size / 2] + v[(size / 2) - 1]) / 2.0;
    }

    cout << "Median=" << mid;
    return 0;
}