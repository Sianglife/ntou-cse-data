// AC
#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

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
        int left = 0, right = 9, mid;
        int result = -1;
        while(true) {
            if (left == right) {
                break;
            }
            mid = (left + right) / 2;
            // cout << "left: "<< left << " ,right: " << right << " ,mid: " << mid << endl;
            
            if (target == arr[mid]) {
                result = mid;
                break;
            } else if (target > arr[mid]) {
                // target in right
                left = mid + 1;
            } else if (target < arr[mid]) {
                // target in left
                right = mid;
            }
        }

        cout << result << endl;
    }
}