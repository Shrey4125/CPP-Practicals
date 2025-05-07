#include<iostream>
#include<vector>
#include<chrono>
using namespace std;

vector<int> getArrayFromUser() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        cout << "Enter value " << ": ";
        cin >> arr[i];
    }
    return arr;
}

int iterativeSum(const vector<int>& arr) {
    int total = 0;
    for (int num : arr) total += num;
    return total;
}

int recursiveSum(const vector<int>& arr, int index) {
    if (index < 0) return 0;
    return arr[index] + recursiveSum(arr, index - 1);
}

int main() {
    vector<int> array = getArrayFromUser();
    const int runs = 1000;

    auto startIter = chrono::high_resolution_clock::now();
    int iterResult = 0;
    for (int i = 0; i < runs; ++i)
        iterResult = iterativeSum(array);
    auto endIter = chrono::high_resolution_clock::now();

    auto startRec = chrono::high_resolution_clock::now();
    int recResult = 0;
    for (int i = 0; i < runs; ++i)
        recResult = recursiveSum(array, array.size() - 1);
    auto endRec = chrono::high_resolution_clock::now();

    cout << "Iterative Sum: " << iterResult << "\n"
         << "Recursive Sum: " << recResult << "\n";

    auto iterDuration = chrono::duration_cast<chrono::nanoseconds>(endIter - startIter).count() / runs;
    auto recDuration = chrono::duration_cast<chrono::nanoseconds>(endRec - startRec).count() / runs;

    cout << "Time For Iterative Sum: " << iterDuration << " ns (average)\n";
    cout << "Time For Recursive Sum: " << recDuration << " ns (average)\n";

    cout << "\n24CE106 - Shrey Rathod\n";
    return 0;
}
