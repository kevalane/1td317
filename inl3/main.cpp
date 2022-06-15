#include <iostream>

using namespace std;

void skrivInfo();
int lasEttTal();
char lasOp();
void ordna(int &num1, int &num2);
long long int berakna(int num1, int num2, char op);
void skrivResultat(int res);

int main() {
    skrivInfo();

    // take user input
    int tal1 = lasEttTal();
    int tal2 = lasEttTal();
    char op = lasOp();

    ordna(tal1, tal2);
    long long int res = berakna(tal1, tal2, op);
    skrivResultat(res);
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
    cout << "E.g.: 4, 1 & m => 1*2*3*4 = 24 skrivs ut\n" << endl;
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

char lasOp() {
    char temp;
    cout << "Skriv operation (a/m/k): ";
    cin >> temp;
    while(cin.fail() || !(temp == 'a' || temp == 'm' || temp == 'k')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Försök igen. Endast karaktärerna 'a', 'm', 'k' tillåtna: ";
        cin >> temp;
    }
    return temp;
}

void ordna(int &num1, int &num2) {
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
}

long long int berakna(int num1, int num2, char op) {
    long long int returnValue;
    if (num1 != num2) {
        for (int i = num1; i <= num2; i++) {
            if (op == 'a') returnValue += i;
            if (op == 'm') returnValue *= i;
            if (op == 'k') returnValue += i*i;
        }
    } else {
        if (op == 'a') returnValue = num1;
        if (op == 'm') returnValue = num1;
        if (op == 'k') returnValue = num1*num1;
    }  
    return returnValue;
}

void skrivResultat(int res) {
    cout << "Resultat: " << res << endl;   
}