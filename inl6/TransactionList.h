#ifndef __TransactionList__
#define __TransactionList__

#include <string>
#include "Transaction.h"
#include "constants.h"
#include "Person.h"
#include "PersonList.h"

class TransactionList {
private:
    int transaction_count;
    Transaction transactions[MAX_TRANSACTIONS];

public:
    TransactionList();
    ~TransactionList();
    void read(istream &is);
    void write(ostream &os);
    void addTransaction(Transaction &t);
    double totalCost();
    double personPayed(const string &name);
    double personOwed(const string &name);
    PersonList FixPersons();
};

#endif // __TransactionList__