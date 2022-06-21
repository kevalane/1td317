#ifndef __PERSONLIST_H__
#define __PERSONLIST_H__

#include <string>
#include "constants.h"
#include "Person.h"

class PersonList {
private:
    int person_count;
    Person persons[MAX_PERSONS];

public:
    PersonList();
    ~PersonList();
    void addPerson(Person newPerson);
    void writwAndFix(std::ostream &os);
    double sumOwed();
    double sumPayed();
    bool personExists(const std::string &name);
}

#endif // __PERSONLIST_H__