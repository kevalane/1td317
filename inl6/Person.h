#ifndef __Person__
#define __Person__

#include <string>

class Person
{
private:
    std::string name;
    double payed;
    double owed_others;
public:
    Person();
    Person(const std::string &name, double payed_others, double owed_others);
    std::string getName();
    double getPayedOthers();
    double getOwedOthers();
    void write(std::ostream &os);
};

#endif // __Person__