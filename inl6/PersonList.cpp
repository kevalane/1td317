#include <string>
#include "constants.h"
#include "Person.h"

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

bool PersonList::personExists(const std::string &name)
{
    for (int i = 0; i < person_count; i++) {
        if (persons[i].getName() == name) {
            return true;
        }
    }
    return false;
}
