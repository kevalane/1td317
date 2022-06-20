#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>

#include "Transaction.h"

using namespace std;

int main() {
    Transaction t = Transaction();
    string file_name = "txt/resa.txt";
    ifstream fin(file_name.c_str());
    t.read(fin);
    cout << t.getName() << endl;
    return 0;
}