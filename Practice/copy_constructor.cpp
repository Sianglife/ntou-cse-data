#include<iostream>
using namespace std;

class Car {
    public:
        Car() = default;
        explicit Car(const Car &car);
        Car(int a, int b) {
            this->a = a;
            this->b = b;
        }

        void getProps() {
            cout << a << " " << b << endl;   
        }        
    private:
        int a = 0;
        int b = 0;
};

Car::Car(const Car &car) {
    this->a = car.a;
    this->b = car.b;
}

int main() {
    Car c1(3, 5);
    Car c2(c1);
    // Car c2 = c1;
    c1.getProps();
    c2.getProps();
}