#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
  string namn;
  string nummer;
  string extraheraSiffror(const string &nummer);

public:
  Person();
  Person(string ny_namn, string ny_nummer);
  string geNamn();
  string geNummer();
  void skrivUt(ostream &out);
  bool sok(const string& key);
};

Person::Person() : namn(""), nummer("") {}

Person::Person(string ny_namn, string ny_nummer)
  : namn(ny_namn), nummer(ny_nummer) {}

string Person::geNamn()
{
  return namn;
}

string Person::geNummer()
{
  return nummer;
}

void Person::skrivUt(ostream &out)
{
  out << left << setw(40) << namn << " " << nummer << endl;
}

string Person::extraheraSiffror(const string &nummer)
{
  string bara_siffror;
  for (unsigned int i = 0; i<nummer.size(); ++i)
    if (isdigit(nummer[i]))
      bara_siffror.push_back(nummer[i]);
  return bara_siffror;
}

bool Person::sok(const string& key)
{
    string extract_key = extraheraSiffror(key);
    string bara_siffror = extraheraSiffror(nummer);
    // find key in part of namn or bara_siffror
    if (namn.find(extract_key) != string::npos || bara_siffror.find(extract_key) != string::npos)
        return true;
    else
        return false;
}

class TelefonLista {
private:
    int personCounter;
    Person *personer;
public:
    TelefonLista();
    ~TelefonLista();
    void laggTill(const Person &person);
    void hittaOchSkrivUt(const string &key);
    TelefonLista &operator=(const TelefonLista &lista);
};

TelefonLista::TelefonLista() : personCounter(0), personer(NULL) {}

TelefonLista::~TelefonLista()
{
    delete[] personer;
}

void TelefonLista::laggTill(const Person &person)
{
    Person *nyPerson = new Person[personCounter + 1];
    for (int i = 0; i < personCounter; ++i)
        nyPerson[i] = personer[i];
    nyPerson[personCounter] = person;
    delete[] personer;
    personer = nyPerson;
    ++personCounter;
}

void TelefonLista::hittaOchSkrivUt(const string &key)
{
    int found = 0;
    for (int i = 0; i < personCounter; ++i)
        if (personer[i].sok(key)) {
            personer[i].skrivUt(cout);
            ++found;
        }
    if (found == 0) cout << "Kunde inte hitta " << key << " i telefonlistan!" << endl;
}

TelefonLista & TelefonLista::operator = (const TelefonLista &other) {
    if (this != &other) {
        delete[] personer;
        this->personCounter = other.personCounter;
        for (int i = 0; i < personCounter; i++) {
            this->personer[i] = other.personer[i];
        }
    }
    return *this;
}


int main() {
    TelefonLista lista;
    lista.laggTill(Person("Andersson, Adam", "070 1234567"));
    lista.laggTill(Person("Andersson, Magdalena", "076-234 5678"));
    lista.laggTill(Person("Anka, Kalle", "+46-18-171 932"));
    lista.laggTill(Person("Duck, Donald", "+1-732 1938 3234"));
    lista.laggTill(Person("Johansson, Johan", "+46-72-325 42 42"));
    lista.laggTill(Person("Jonsson, Ibrahim", "+46-72-843 41 52"));
    lista.laggTill(Person("Ibrahimovic, Anders", "+39-471-268 52 35"));
    lista.laggTill(Person("Ibrahimovic, Anna", "0732444985"));
    lista.laggTill(Person("Reinfeldt, Fredrik", "0701-419 273"));
    lista.laggTill(Person("von Anka, Joakim", "+45-533 30 43 940"));

    while(true)
        {
        cout << "Ange person eller nummer som ska hittas (sluta med 0): ";
        string input;
        getline(cin, input);
        if (input == "0")
            break;
        lista.hittaOchSkrivUt(input);
        }

    return 0;
}
