/*Question: A team of developers is tasked with building a temperature conversion system for a weather
application. To achieve this, the team creates two classes: Celsius and Fahrenheit. These classes
handle the conversion between temperature units, with the ability to convert from Celsius to
Fahrenheit and vice versa using type conversion. The team utilizes operator overloading to define the
conversion operators for both classes, enabling seamless conversions between the two units.
The system also requires the ability to compare two temperature objects to check if they are equal.
This is achieved by overloading the equality operator ==, which compares the values of the
temperatures in their respective units.
To ensure smooth processing of temperature conversions, the team needs to manage and store
multiple converted temperature objects. Two approaches are considered for handling this task. The
first approach involves using a dynamic data structure, a queue, to process the conversions in a first-
in-first-out (FIFO) manner. Alternatively, a basic array is used to store the converted objects in a static
manner.*/

#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius {
    float temp;

public:
    Celsius(float t = 0) : temp(t) {}

    float getTemp() const {
        return temp;
    }

    operator Fahrenheit();

    bool operator==(const Celsius& other) const {
        return temp == other.temp;
    }

    void display() const {
        cout << temp << "'C";
    }
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 0) : temp(t) {}

    float getTemp() const {
        return temp;
    }

    operator Celsius() {
        return Celsius((temp - 32) * 5.0 / 9);
    }

    bool operator==(const Fahrenheit& other) const {
        return temp == other.temp;
    }

    void display() const {
        cout << temp << "'F";
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9.0 / 5) + 32);
}

int main() {
    Celsius c1(25);
    Fahrenheit f1 = c1;

    cout << "Original Celsius: ";
    c1.display(); cout << endl;

    cout << "Converted to Fahrenheit: ";
    f1.display(); cout << endl;

    Fahrenheit f2(98.6);
    Celsius c2 = f2;

    cout << "Original Fahrenheit: ";
    f2.display(); cout << endl;

    cout << "Converted to Celsius: ";
    c2.display(); cout << endl;

    cout << "Are c1 and c2 equal? ";
    if (c1 == c2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    queue<Fahrenheit> tempQueue;
    tempQueue.push(f1);
    tempQueue.push(Fahrenheit(100));
    tempQueue.push(Fahrenheit(77));

    cout << "Temperatures in queue (FIFO):" << endl;
    while (!tempQueue.empty()) {
        tempQueue.front().display(); cout << endl;
        tempQueue.pop();
    }

    Celsius cArray[3] = { Celsius(0), Celsius(20), Celsius(37) };
    cout << "Temperatures in array:" << endl;
    for (int i = 0; i < 3; i++) {
        cArray[i].display(); cout << endl;
    }

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
