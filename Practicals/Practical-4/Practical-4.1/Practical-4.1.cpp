#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    double radius;

public:
    Shape(double r):radius(r){}
    double getRadius()const 
    {
        return radius;
    }
};

class Circle: public Shape {
public:
    Circle(double r): Shape(r){}
    double calculateArea()const 
    {
        return M_PI*radius*radius;
    }
};

int main() {
    Circle circle1(3.5);
    Circle circle2(5.2);
    Circle circle3(7.0);

    cout<<"Circle with radius "<<circle1.getRadius()<<" has area: " <<circle1.calculateArea()<<endl;
    cout<<"Circle with radius "<<circle2.getRadius()<<" has area: " <<circle2.calculateArea()<<endl;
    cout<<"Circle with radius "<<circle3.getRadius()<<" has area: " <<circle3.calculateArea()<<endl;
    
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
