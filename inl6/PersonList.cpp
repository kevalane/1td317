#include <string>
#include <iomanip>
#include "constants.h"
#include "Person.h"
#include "PersonList.h"

using namespace std;

PersonList::PersonList()
: person_count(0)
{
    for (int i = 0; i < MAX_PERSONS; i++) {
        persons[i] = Person();
    }
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
    os << setprecision(15);
    // print the persons
    for (int i = 0; i < person_count; i++) {
        persons[i].write(os);
    }
    os << this->sumOwed() << "==" << this->sumPayed() << endl;
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
        if (persons[i].getName() == name) {
            return true;
        }
    }
    return false;
}
