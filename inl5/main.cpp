#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>

#include "Text.h"
#include "constants.h"

using namespace std;

int main() {
    Text t = Text();
    string s = "Testing this shizz";
    t.setText(s);
    t.printHistogramAbs();
    return 0;
}