/*Question: A university administration is developing a system to display student marks in a structured and visually
appealing format. The goal is to ensure clarity in academic reports by properly aligning names and
scores while also demonstrating the use of currency formatting for tuition fees or other financial data.
To achieve this, built-in stream manipulators such as endl, setw, setfill, and setprecision must be used
to create a neatly formatted output.
The system first reads student names and their corresponding marks, ensuring that the data is aligned
in tabular form. Proper spacing between columns enhances readability, preventing misalignment
issues caused by varying name lengths or mark values. Additionally, numerical values must be
displayed with controlled decimal precision for consistency.
Beyond academic scores, the university also wants to format financial figures, such as tuition fees, in
a standardized manner. To achieve this, the system includes a user-defined manipulator, currency(),
which prepends a specified currency symbol (₹, $, etc.) before displaying monetary values. This custom
formatting ensures that financial data is both readable and professionally presented.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    double marks;
    double tuition;
};

class Currency {
    char symbol;
public:
    Currency(char s) : symbol(s) {}
    friend ostream& operator<<(ostream& os, const Currency& c) {
        return os << c.symbol;
    }
};

Currency currency(char symbol) {
    return Currency(symbol);
}

int main() {
    vector<Student> students = {
        {"Alice", 89.456, 25000.50},
        {"Bob", 72.3, 18000.75},
        {"Clara", 95.78, 30500.00},
        {"David", 60.0, 17000.00}
    };

    cout << fixed << setprecision(2);
    cout << left << setw(15) << "Name"
         << right << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    for (const auto& s : students) {
        cout << left << setw(15) << s.name
             << right << setw(10) << s.marks
             << setw(5) << " " << currency('₹') << setw(8) << s.tuition << endl;
    }

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
