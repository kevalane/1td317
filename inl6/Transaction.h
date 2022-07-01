#ifndef __Transaction__
#define __Transaction__

#include <iostream>
#include "constants.h"

class Transaction {
private:
    std::string date;
    std::string type;
    std::string name;
    double amount;
    int number_of_friends;
    // std::string *friends;
    std::string friends[MAX_PERSONS];
public:
    Transaction();
    ~Transaction();
    Transaction & operator = (const Transaction &);
    std::string getName();
    double getAmount();
    int getNumberOfFriends();
    bool friendExists(const std::string &name);
    bool read(std::istream &is);
    void write(std::ostream &os);
    void writeTitle(std::ostream &os);
};


#endif // __Transaction__