#include <iostream>

using namespace std;

void skrivInfo();
void lasEttTal();

int main() {
    skrivInfo();
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

void lasEttTal() {
    
}