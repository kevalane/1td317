#include <string>
#include <iomanip>
#include "constants.h"
#include "Person.h"
#include "PersonList.h"

using namespace std;

/**
 * @brief Construct a new Person List:: Person List object
 * 
 */
PersonList::PersonList()
: person_count(0), persons(nullptr) // nullpoint
{
}

/**
 * @brief Destroy the Person List:: Person List object
 * Deletes pointer ref
 */
PersonList::~PersonList()
{
    delete[] persons;
}

/**
 * @brief Add new person to the list
 * 
 * @param newPerson the Person object to add
 */
void PersonList::addPerson(Person newPerson)
{
    Person *p = nullptr;
    p = new Person[person_count + 1]; // new, now we need delete[] later
    for (int i = 0; i < person_count; i++) {
        p[i] = persons[i];
    }
    p[person_count] = newPerson; // last person in array is new person
    person_count++; // increment num persons
    delete[] persons; // delete old array, no mem leak
    persons = p; // assign new array to old array
}

/**
 * @brief Uses the Person::write() function to print the list of people
 * 
 * @param os the ostream to print to
 */
void PersonList::writeAndFix(ostream &os)
{
    os << setprecision(2) << fixed;
    // print the persons
    for (int i = 0; i < person_count; i++) {
        persons[i].write(os);
    }
}

/**
 * @brief Gets the sum of all the people's owed amounts
 * 
 * @return double the sum amount owed
 */
double PersonList::sumOwed()
{
    double sum = 0.0;
    for (int i = 0; i < person_count; i++) {
        sum += persons[i].getOwedOthers();
    }
    return sum;
}

/**
 * @brief Gets the sum paid by all the people
 * 
 * @return double sum paid
 */
double PersonList::sumPayed()
{
    double sum = 0.0;
    for (int i = 0; i < person_count; i++) {
        sum += persons[i].getPayedOthers();
    }
    return sum;
}

/**
 * @brief Checks if a person of given name exists in PersonList
 * 
 * @param name the name to check for
 * @return true if person exists
 * @return false if person does not exist
 */
bool PersonList::personExists(const string &name)
{
    for (int i = 0; i < person_count; i++) {
        if (persons[i].getName().compare(name) == 0) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Ensures deep copy of PersonList
 * 
 * @param other the other PersonList to copy
 */
PersonList & PersonList::operator = (const PersonList &other)
{
    if (this != &other) {
        delete[] persons; // delete old array, no mem leak
        this->person_count = other.person_count;
        for (int i = 0; i < person_count; i++) {
            this->persons[i] = other.persons[i]; // deep copy array
        }
    }
    return *this;
}