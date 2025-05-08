/*Question: A media research team is developing a tool to analyze word frequency in large textual datasets, such
as news articles and research papers. The goal is to process a given paragraph, identify individual
words, and count their occurrences while ensuring case-insensitive matching. Since the tool is
intended for both constrained environments and high-performance systems, two different
approaches are considered—one utilizing dynamic memory management and another relying on
manually structured arrays.
The first challenge is reading an entire paragraph from the console as a single unformatted string.
Once acquired, the text must be split into individual words, ensuring that uppercase and lowercase
variations are treated as the same. To store and process words dynamically, the team designs a

mechanism using raw pointers and dynamic memory allocation, allowing the program to handle
variable input sizes effectively.
In one approach, a dynamically allocated array is used to store words, with additional logic to count
occurrences efficiently. The array expands as needed, ensuring that new words can be
accommodated. The frequency counting is implemented manually by searching for existing words in
the array and updating counts accordingly.*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_WORDS = 100;
const int MAX_WORD_LEN = 50;

struct WordEntry {
    char word[MAX_WORD_LEN];
    int count;
};

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

bool isAlphaNum(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

int findWord(WordEntry words[], int size, const char word[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i].word, word) == 0)
            return i;
    }
    return -1;
}

int main() {
    WordEntry words[MAX_WORDS];
    int wordCount = 0;

    string text;
    cout << "Enter a paragraph:" << endl;
    getline(cin, text);

    char currentWord[MAX_WORD_LEN];
    int letterCount = 0;

    for (int i = 0; i < text.length(); i++) {
        char c = toLowerChar(text[i]);

        if (isAlphaNum(c)) {
            if (letterCount < MAX_WORD_LEN - 1) {
                currentWord[letterCount++] = c;
            }
        } else if (letterCount > 0) {
            currentWord[letterCount] = '\0';
            int index = findWord(words, wordCount, currentWord);
            if (index != -1) {
                words[index].count++;
            } else {
                strcpy(words[wordCount].word, currentWord);
                words[wordCount].count = 1;
                wordCount++;
            }
            letterCount = 0;
        }
    }

    if (letterCount > 0) {
        currentWord[letterCount] = '\0';
        int index = findWord(words, wordCount, currentWord);
        if (index != -1) {
            words[index].count++;
        } else {
            strcpy(words[wordCount].word, currentWord);
            words[wordCount].count = 1;
            wordCount++;
        }
    }

    cout << "Word Frequencies:" << endl;
    for (int i = 0; i < wordCount; i++) {
        cout << words[i].word << ": " << words[i].count << endl;
    }


    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
