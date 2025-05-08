/*Question: In a rapidly growing software development firm, a team of engineers is tasked with building a
lightweight, custom memory management system for handling dynamic datasets. The existing
framework lacks flexibility in managing arrays, often leading to inefficient memory usage and
performance bottlenecks. To address this, the engineers need to develop a solution that allows
seamless insertion and deletion of elements while ensuring efficient memory utilization.
The primary challenge is to design a structure that supports adding new data points dynamically at
the end of the dataset and removing specific elements based on their position. Since the system
operates in a resource-constrained environment, using standard template libraries is not an option,
and direct dynamic memory management must be implemented using pointers. The solution should
ensure that memory is allocated and deallocated appropriately to prevent leaks and unnecessary
overhead.
The development team must carefully decide on the structure of their implementation, defining how
data will be stored, accessed, and modified efficiently. They need to outline the appropriate class
design, determine essential data members, and define necessary member functions to handle the
operations effectively.*/

#include <iostream>
using namespace std;

class DynamicArray {
    int* Data;
    int Size;
    int Capacity;

    void Resize() {
        cout << "Resizing The Array ....." << endl;
        Capacity *= 2;
        int* NewData = new int[Capacity];
        for (int i = 0; i < Size; i++) {
            NewData[i] = Data[i];
        }
        delete[] Data;
        Data = NewData;
    }

public:
    DynamicArray(int C = 4) {
        Size = 0;
        Capacity = C;
        Data = new int[Capacity];
    }

    ~DynamicArray() {
        delete[] Data;
    }

    void insert(int value) {
        if (Size == Capacity) {
            Resize();
        }
        Data[Size++] = value;
    }

    void remove(int index) {
        if (index < 0 || index >= Size) {
            cout << "Invalid Index" << endl;
            return;
        }
        for (int i = index; i < Size - 1; i++) {
            Data[i] = Data[i + 1];
        }
        Size--;
    }

    void Display() const {
        for (int i = 0; i < Size; i++) {
            cout << Data[i] << endl;
        }
    }
};

int main() {
    DynamicArray arr;
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);
    arr.insert(50);
    arr.Display();

    cout << "After removing index 2:" << endl;
    arr.remove(2); // Removes 30
    arr.Display();

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
