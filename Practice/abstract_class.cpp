#include <iostream>
using namespace std;

class Shape {
    public:
        virtual int area() = 0;
};

class Circle: public Shape {
    public:
        int area() override {
            return radius * radius * 3;
        }
    private:
        int radius = 3;
        
};


int main() {
    Circle c;
    cout << c.area();

}