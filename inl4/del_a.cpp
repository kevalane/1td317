//
// Programskal till inlämningsuppgift 4 - deluppgift A
//
// Hanterar fallet med 26 bokstäver A-Z

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;


// Använd gärna denna globala konstant i programmet
// i stället för värdet 26
const int ANTAL_BOKSTAVER = 26;  //A-Z
// Globala variabler är ej tillåtna

//--------------------------------------------------------
// Funktionsdeklarationer:
// Använd exakt de funktionsnamn som finns nedan

// Funktionen berakna_histogram_abs
void berakna_histogram_abs(string &text, int freq[ANTAL_BOKSTAVER]);
// Funktionen skriv_histogram_abs
void skriv_histogram_abs(int freq[ANTAL_BOKSTAVER]);
//--------------------------------------------------------
// Huvudprogram:

int main()
{
    // Deklarera variabler
    int freq[ANTAL_BOKSTAVER] = {0};
    string text;

    // Läs in en rad med text från tangentbordet
    cout << "Skriv in din text: " << endl;
    getline(cin, text);

    // Anropa funktionen berakna_histogram_abs som beräknar histogrammet
    // och antalet bokstäver.  
    berakna_histogram_abs(text, freq);

    // Anropa funktionen skriv_histogram_abs som skriver ut histogrammet
    skriv_histogram_abs(freq);

    return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
void berakna_histogram_abs(string &text, int freq[ANTAL_BOKSTAVER]) {
    for (int i = 0; i < text.size(); i++) {
        if ((int) text[i] > 90) text[i] = text[i] - 32; // convert all to capital letters
        freq[ (int) text[i] - 65]++; // shift index 65, A = 0, B = 1 etc
    }
}

void skriv_histogram_abs(int freq[ANTAL_BOKSTAVER]) {
    for (int i = 0; i < ANTAL_BOKSTAVER; ++i) {
        cout << (char) (i + 65) << ": " << freq[i] << endl;
    }
}

// Redovisning av uppgiften i ord. 
