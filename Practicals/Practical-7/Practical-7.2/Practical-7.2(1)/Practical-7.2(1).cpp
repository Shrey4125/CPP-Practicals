/*Question: A data analysis firm is developing a tool to process large text files and extract key statistics, such as
the total number of characters, words, and lines. This tool is essential for tasks like document indexing,
text summarization, and data validation. Given the varying sizes of input files, the system must handle
large datasets efficiently while ensuring error detection when files are missing or inaccessible.
To begin, the program needs to open a specified text file and process its contents line by line. If the
file cannot be found or opened due to permission issues, the system should notify the user with an
appropriate error message and safely terminate execution. Once the file is successfully accessed, the
program will analyze its contents to count the total number of lines, extract words while handling
different delimiters, and compute the total number of characters, including spaces and punctuation.
For handling this data, the team explores two approaches. One approach dynamically stores the lines
in a manually managed array, processing the information without relying on built-in containers. This
requires careful memory allocation and deallocation to avoid leaks. The alternative approach uses a
dynamic structure to hold the lines in memory, allowing for efficient access and further analysis, such
as searching or editing.*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    const char* filename = "sample.txt";
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Cannot open file '" << filename << "'\n";
        return 1;
    }

    const int MAX_LINES = 10000;
    char** lines = new char*[MAX_LINES];
    int lineCount = 0, wordCount = 0, charCount = 0;

    string tempLine;
    while (getline(file, tempLine) && lineCount < MAX_LINES) {
        lines[lineCount] = new char[tempLine.length() + 1];
        strcpy(lines[lineCount], tempLine.c_str());
        charCount += tempLine.length() + 1;

        char* copy = new char[tempLine.length() + 1];
        strcpy(copy, tempLine.c_str());
        char* token = strtok(copy, " \t\n,.!?;:-");

        while (token) {
            ++wordCount;
            token = strtok(nullptr, " \t\n,.!?;:-");
        }
        delete[] copy;

        ++lineCount;
    }

    cout << "Lines: " << lineCount << "\nWords: " << wordCount << "\nCharacters: " << charCount << "\n";

    for (int i = 0; i < lineCount; ++i)
        delete[] lines[i];
    delete[] lines;

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
