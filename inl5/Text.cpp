#include <iostream>
#include "Text.h"
#include "constants.h"

using namespace std;

Text::Text() {
    text = "";
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) abs_histogram[i] = 0;
    letter_count = 0;
}

void Text::setText(const string &text) {
    this->text = text;
}

bool Text::calcHistogramAbs() {
    if (this->text.size() == 0) return false;
    for (int i = 0; i < this->text.size(); i++) {
        if ((int) text[i] > 90) this->text[i] = this->text[i] - 32; // convert all to capital letters
        int index = (int) this->text[i] - 65; // shift index 65, A = 0, B = 1 etc
        if (index < ANTAL_BOKSTAVER && index >= 0) {
            this->abs_histogram[index]++; 
            this->letter_count++;
        }
    }
    return true;
}

void Text::printHistogramAbs() {
    cout << "\nResultat för bokstäverna A-Z\n" << endl;
    cout << "Totala antalet bokstäver: " << this->letter_count << endl;
    cout << "Bokstavsfördelning:\n" << endl;
    for (int i = 0; i < ANTAL_BOKSTAVER; ++i) {
        cout << (char) (i + 65) << ": " << this->abs_histogram[i] << endl;
    }
}