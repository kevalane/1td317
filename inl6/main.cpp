#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>

#include "Transaction.h"
#include "Person.h"

using namespace std;

int main() {
    Transaction t = Transaction();
    string file_name = "txt/resa.txt";
    ifstream fin(file_name.c_str());
    t.read(fin);
    cout << t.getName() << endl;
    t.writeTitle(cout);
    t.write(cout);

    Person p = Person("test", 10.0, 10.0);
    p.write(cout);
    return 0;
}