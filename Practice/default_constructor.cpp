#include<iostream>
using namespace std;
class Car {
    public:
        Car() = default;
        int showSpeed();
    private:
        int speed = 0;
};

int Car::showSpeed() {
    return speed;
}

int main() {
    Car c;
    cout << c.showSpeed();
}