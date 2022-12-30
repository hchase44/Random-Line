// Copyright 2022 Chase Hollander
/*
The purpose of this program is for the user to choose any random line
from the popular classic Frankenstein. The line, the words,
and characters of each line are printed. The user is then prompted 
with a choice of two options. The first one prints the words
that are of even length. The second prints how many vowels there are.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "randomFile.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

void randomGenerator(string line) {
    int count = 0;
    std::vector<string> randLine;

    std::ifstream input("Frank.txt");
    if (input.fail()) {
        cerr << "Could not open file!" << endl;
        exit(1);
    }
    while (getline(input, line)) {
        count++;
        randLine.push_back(line);
    }
}

void printMenu() {
    std::ifstream input("Frank.txt");
    std::string read = "";
    std::string guess = "";
    std::string line = "";
    std::vector<string> lines;

    if (input.fail()) {
        cerr << "Could not open file!" << endl;
        exit(1);
    }

    while (getline(input, line)) {
        lines.push_back(line);
    }
    cout << "What would you like to know? \n" << endl;
    cout << "   1. Number of even words" << endl;
    cout << "   2. Number of vowels\n" << endl;
    cin >> guess;

    if (guess == "1") {
        evenNumbers(line);
    }
    if (guess == "2") {
        vowelsCount(line);
    }
}

void evenNumbers(std::string countEven) {
    std::string check = "";
    std::vector<string> lines;

    for (int i = 0; i < lines.size(); i++) {
        if (check.length() % 2 == 0) {
            lines.push_back(countEven);
        }
    }
        cout << "Even words: " << countEven << endl;
}
void vowelsCount(string str) {
    int vowel = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'A' || str[i] == 'a' || str[i] == 'I'
        || str[i] == 'i' || str[i] == 'E' || str[i] == 'e'
        || str[i] == 'O' || str[i] == 'o' || str[i] == 'U'
        || str[i] == 'u') {
            vowel++;
        }
    }
        cout << "Vowels: " << vowel << endl;
}
