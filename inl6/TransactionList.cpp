#include "TransactionList.h"
#include "Transaction.h"
#include "PersonList.h"

using namespace std;

TransactionList::TransactionList()
: transaction_count(0)
{
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        transactions[i] = Transaction();
    }
}

TransactionList::~TransactionList()
{
}

void TransactionList::read(istream &is) {
    Transaction t;
    while (t.read(is)) {
        addTransaction(t);
    }
}

void TransactionList::write(ostream &os) {
    cout << "Antal transaktioner: " << transaction_count << endl;
    transactions[0].writeTitle(os);
    for (int i = 0; i < transaction_count; i++) {
        transactions[i].write(os);
    }
}

void TransactionList::addTransaction(Transaction &t) {
    this->transactions[transaction_count] = t;
    transaction_count++;
}

double TransactionList::totalCost() {
    double total = 0;
    for (int i = 0; i < transaction_count; i++) {
        total += transactions[i].getAmount();
    }
    return total;
}

double TransactionList::personPayed(const string &name) {
    double total = 0;
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].getName().compare(name) == 0) {
            total += (transactions[i].getAmount() - (transactions[i].getAmount()/(transactions[i].getNumberOfFriends() + 1)));
        }
    }
    return total;
}

// not working implement again
double TransactionList::personOwed(const string &name) {
    double total = 0;
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].friendExists(name)) {
            total += (transactions[i].getAmount()/(transactions[i].getNumberOfFriends() + 1));
        }
    }
    return total;
}

PersonList TransactionList::fixPersons() {
    PersonList pl = PersonList();
    string name;
    double payed;
    double owed;

    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        name = transactions[i].getName();
        // check if person exists in list and don't allow empty name
        if (!pl.personExists(name) && name.compare("") != 0) {
            payed = personPayed(name);
            owed = personOwed(name);
            Person p = Person(name, payed, owed);
            pl.addPerson(p);
        }
    }
    return pl;
}