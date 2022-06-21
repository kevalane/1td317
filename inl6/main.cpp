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

    Person p = Person();
    Person p2 = Person();
    PersonList pl = PersonList();
    pl.addPerson(p);
    pl.addPerson(p2);
    pl.writeAndFix(cout);
    return 0;
}