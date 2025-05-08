/*Question: An educational institution is developing a system to rank students based on their scores in an
examination. The goal is to efficiently store student names along with their respective scores, sort the
records in descending order based on scores, and display the ranked list. The system should be flexible
enough to handle varying numbers of students dynamically.
To achieve this, the system associates each student’s name with their score using a structured data
representation. A dynamically resizable sequence is chosen to store student records, allowing efficient
insertion and retrieval of entries. Each entry consists of a name-score pair, ensuring logical grouping
of related information.
Once the data is collected, a sorting operation is performed using a custom comparison function. By
leveraging an efficient sorting algorithm, the system ensures that students with the highest scores
appear at the top of the list. Iterators are then used to traverse and display the sorted data in a
structured format, highlighting rank-based ordering.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    vector<pair<string, int>> students;
    string name;
    int score;

    cout << "Enter student names and scores (type 'x' to stop):\n";
    while (true) {
        cout << "Name: ";
        cin >> name;
        if (name == "x" || name == "X") break;

        cout << "Score: ";
        if (!(cin >> score)) {
            cout << "Invalid score input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        students.push_back(make_pair(name, score));
    }

    sort(students.begin(), students.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    cout << "\nRanked Student List:\n";
    cout << left << setw(10) << "Rank" << setw(15) << "Name" << "Score" << endl;
    cout << string(35, '-') << endl;

    int rank = 1;
    for (const auto& student : students) {
        cout << left << setw(10) << rank++ << setw(15) << student.first << student.second << endl;
    }

    return 0;
}
