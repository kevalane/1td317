#include <iostream>
#include "Text.h"
#include "constants.h"

using namespace std;

Text::Text() {
    cout << "Hit" << endl;
    // text = "";
    // abs_histogram = {0};
    // letter_count = 0;
}

void Text::setText(const string &text) {
    this->text = text;
}

bool Text::calcHistogramAbs() {
    return true;
}

void Text::printHistogramAbs() {
    cout << text << endl;
}
