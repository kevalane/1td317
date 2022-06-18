#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>

#include "Text.h"
#include "constants.h"

using namespace std;

Text::Text() {
    this->text = "";
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
        this->abs_histogram[i] = 0;
        this->rel_histogram[i] = 0.0;
    }
    this->letter_count = 0;
}

/**
 * @brief Setter for text attribute
 * 
 * @param text to use for the set
 */
void Text::setText(const string &text) {
    this->text = text;
}

/**
 * @brief Counts frequencies of chars in a given string.
 * 
 * @param text string to count freq on
 * @param freq array to store values of freq
 * @param used number of used letters
 */
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

/**
 * @brief Prints out contents of array freq
 * 
 * @param freq array of length ANTAL_BOKSTAVER (26) containing all frequencies for letters
 * @param used the number of used characters
 */
void Text::printHistogramAbs() {
    cout << "\nResultat för bokstäverna A-Z\n" << endl;
    cout << "Totala antalet bokstäver: " << this->letter_count << endl;
    cout << "Bokstavsfördelning:\n" << endl;
    for (int i = 0; i < ANTAL_BOKSTAVER; ++i) {
        cout << (char) (i + 65) << ": " << this->abs_histogram[i] << endl;
    }
}

/**
 * @brief Converts frequency to relative frequency
 * 
 * @param freq array of freq
 * @param rel_freq array of rel freq added my this function
 * @param used the number of used letters
 */
void Text::absToRel() {
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
        this->rel_histogram[i] = (double) this->abs_histogram[i]/ (double) this->letter_count * 100.0;
    }
}

/**
 * @brief Used to plot the histogram given relative frequencies.
 * 
 * @param rel_freq array of doubles containing relative frequencies.
 */
void Text::plotHistogramRel() {
    cout << "\nBokstavsfördelning:\n" << endl;
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
        double times = round(this->rel_histogram[i]/0.5);
        string stars = "";
        for (int i = 0; i < (int) times; i++) stars.push_back('*');
        cout << (char) (i + 65) << " " << stars << endl;
    }
}

/**
 * @brief Calculates the relative histogram and prints is
 * 
 */
void Text::calcHistogram() {
    this->absToRel();
    this->plotHistogramRel();
}

/**
 * @brief Calculates square error and determines a strings language.
 * 
 * @param rel_freq relative frequencies for letters occurrance.
 * @param used number of used letters
 * @return string the name of the guessed language
 */
string Text::interpret() {
    double sq_sum[ANTAL_SPRAK] = {0.0};
    double min_sum = numeric_limits<double>::max();
    int min_sum_index = -1;
    for (int i = 0; i < ANTAL_SPRAK; i++) {
        double sum = 0;
        for (int k = 0; k < ANTAL_BOKSTAVER; k++) {
            sum += (TOLK_HJALP[i][k] - this->rel_histogram[k])*(TOLK_HJALP[i][k] - this->rel_histogram[k]);
        }
        sq_sum[i] = sum;
        if (sum < min_sum) {
            min_sum = sum;
            min_sum_index = i;
        }
    }
    
    cout << "\nResultat för bokstäverna A-Z" << endl;
    cout << "\nTotala antalet bokstäver: " << this->letter_count << endl;
    cout << "Engelska har kvadratsumma = " << sq_sum[0] << endl;
    cout << "Franska har kvadratsumma = " << sq_sum[1] << endl;
    cout << "Svenska har kvadratsumma = " << sq_sum[2] << endl;
    cout << "Tyska har kvadratsumma = " << sq_sum[3] << endl;
    cout << "Det är mest troligt att språket är ";
    switch(min_sum_index) {
        case 0:
            cout << "engelska" << endl;
            return "engelska";
            break;
        case 1:
            cout << "franska" << endl;
            return "franska";
            break;
        case 2:
            cout << "svenska" << endl;
            return "svenska";
            break;
        case 3:
            cout << "tyska" << endl;
            return "tyska";
            break;
        default:
            cout << "error" << endl;
            return "error";
            break;
    }
}