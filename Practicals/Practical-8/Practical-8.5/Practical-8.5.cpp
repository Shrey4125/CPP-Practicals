/*Question: A software development team requires a lightweight directory management system to efficiently
organize project files. The system should allow users to create folders, add files to specific folders, and
display the directory structure in an organized manner.
Each folder serves as a unique entry, mapping to a list of associated files, ensuring structured storage
and easy retrieval. A hierarchical mapping approach is used, where folder names act as keys, and
dynamically resizable sequences store the corresponding filenames.
The system provides essential functionalities, including adding new folders, appending files to existing
folders, and displaying the complete directory structure. To enhance accessibility, folder names are
sorted alphabetically, allowing users to quickly locate specific folders and their contents. Iterators are
used for efficient traversal and structured display of data. This approach ensures optimized
performance, even for large datasets, while maintaining a logical and organized hierarchy.*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    map<string, vector<string>> directory;
    string command, folder, file;

    while (true) {
        cout << "\nCommands: add_folder, add_file, show, exit\n";
        cout << "Enter command: ";
        cin >> command;

        if (command == "add_folder") {
            cout << "Enter folder name: ";
            cin >> folder;
            directory[folder]; // Initializes folder if not present
            cout << "Folder '" << folder << "' added.\n";
        }
        else if (command == "add_file") {
            cout << "Enter folder name: ";
            cin >> folder;
            if (directory.find(folder) == directory.end()) {
                cout << "Folder does not exist.\n";
                continue;
            }
            cout << "Enter file name: ";
            cin >> file;
            directory[folder].push_back(file);
            cout << "File '" << file << "' added to folder '" << folder << "'.\n";
        }
        else if (command == "show") {
            cout << "\nDirectory Structure:\n";
            for (const auto& pair : directory) {
                cout << "📁 " << pair.first << ":\n";
                for (const auto& fname : pair.second) {
                    cout << "    📄 " << fname << "\n";
                }
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid command.\n";
        }
    }

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}

