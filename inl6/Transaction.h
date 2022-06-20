#ifndef __Transaction__
#define __Transaction__

#include <iostream>

class Transaction {
private:
    std::string date;
    std::string type;
    std::string name;
    double amount;
    int number_of_friends;
    std::friends[1];

public:
    Transaction();
    ~Transaction();
    std::string getName();
    double getAmount();
    int getNumerOfFriends();
    bool friendExists(const std::string &name);
    bool read(istream &is);
    bool write(ostream &os);
    bool writeTitle(ostream &os);
}


#endif // __Transaction__