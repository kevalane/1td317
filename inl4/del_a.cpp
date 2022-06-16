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

//--------------------------------------------------------
// Huvudprogram:

int main()
{
  // Deklarera variabler
  

  // Läs in en rad med text från tangentbordet
  int freq[ANTAL_BOKSTAVER];
  string text = "aaaaaaaabbbbbbbb";
  for (int i = 0; i < ANTAL_BOKSTAVER; ++i) {
    freq[i] = 0;
  }
  berakna_histogram_abs(text, freq);
  for (int i = 0; i < ANTAL_BOKSTAVER; ++i) {
    cout << (char) (i + 65) << ": " << freq[i] << endl;
  }

  // Anropa funktionen berakna_histogram_abs som beräknar histogrammet
  // och antalet bokstäver.  
  
 

  // Anropa funktionen skriv_histogram_abs som skriver ut histogrammet
  

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


// Redovisning av uppgiften i ord. 
