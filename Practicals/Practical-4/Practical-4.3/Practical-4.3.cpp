/*Question : A vehicle manufacturing company sought to create a robust system to organize and manage the
details of various cars produced under its brand. To accomplish this, a hierarchical structure was
conceptualized, reflecting the essential components of a vehicle. At the foundation, a class was
designed to represent the type of fuel a vehicle uses. Another class was created to capture the brand
name of the vehicle. These two foundational elements were then combined into a derived class
specifically representing cars, integrating both fuel type and brand information.
Constructors were used at each level to ensure proper initialization of attributes, allowing seamless
integration of all details. Additionally, the ability to display complete information about a car, including
its fuel type and brand, was incorporated into the system. To simulate a real-world scenario such as a
service queue, multiple cars were organized and processed sequentially using a structured approach.
This not only streamlined the handling of cars but also provided an opportunity to compare different
methods of managing the collection and processing of vehicle data.*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Fuel {
protected:
    string fuelType;

public:
    Fuel(string type) : fuelType(type) {}
    void displayFuel() const {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand {
protected:
    string brandName;

public:
    Brand(string name) : brandName(name) {}
    void displayBrand() const {
        cout << "Brand: " << brandName << endl;
    }
};

class Car : public Fuel, public Brand {
private:
    string modelName;

public:
    Car(string brand, string fuel, string model)
        : Brand(brand), Fuel(fuel), modelName(model) {}

    void displayCarInfo() const {
        cout << "----- Car Details -----" << endl;
        displayBrand();
        displayFuel();
        cout << "Model: " << modelName << endl;
    }
};

int main() {
    queue<Car> serviceQueue;

    Car car1("Toyota", "Petrol", "Corolla");
    Car car2("Honda", "Diesel", "Civic");
    Car car3("Tesla", "Electric", "Model 3");

    serviceQueue.push(car1);
    serviceQueue.push(car2);
    serviceQueue.push(car3);

    while (!serviceQueue.empty()) {
        Car currentCar = serviceQueue.front();
        currentCar.displayCarInfo();
        serviceQueue.pop();
        cout << "Car serviced and removed from queue.\n" << endl;
    }
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
