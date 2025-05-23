/*Question: A software development team is tasked with designing a system that can handle various geometric
shapes and compute their areas in a flexible way. The challenge is to create a system that can easily
extend to accommodate new types of shapes without altering the core functionality for each shape.
To accomplish this, the system is designed with a base class called Shape, which includes a virtual
function Area(). This function is meant to be overridden by each specific shape class to provide the
correct formula for calculating the area.
The derived classes, Rectangle and Circle, each implement the Area() function with their own
formulas: the Rectangle calculates the area using its length and width, while the Circle uses its radius.
This structure allows the system to treat all shapes uniformly through a common interface, enabling
easy extensibility. The goal is to use a single reference to the base class (Shape*) to calculate the area
of any shape, regardless of its type. This approach makes the system more adaptable, as new shapes
can be added later without disrupting existing code.
In managing a collection of shapes, there are two primary approaches: one method involves
dynamically managing a collection of shapes, allowing for easy addition and removal of shapes, while
the other relies on a static method that requires manually managing the size of the collection. Both
approaches aim to store and manage the shapes effectively, with one allowing automatic resizing as
needed while the other requires more manual handling.
Through this case study, the team will implement the base class Shape and the derived classes
Rectangle and Circle, each with their own Area() function. The students will gain a deeper
understanding of polymorphism, inheritance, and memory management while working with different
methods to store and manage the collection of shapes.*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override {
        return length * width;
    }
    void display() const override {
        cout << "Rectangle: Area = " << Area() << endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override {
        return 3.14159 * radius * radius;
    }
    void display() const override {
        cout << "Circle: Area = " << Area() << endl;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 3));
    shapes.push_back(new Circle(4));
    shapes.push_back(new Rectangle(2, 7));
    shapes.push_back(new Circle(6));

    cout << "Shape Areas:" << endl;
    for (Shape* shape : shapes) {
        shape->display();
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
