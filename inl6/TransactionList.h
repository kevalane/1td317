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
    Transaction *transactions;

public:
    TransactionList();
    ~TransactionList();
    TransactionList & operator = (const TransactionList &);
    void read(std::istream &is);
    void write(std::ostream &os);
    void addTransaction(Transaction &t);
    double totalCost();
    double personPayed(const std::string &name);
    double personOwed(const std::string &name);
    PersonList fixPersons();
};

#endif // __TransactionList__