#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person()
: name(""), payed(0.0), owed_others(0.0)
{
}

Person::Person(const string &name, double payed, double owed_others)
: name(name), payed(payed), owed_others(owed_others)
{
}

string Person::getName()
{
    return this->name;
}

double Person::getPayedOthers()
{
    return this->payed;
}

double Person::getOwedOthers()
{
    return this->owed_others;
}

void Person::write(ostream &os)
{
    os << this->name << " ligger ute med " << this->payed << " och är skyldig " << this->owed_others << ".";
    os << " Skall ha " << this->payed - this->owed_others << " från potten!" << endl;
}