#ifndef __PERSONLIST__
#define __PERSONLIST__

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
    void writeAndFix(std::ostream &os);
    double sumOwed();
    double sumPayed();
    bool personExists(const std::string &name);
};

#endif // __PERSONLIST__