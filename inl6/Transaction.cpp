#include "Transaction.h"

using namespace std;

Transaction::Transaction() 
: date(""), type(""), name(""), 
amount(0.0), number_of_friends(0), friends[MAX_PERSONS]({""})
{}