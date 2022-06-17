//
// Programskal till inlämningsuppgift 4 - deluppgift B
//
// Hanterar fallet med 26 bokstäver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

// Tips: Använd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK
// istället för värdena 26 och 4 i programmet.
const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP innehåller bokstavsfrekvensen i %
// för fyra språk. TOLK_HJALP[0][0] är frekvensen av
// bokstaven a för engelska. TOLK_HJALP[0][25] är frekvensen av
// bokstaven z för engelska.
// Arrayen är en GLOBAL KONSTANT och skall alltså ej skickas
// som parameter till den funktion som behöver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};

// Globala variabler är ej tillåtna

//--------------------------------------------------------
// Funktionsdeklarationer:

// Deklarationer av dina egna funktioner
// Använd exakt de funktionsnamn som finns nedan

// Funktionen berakna_histogram_abs
// denna skrevs i A-uppgiften och kan klippas in här
void berakna_histogram_abs(string &text, int freq[ANTAL_BOKSTAVER], int &used);
// Funktionen abs_till_rel
void abs_till_rel(int freq[ANTAL_BOKSTAVER], double rel_freq[ANTAL_BOKSTAVER], int used);
// Funktionen plotta_histogram_rel
void plotta_histogram_rel(double rel_freq[ANTAL_BOKSTAVER]);
// Funktionen tolkning
void tolkning(double rel_freq[ANTAL_BOKSTAVER]);
// Funktionen namn_pa_fil
string namn_pa_fil();
// Funktionen inlasning

//--------------------------------------------------------
// Huvudprogram:

int main()
{
    int freq[ANTAL_BOKSTAVER] = {0};
    double rel_freq[ANTAL_BOKSTAVER] = {0.0};
    int used = 0;
    string text = "ekoageagfKOAEKFIPAEGNersjbnasohjrnagros";
    berakna_histogram_abs(text, freq, used);
    abs_till_rel(freq, rel_freq, used);
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
        cout << (int) i + 65 << ": " << rel_freq[i] << "%" << endl;
    }
    plotta_histogram_rel(rel_freq);
    tolkning(rel_freq);
    cout << namn_pa_fil() << endl;
    return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
/**
 * @brief Counts frequencies of chars in a given string.
 * 
 * @param text string to count freq on
 * @param freq array to store values of freq
 * @param used number of used letters
 */
void berakna_histogram_abs(string &text, int freq[ANTAL_BOKSTAVER], int &used) {
    for (int i = 0; i < text.size(); i++) {
        if ((int) text[i] > 90) text[i] = text[i] - 32; // convert all to capital letters
        int index = (int) text[i] - 65; // shift index 65, A = 0, B = 1 etc
        if (index < ANTAL_BOKSTAVER && index >= 0) {
            freq[index]++; 
            used++;
        }
    }
}

void abs_till_rel(int freq[ANTAL_BOKSTAVER], double rel_freq[ANTAL_BOKSTAVER], int used) {
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
        rel_freq[i] = (double) freq[i]/ (double) used * 100.0;
    }
}

void plotta_histogram_rel(double rel_freq[ANTAL_BOKSTAVER]) {
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
        double times = round(rel_freq[i]/0.5);
        string stars = "";
        for (int i = 0; i < (int) times; i++) stars.push_back('*');
        cout << (char) (i + 65) << " " << stars << endl;
    }
}

void tolkning(double rel_freq[ANTAL_BOKSTAVER]) {
    double sq_sum[ANTAL_SPRAK] = {0.0};
    double min_sum = numeric_limits<double>::max();
    int min_sum_index = -1;
    for (int i = 0; i < ANTAL_SPRAK; i++) {
        double sum;
        for (int k = 0; k < ANTAL_BOKSTAVER; k++) {
            sum += (rel_freq[k] - TOLK_HJALP[i][k])*(rel_freq[k] - TOLK_HJALP[i][k]);
        }
        sq_sum[i] = sum;
        if (sum < min_sum) {
            min_sum = sum;
            min_sum_index = i;
        }
    }
    cout << "LANG: " << min_sum_index << " VAR: " << min_sum << endl;
}

string namn_pa_fil() {
    string name;
    string extension = ".txt";
    cout << "Skriv in ett filnamn: " << endl;
    getline(cin, name);
    if (!equal(extension.rbegin(), extension.rend(), name.rbegin())) name += extension; // check ending
    return name;
}
// -------------------------------------------------------
// Rapport om uppgiften
