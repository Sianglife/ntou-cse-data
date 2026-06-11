#include<iostream>
using namespace std;

template <typename T>
class Calc {
    public:
        T plus(T a, T b) {
            return a + b;
        }
};

int main() {
    Calc<int> ci;
    Calc<double> cd;
    cout << ci.plus(1, 2) << endl << cd.plus(1.2, 2.4) << endl;
}
