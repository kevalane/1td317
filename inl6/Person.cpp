#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

/**
 * @brief Construct a new Person:: Person object
 * 
 */
Person::Person()
: name(""), payed(0.0), owed_others(0.0)
{
}

/**
 * @brief Construct a new Person:: Person object
 * 
 * @param name string name of person
 * @param payed double how much the person has paid
 * @param owed_others double how much the person owes others
 */
Person::Person(const string &name, double payed, double owed_others)
: name(name), payed(payed), owed_others(owed_others)
{
}

/**
 * @brief getter for attribute name
 * 
 * @return string name
 */
string Person::getName()
{
    return this->name;
}

/**
 * @brief getter for paid others
 * 
 * @return double amount paid others
 */
double Person::getPayedOthers()
{
    return this->payed;
}

/**
 * @brief getter for owed others
 * 
 * @return double owed others
 */
double Person::getOwedOthers()
{
    return this->owed_others;
}

/**
 * @brief Gives a brief summary of a persons standing
 * 
 * @param os ostream to write to
 */
void Person::write(ostream &os)
{
    os << this->name << " ligger ute med " << this->payed << " och är skyldig " << this->owed_others << ".";
    double diff = this->payed - this->owed_others;
    if (diff >= 0) os << " Skall ha " << diff << " från potten!" << endl;
    else os << " Ska betala " << -diff << " till potten!" << endl;
}