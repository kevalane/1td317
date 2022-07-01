#include <string>
#include <iomanip>
#include "constants.h"
#include "Person.h"
#include "PersonList.h"

using namespace std;

PersonList::PersonList()
: person_count(0), persons(nullptr) // nullpoint
{
}

PersonList::~PersonList()
{
    delete[] persons;
}

void PersonList::addPerson(Person newPerson)
{
    persons[person_count] = newPerson;
    person_count++;
}

PersonList::~PersonList()
{
}

void PersonList::writeAndFix(ostream &os)
{
    os << setprecision(2) << fixed;
    // print the persons
    for (int i = 0; i < person_count; i++) {
        persons[i].write(os);
    }
}

double PersonList::sumOwed()
{
    double sum = 0.0;
    for (int i = 0; i < person_count; i++) {
        sum += persons[i].getOwedOthers();
    }
    return sum;
}

double PersonList::sumPayed()
{
    double sum = 0.0;
    for (int i = 0; i < person_count; i++) {
        sum += persons[i].getPayedOthers();
    }
    return sum;
}

bool PersonList::personExists(const string &name)
{
    for (int i = 0; i < person_count; i++) {
        if (persons[i].getName().compare(name) == 0) {
            return true;
        }
    }
    return false;
}

PersonList & PersonList::operator = (const PersonList &other)
{
    if (this != &other) {
        delete[] persons;
        this->person_count = other.person_count;
        for (int i = 0; i < person_count; i++) {
            this->persons[i] = other.persons[i];
        }
    }
    return *this;
}