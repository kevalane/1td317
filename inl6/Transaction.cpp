#include <iomanip>
#include "Transaction.h"
#include "constants.h"

using namespace std;

Transaction::Transaction() 
: date(""), type(""), name(""), 
amount(0.0), number_of_friends(0)
{
    for (int i = 0 ; i < MAX_PERSONS; i++) {
        this->friends[i] = "";
    }
}

string Transaction::getName() {
    return this->name;
}

double Transaction::getAmount() {
    return this->amount;
}

int Transaction::getNumerOfFriends() {
    return this->number_of_friends;
}

bool Transaction::friendExists(const string &name) {
    for (int i = 0; i < MAX_PERSONS; i++) {
        if (this->friends[i] == name) return true;
    }
    return false;
}

bool Transaction::read(istream &is) {
    is >> this->date >> this->type >> this->name >> this->amount >> this->number_of_friends;
    for (int i = 0 ; i < this->number_of_friends; i++) {
        is >> this->friends[i];
    }
    return !is.eof();
}

void Transaction::write(ostream &os) {
    
}

void Transaction::writeTitle(ostream &os) {
    os << "Datum" << setw(10);
    os << "Typ" << setw(10);
    os << "Namn" << setw(10);
    os << "Belopp" << setw(10);
    os << "Antal" << setw(20);
    os << "Lista av kompisar" << endl;
}

Transaction::~Transaction() {}