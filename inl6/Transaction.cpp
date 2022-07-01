#include <iomanip>
#include "Transaction.h"
#include "constants.h"

using namespace std;

/**
 * @brief Construct a new Transaction:: Transaction object
 * 
 */
Transaction::Transaction() 
: date(""), type(""), name(""), 
amount(0.0), number_of_friends(0), friends(nullptr)
{
}

/**
 * @brief Destroy the Transaction:: Transaction object
 * Deletes memalloc by friends array
 */
Transaction::~Transaction()
{
    delete[] friends;
}

/**
 * @brief Ensures deep copy of another Transaction object
 * 
 * @param t the transaction to copy
 */
Transaction& Transaction::operator=( const Transaction& t) {
    if (this != &t) {
        delete[] friends;
        this->date = t.date;
        this->type = t.type;
        this->name = t.name;
        this->amount = t.amount;
        this->number_of_friends = t.number_of_friends;
        this->friends = new string[number_of_friends];
        for (int i = 0; i < this->number_of_friends; i++) {
            this->friends[i] = t.friends[i];
        }
    }
    return *this;
}

/**
 * @brief Getter for name attribute
 * 
 * @return string name
 */
string Transaction::getName() {
    return this->name;
}

/**
 * @brief Getter for amount attribute
 * 
 * @return double amount
 */
double Transaction::getAmount() {
    return this->amount;
}

/**
 * @brief Getter for number_of_friends counter
 * 
 * @return int number_of_friends
 */
int Transaction::getNumberOfFriends() {
    return this->number_of_friends;
}

/**
 * @brief Checks if friend exists in list of friends
 * 
 * @param name the name to check for
 * @return true if friend exists
 * @return false if friend does not exist
 */
bool Transaction::friendExists(const string &name) {
    for (int i = 0; i < number_of_friends; i++) {
        if (this->friends[i].compare(name) == 0) return true;
    }
    return false;
}

/**
 * @brief Reads in a transaction from a given istream
 * 
 * @param is the istream to read from
 * @return true if there's more to read
 * @return false if done reading
 */
bool Transaction::read(istream &is) {
    is >> this->date >> this->type >> this->name >> this->amount >> this->number_of_friends;
    
    string *f;
    f = new string[this->number_of_friends]; // allocate memory for friends array
    // add friends to array
    for (int i = 0; i < this->number_of_friends; i++) {
        is >> f[i];
    }
    delete[] friends; // delete old array, no mem leak
    friends = f; // assign new array to old array
    return !is.eof();
}

/**
 * @brief Prints all information about a transaction
 * 
 * @param os the ostream to print to
 */
void Transaction::write(ostream &os) {
    os << left << setw(TABLE_WIDTH) << setfill(' ');
    os << this->date << setw(TABLE_WIDTH);
    os << this->type << setw(TABLE_WIDTH);
    os << this->name << setw(TABLE_WIDTH);
    os << this->amount << setw(TABLE_WIDTH);
    os << this->number_of_friends;
    for (int i = 0; i < number_of_friends; i++) {
        os << this->friends[i] << + " ";
    }
    os << endl;
}

/**
 * @brief Writes a title for all attributes of a transaction
 * 
 * @param os the ostream to print to
 */
void Transaction::writeTitle(ostream &os) {
    os << left << setw(TABLE_WIDTH) << setfill(' ');
    os << "Datum" << setw(TABLE_WIDTH);
    os << "Typ" << setw(TABLE_WIDTH);
    os << "Namn" << setw(TABLE_WIDTH);
    os << "Belopp" << setw(TABLE_WIDTH);
    os << "Antal" << setw(TABLE_WIDTH);
    os << "Lista av kompisar" << endl;
}