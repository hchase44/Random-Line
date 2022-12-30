// Copyright 2022 Chase Hollander
/*
The purpose of this program is for the user to choose any random line
from the popular classic Frankenstein. The line, the words,
and characters of each line are printed. The user is then prompted 
with a choice of two options. The first one prints the words
that are of even length. The second prints how many vowels there are.
*/
#include <iostream>
#include <string>
#include <fstream>
#include "randomFile.h"
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main() {
    string lines = "";
    int guess = 0;
    string lineNum = "";
    cout << "Choose any line number from the novel Frankenstein: ";
    cin >> guess;
    randomGenerator(lineNum);
    printMenu();
    int count = 0;
    string line = "";

    std::ifstream input("Frank.txt");
    if (input.fail()) {
        cerr << "Could not open file!" << endl;
        exit(1);
    }

    while (!input.eof()) {
        getline(input, line);
        count++;
        if (count == guess) {
            break;
        }
    }
    int wordCount = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            wordCount++;
        }
    }
    wordCount += 1;
    int charact = line.length();
    cout << line << endl;
    cout << "Characters: " << charact << endl;
    cout << "Words: " << wordCount << endl;
    input.close();
    return 0;
}
