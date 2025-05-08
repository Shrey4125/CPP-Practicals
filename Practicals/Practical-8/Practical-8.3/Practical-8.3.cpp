/*Question: A financial analytics firm is designing a data processing system to filter out duplicate transaction IDs
from large datasets. The system must take an input list of integers, efficiently remove duplicates, and
display the unique values in an ordered manner. Given the need for high performance in handling
large datasets, the implementation must leverage efficient data structures that automatically
eliminate redundancy.
To achieve this, the system employs an associative container that inherently ensures uniqueness while
maintaining a sorted order. As integers are added, duplicate entries are automatically discarded,
eliminating the need for explicit duplicate-checking logic. Once the unique values are identified, they
are either displayed directly using iterators or converted back into a dynamically managed sequence
for further processing.
By utilizing iterators, the system efficiently traverses the filtered dataset, ensuring that unique
elements are accessed and displayed without additional computational overhead.*/

#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main() {
    set<int> transactionIDs;
    string input;

    cout << "Enter transaction IDs (type 'x' to stop): ";
    while (cin >> input) {
        if (input == "x" || input == "X") {
            break;
        }
        stringstream ss(input);
        int id;
        if (ss >> id) {
            transactionIDs.insert(id);
        }
    }

    cout << "\nUnique and Sorted Transaction IDs:\n";
    for (auto it = transactionIDs.begin(); it != transactionIDs.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}

