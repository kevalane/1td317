#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person()
: name(""), payed_others(0.0), owed_others(0.0)
{
}

Person::Person(const string &name, double payed_others, double owed_others)
: name(name), payed_others(payed_others), owed_others(owed_others)
{
}

string Person::getName()
{
    return this->name;
}

double Person::getPayedOthers()
{
    return this->payed_others;
}

double Person::getOwedOthers()
{
    return this->owed_others;
}

void Person::write(ostream &os)
{
    os << this->name << " " << this->payed_others << " " << this->owed_others << endl;
}