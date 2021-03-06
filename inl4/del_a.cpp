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
void berakna_histogram_abs(string &text, int freq[ANTAL_BOKSTAVER], int &used);
// Funktionen skriv_histogram_abs
void skriv_histogram_abs(int freq[ANTAL_BOKSTAVER], int used);
//--------------------------------------------------------
// Huvudprogram:

int main()
{
    // Deklarera variabler
    int freq[ANTAL_BOKSTAVER] = {0};
    string text;
    int used;

    // Läs in en rad med text från tangentbordet
    cout << "Ge en rad med text: " << endl;
    getline(cin, text);

    // Anropa funktionen berakna_histogram_abs som beräknar histogrammet
    // och antalet bokstäver.  
    berakna_histogram_abs(text, freq, used);

    // Anropa funktionen skriv_histogram_abs som skriver ut histogrammet
    skriv_histogram_abs(freq, used);

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

/**
 * @brief Prints out contents of array freq
 * 
 * @param freq array of length ANTAL_BOKSTAVER (26) containing all frequencies for letters
 * @param used the number of used characters
 */
void skriv_histogram_abs(int freq[ANTAL_BOKSTAVER], int used) {
    cout << "\nResultat för bokstäverna A-Z\n" << endl;
    cout << "Totala antalet bokstäver: " << used << endl;
    cout << "Bokstavsfördelning:\n" << endl;
    for (int i = 0; i < ANTAL_BOKSTAVER; ++i) {
        cout << (char) (i + 65) << ": " << freq[i] << endl;
    }
}

// Redovisning av uppgiften i ord. 
/*
Först tas en rad text som input. Valde getline för att även få med flera ord (efter mellanslag)
Sedan anropas beräkna histo, där strängen gås igenom char för char, och dess ASCII mappas mot ett index
enligt tabell. Fixar även så att gemener blir versaler. Sparar i array freq och inkrementerar referensvariabel used.
Sedan skrivs det ut, och den metoden är rätt straight forward utan vidare elaboration.
*/
