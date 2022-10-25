#include "headers.h"

int main()
{
    srand(time(0)+1);

    vector<user> users;
    generateUsers(users);

    vector<transaction> transactions;
    generateTransactions(users, transactions);

}
