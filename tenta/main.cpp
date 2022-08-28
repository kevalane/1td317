// main.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin1, fin2;
    ofstream fout;
    int n1, n2;
    string s1, s2;

    fin1.open("temperatur1.dat");
    fin2.open("temperatur2.dat");
    fout.open("temperatur.dat");

    while(fin1 >> n1 && fin2 >> n2)
    {
    if(n1 < n2)
        fout << n1 << '\n';
    else
        fout << n2 << '\n';
    }

    // This loop will only execute if fin1 is not at eof().
    while(fin1 >> n1) fout << n1 << '\n';
    // This loop will only execute if fin2 is not at eof().
    while(fin2 >> n2) fout << n2 << '\n';

    fin1.close();
    fin2.close();
    fout.close();
}