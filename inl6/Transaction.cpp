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

Transaction::~Transaction() {}