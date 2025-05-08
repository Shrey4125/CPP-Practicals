/*Question: A financial analytics company is working on a system that processes large volumes of sorted numerical
data from different sources. The challenge is to efficiently combine two independently sorted datasets
into a single, fully sorted dataset while ensuring optimal memory management. Since the size of the
datasets varies dynamically based on incoming data streams, the solution must be flexible and manage
memory efficiently without relying on built-in container libraries.
To achieve this, the development team needs to implement a mechanism that accepts two sorted
arrays of different sizes and merges them into a new dynamically allocated array while maintaining
the sorted order. The system should read input values specifying the sizes of both datasets, followed
by the elements of each array. After merging, the final sorted array should be displayed as output.
Efficient memory handling is crucial in this implementation, requiring the use of new and delete
operators for dynamic allocation and deallocation of memory.*/

#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int s) : size(s) {
        data = new int[size];
    }

    ~DynamicArray() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size)
            data[index] = value;
    }

    int get(int index) const {
        if (index >= 0 && index < size)
            return data[index];
        return -1;
    }

    void read() {
        for (int i = 0; i < size; ++i)
            cin >> data[i];
    }

    void print() const {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    friend DynamicArray mergeSortedArrays(const DynamicArray& a, const DynamicArray& b);
};

DynamicArray mergeSortedArrays(const DynamicArray& a, const DynamicArray& b) {
    int size1 = a.getSize();
    int size2 = b.getSize();
    DynamicArray result(size1 + size2);

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (a.get(i) <= b.get(j))
            result.set(k++, a.get(i++));
        else
            result.set(k++, b.get(j++));
    }

    while (i < size1)
        result.set(k++, a.get(i++));

    while (j < size2)
        result.set(k++, b.get(j++));

    return result;
}

int main() {
    int size1, size2;

    cout << "Enter size of first sorted array: ";
    cin >> size1;
    cout << "Enter size of second sorted array: ";
    cin >> size2;

    DynamicArray arr1(size1);
    DynamicArray arr2(size2);

    cout << "Enter elements of the first sorted array: ";
    arr1.read();

    cout << "Enter elements of the second sorted array: ";
    arr2.read();

    DynamicArray merged = mergeSortedArrays(arr1, arr2);

    cout << "Merged sorted array: ";
    merged.print();

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
