#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>

#include "Transaction.h"
#include "Person.h"
#include "PersonList.h"

using namespace std;

int main() {
    // Transaction t = Transaction();
    // string file_name = "txt/resa.txt";
    // ifstream fin(file_name.c_str());
    // t.read(fin);
    // cout << t.getName() << endl;
    // t.writeTitle(cout);
    // t.write(cout);

    Person p1 = Person("Kalle", 100.0, 0.0);
    Person p2 = Person("Pelle", 0.0, 100.0);
    Person p3 = Person("Lisa", 0.0, 0.0);

    PersonList pl = PersonList();
    pl.addPerson(p1);
    pl.addPerson(p2);
    pl.addPerson(p3);
    pl.writeAndFix(cout);
    return 0;
}