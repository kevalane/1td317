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
    fin >> this->date >> this->type >> this->name >> this->amount >> this->number_of_friends;
    for (int i = 0 ; i < this->number_of_friends; i++) {
        fin >> this->friends[i];
    }
    return !fin.eof();
}

void Transaction::write(ostream &os) {
    
}

void Transaction::writeTitle(ostream &os) {
    
}

Transaction::~Transaction() {}