#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>

#include "Transaction.h"
#include "Person.h"
#include "PersonList.h"
#include "TransactionList.h"

using namespace std;

int main()
{
  cout << "Startar med att läsa från en fil." << endl;

  TransactionList transaktioner;
  std::ifstream     is("resa.txt");
  transaktioner.read(is);

  int operation = 1;
  while (operation != 0)
    {
      cout << endl;
      cout << "Välj i menyn nedan:" << endl;
      cout << "0. Avsluta. Alla transaktioner sparas på fil." << endl;
      cout << "1. Skriv ut information om alla transaktioner." << endl;
      cout << "2. Läs in en transaktion från tangentbordet." << endl;
      cout << "3. Beräkna totala kostnaden." << endl;
      cout << "4. Hur mycket ärr en viss person skyldig?" << endl;
      cout << "5. Hur mycket ligger en viss person ute med?" << endl;
      cout << "6. Lista alla personer mm och FIXA" << endl;

      cin >> operation;
      cout << endl;

      switch (operation)
        {
          case 1:
            {
              transaktioner.write(cout);
              break;
            }
          case 2:
            {
              Transaction transaktion;
              cout << "Ange transaktion i följande format" << endl;
              transaktion.writeTitle(cout);
              transaktion.read(cin);
              transaktioner.addTransaction(transaktion);
              break;
            }
          case 3:
            {
              cout << "Den totala kostnanden för resan var "
                   << transaktioner.totalCost() << endl;
              break;
            }
          case 4:
            {
              cout << "Ange personen: ";
              string namn;
              cin >> namn;
              double ar_skyldig = transaktioner.personOwed(namn);
              if (ar_skyldig == 0.)
                cout << "Kan inte hitta personen " << namn << endl;
              else
                cout << namn << " är skyldig " << ar_skyldig << endl;
              break;
            }
          case 5:
            {
              cout << "Ange personen: ";
              string namn;
              cin >> namn;
              double ligger_ute_med = transaktioner.personPayed(namn);
              if (ligger_ute_med == 0.)
                cout << "Kan inte hitta personen " << namn << endl;
              else
                cout << namn << " ligger ute med " << ligger_ute_med << endl;
              break;
            }
          case 6:
            {
              cout << "Nu skapar vi en personarray och reder ut det hela!" << endl;
              PersonList lista = transaktioner.fixPersons();
              lista.writeAndFix(cout);
              break;
            }
        }
    }

    std::ofstream os("transaktioner.txt");
    transaktioner.write(os);

    return 0;
}