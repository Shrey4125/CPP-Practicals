/*Question: A small retail business is looking for a simple yet effective inventory management system to keep track
of its products. The system needs to support essential operations such as adding new items, viewing
the complete inventory, and searching for specific products. Since the inventory data should persist
across sessions, all operations must be performed using file storage. The business also requires an
efficient way to retrieve item details without unnecessary file reads.
To manage inventory, the system must allow employees to add new products by recording details
such as the item name, quantity, and price. These records should be appended to a file, ensuring that
previously stored data remains intact. When viewing inventory, the system should read the file
sequentially and display all stored items. Additionally, employees should be able to search for a
product by name, retrieving its details without manually scanning the entire file.
For implementation, two approaches are considered. One method processes file operations directly,
reading and searching line by line to retrieve item information efficiently. This minimizes memory
usage but requires re-reading the file for each search operation. An alternative approach loads
inventory data into a dynamically managed array, enabling faster searches and future enhancements
such as sorting and filtering without repeated file access.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addItem(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Cannot open file.\n";
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;

    outFile << name << " " << quantity << " " << price << "\n";
    outFile.close();
}

void viewInventory(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Cannot open file.\n";
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Inventory:\n";
    while (inFile >> name >> quantity >> price) {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: " << price << "\n";
    }

    inFile.close();
}

void searchItem(const string& filename, const string& target) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Cannot open file.\n";
        return;
    }

    string name;
    int quantity;
    double price;
    bool found = false;

    while (inFile >> name >> quantity >> price) {
        if (name == target) {
            cout << "Found: Name: " << name << ", Quantity: " << quantity << ", Price: " << price << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Item not found.\n";

    inFile.close();
}

int main() {
    const string filename = "inventory.txt";
    int choice;
    string itemName;

    do {
        cout << "\n1. Add Item\n2. View Inventory\n3. Search Item\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(filename);
                break;
            case 2:
                viewInventory(filename);
                break;
            case 3:
                cout << "Enter item name to search: ";
                cin >> itemName;
                searchItem(filename, itemName);
                break;
        }
    } while (choice != 0);

    return 0;
}
