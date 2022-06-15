#include <iostream>

using namespace std;

void skrivInfo();
int lasEttTal();

int main() {
    int num = lasEttTal();
    cout << num << endl;
    return 0;
}

void skrivInfo() {
    cout << "Detta program utför beräkningar på alla heltal mellan två från användaren inmatade heltal." << endl;
    cout << "1. Användaren efterfrågas att mata in två heltal." << endl;
    cout << "2. Användaren efterfrågas vilken operation som skall genomföras. Tre alternativ finns: " << endl;
    cout << "i) a: Addera tal" << endl;
    cout << "ii) m: Multiplicera tal" << endl;
    cout << "iii) k: Beräkna kvadratsumman av tal" << endl;
    cout << "E.g.: 3, 5 & k => 3*3 + 4*4 + 5*5 = 50 skrivs ut" << endl;
    cout << "E.g.: 4, 1 & m => 1*2*3*4 = 24 skrivs ut" << endl;
}

int lasEttTal() {
    int temp;
    cout << "Skriv ett heltal: ";
    cin >> temp;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Försök igen. Skriv ett heltal: ";
        cin >> temp;
    }
    return temp;
}