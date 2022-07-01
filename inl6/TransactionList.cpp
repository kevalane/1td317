#include "TransactionList.h"
#include "Transaction.h"
#include "PersonList.h"

using namespace std;

/**
 * @brief Construct a new Transaction List:: Transaction List object
 * 
 */
TransactionList::TransactionList()
: transaction_count(0), transactions(nullptr)
{
}

/**
 * @brief Destroy the Transaction List:: Transaction List object
 * 
 */
TransactionList::~TransactionList()
{
    delete[] transactions;
}

/**
 * @brief Ensures deep copy of another transactionlist
 * 
 * @param other the TransactionList to copy
 */
TransactionList & TransactionList::operator = (const TransactionList &other) {
    if (this != &other) {
        delete[] transactions;
        this->transaction_count = other.transaction_count;
        for (int i = 0; i < transaction_count; i++) {
            this->transactions[i] = other.transactions[i];
        }
    }
    return *this;
}

/**
 * @brief Reads an instream of transactions and adds them to the list
 * 
 * @param is the istream to read from
 */
void TransactionList::read(istream &is) {
    Transaction t;
    while (t.read(is)) {
        addTransaction(t);
    }
}

/**
 * @brief Writes the list of transactions to an ostream
 * 
 * @param os the ostream to write to
 */
void TransactionList::write(ostream &os) {
    cout << "Antal transaktioner: " << transaction_count << endl;
    transactions[0].writeTitle(os);
    for (int i = 0; i < transaction_count; i++) {
        transactions[i].write(os);
    }
}

/**
 * @brief Adds a new transaction to list of transactions
 * 
 * @param newTransaction the transaction to add to TransactionList
 */
void TransactionList::addTransaction(Transaction &newTransaction) {
    Transaction *t = nullptr;
    t = new Transaction[transaction_count + 1]; // create new array of new size
    for (int i = 0; i < transaction_count; i++) {
        t[i] = this->transactions[i]; // copy
    }
    t[transaction_count] = newTransaction;
    transaction_count++;
    delete[] transactions; // delete old array, 'cancels' new keyword
    transactions = t;
}

/**
 * @brief Calculates total cost of all transactions
 * 
 * @return double sum of all transactions
 */
double TransactionList::totalCost() {
    double total = 0;
    for (int i = 0; i < transaction_count; i++) {
        total += transactions[i].getAmount();
    }
    return total;
}

/**
 * @brief Calculates how much a person has paid in total given their name
 * 
 * @param name the name of person to check
 * @return double total person paid
 */
double TransactionList::personPayed(const string &name) {
    double total = 0;
    for (int i = 0; i < transaction_count; i++) { // for each transaction
        if (transactions[i].getName().compare(name) == 0) { // if name matches
            // persons share = total amount - (total amount)/(total people sharing)
            total += (transactions[i].getAmount() - (transactions[i].getAmount()/(transactions[i].getNumberOfFriends() + 1)));
        }
    }
    return total;
}

/**
 * @brief calculates what a specific person is owed
 * 
 * @param name the name of person to check
 * @return double total person owed
 */
double TransactionList::personOwed(const string &name) {
    double total = 0;
    for (int i = 0; i < transaction_count; i++) { // for each transaction
        if (transactions[i].friendExists(name)) { // if name matches
            total += (transactions[i].getAmount()/(transactions[i].getNumberOfFriends() + 1)); // persons share = total amount / (total people sharing)
        }
    }
    return total;
}

/**
 * @brief creates a PersonList of all people who are part of any transaction
 * 
 * @return PersonList a list of persons with their paid and owerd calculated
 */
PersonList TransactionList::fixPersons() {
    PersonList pl = PersonList();
    string name;
    double payed;
    double owed;

    for (int i = 0; i < this->transaction_count; i++) { 
        name = transactions[i].getName();
        if (!pl.personExists(name) && name.compare("") != 0) { // check if person exists in list and don't allow empty name
            payed = personPayed(name);
            owed = personOwed(name);
            Person p = Person(name, payed, owed); // create person with calculated payed and owed
            pl.addPerson(p);
        }
    }
    return pl;
}