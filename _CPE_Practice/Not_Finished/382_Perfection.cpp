#include<iostream>
#include<string>
using namespace std;

int len(int number) {
    int i = 0;
    while(number != 0) {
        number /= 10;
        i++;
    }
    return i;
}

void output(int number, string desc) {
    int length = len(number);
    int space = 5 - length;
    while(space--) {
        cout << " ";
    }
    cout << number << "  " << desc << "\n";
}

int getFactorSum(int n) {
    int sum = 1;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            // cout << i << "  " <<  n / i << '\n';
            sum += i;
            sum += n / i; 
        }
        if(i * i > n) {
            break;
        }
    }
    // cout << "Factor "<< n<<" sum: " << sum << '\n';
    return sum;
}


int main() {
    cout << "PERFECTION OUTPUT\n";
    cout << getFactorSum(28);
    int n;
    while(cin >> n) {
        if (n == 0) continue;
        int sum = getFactorSum(n);
        if (sum == n) {
            output(n, "PERFECT");
        } else if (sum > n) {
            output(n, "ABUNDANT");
        } else {
            output(n, "DEFICIENT");
        }
    }
    cout << "END OF OUTPUT";
}