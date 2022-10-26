#include "headers.h"


//User class
user::user(string name, string pk, int bal)
{
    this->name = name;
    this->public_key = pk;
    this->balance = bal;
};

string user::getName()
{
    return this->name;
}

void user::setName(string name)
{
    this->name = name;
}

string user::getPublicKey()
{
    return this->public_key;
}
void user::setPublicKey(string publicKey)
{
    this->public_key = publicKey;
}

int user::getBalance()
{
    return this->balance;
}

void user::setBalance(int balance)
{
    this->balance = balance;
}


//Transaction class
transaction::transaction(string transID, string send, string rec, int sum)
{
    this->transactionID = transID;
    this->sender = send;
    this->receiver = rec;
    this->sum = sum;
};

string transaction::getTransactionID()
{
    return this->transactionID;
}

void transaction::setTransactionID(string transactionID)
{
    this->transactionID = transactionID;
}

string transaction::getSender()
{
    return this->sender;
}
void transaction::setSender(string sender)
{
    this->sender = sender;
}

string transaction::getReceiver()
{
    return this->receiver;
}
void transaction::setReceiver(string receiver)
{
    this->receiver = receiver;
}

int transaction::getSum()
{
    return this->sum;
}

void transaction::setSum(int sum)
{
    this->sum = sum;
}

