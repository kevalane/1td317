#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>

#include "Text.h"
#include "constants.h"

using namespace std;

// Funktionen namn_pa_fil
string namn_pa_fil();
// Funktionen inlasning
string inlasning(ifstream &fin);

int main() {
    Text t = Text();
    string s = "Testing this shizz";
    t.setText(s);
    t.calcHistogramAbs();
    t.printHistogramAbs();
    return 0;
}

/**
 * @brief Gets user input of a string value (a file name)
 * 
 * @return string the file name input by the user
 */
string namn_pa_fil() {
    string name;
    string extension = ".txt";
    cout << "Skriv in ett filnamn: " << endl;
    getline(cin, name);
    if (!equal(extension.rbegin(), extension.rend(), name.rbegin())) name += extension; // check ending
    return name;
}

/**
 * @brief Reads a file given a stream
 * 
 * @param fin stream to read from
 * @return string a string representation of all characters encountered in read stream
 */
string inlasning(ifstream &fin) {
    string text = "";
    char c;
    fin.get(c);
    while(!fin.eof()) {
        text.push_back(c);
        fin.get(c);
    }
    return text;
}