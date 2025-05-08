/*Question: A data analytics firm is developing a tool to process numerical sequences efficiently. One of the key
requirements is to reverse a given sequence of integers while ensuring optimized performance using
modern C++ techniques. The system should allow users to input a sequence of numbers, process the
reversal using iterators, and display the transformed output.
To accomplish this, two approaches are explored. The first method leverages the built-in std::reverse()
function, which efficiently reverses elements within a dynamically managed sequence. The second
approach involves manually implementing the reversal using iterators, providing deeper insight into
how iterators navigate and modify data structures.
The system uses a dynamic storage mechanism to handle sequences of varying sizes efficiently.
Iterators facilitate traversal and modification, ensuring that elements are manipulated without direct
indexing.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


void reverseWithIterators(vector<int>& seq) {
    auto front = seq.begin();
    auto back = seq.end();
    while (front < --back) {
        iter_swap(front, back);
        ++front;
    }
}

void displaySequence(const vector<int>& seq) {
    for (int num : seq) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> sequence;
    int num;

    cout << "Enter integers (type 'x' to stop): ";
    while (cin >> num) {
        sequence.push_back(num);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nOriginal sequence:\n";
    displaySequence(sequence);


    vector<int> stdReversed = sequence;
    reverse(stdReversed.begin(), stdReversed.end());
    cout << "\nReversed using std::reverse:\n";
    displaySequence(stdReversed);

    vector<int> iterReversed = sequence;
    reverseWithIterators(iterReversed);
    cout << "\nReversed using manual iterators:\n";
    displaySequence(iterReversed);

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
