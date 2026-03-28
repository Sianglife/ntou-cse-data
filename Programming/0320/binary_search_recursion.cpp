// AC
#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

int bin_search(array<int, 10> &arr, int target, int left = 0, int right= 9) {
    if (left == right && arr[left] != target) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (target == arr[mid]) {
        return mid;
    } else if (target > arr[mid]) {
        // target in right
        return bin_search(arr, target, mid + 1, right);
    } else {
        // target in left
        return bin_search(arr, target, left, mid);
    }
}

int main() {
    int n, target;
    array<int, 10> arr;
    cin >> n;
    while (n--) {
        arr.empty();
        for(int i = 0; i < 10; i++) {
            cin >> arr[i];
        }
        cin >> target;

        sort(arr.begin(), arr.end());

        cout << bin_search(arr, target) << endl;
    }
    return 0;
}