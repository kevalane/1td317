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
    int place1 = 0;
    int place2 = 0;

    fin1.open("temperatur1.dat");
    fin2.open("temperatur2.dat");
    fout.open("temperatur.dat");

    while(fin1 >> n1 && fin2 >> n2)
    {
        if(n1 < n2)
        { 
            double temp;
            fin1 >> temp;
            fout << n1 << " " << temp << endl;
            fin2.seekg(place2);
        } else {
            double temp;
            fin2 >> temp;
            fout << n2 << " " << temp << endl;
            fin1.seekg(place1);
        }

        place1 = fin1.tellg();
        place2 = fin2.tellg();
    }

    // This loop will only execute if fin1 is not at eof().
    while(fin1 >> n1) {
        double temp;
        fin1 >> temp;
        fout << n1 << " " << temp << endl;
    }
    // This loop will only execute if fin2 is not at eof().
    while(fin2 >> n2) {
        double temp;
        fin2 >> temp;
        fout << n2 << " " << temp << endl;
    }

    fin1.close();
    fin2.close();
    fout.close();
}