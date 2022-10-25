#include "headers.h"
#include "SHA256.h"


void generateUsers(vector<user> &users)
{
	user user;
	for (int i = 1; i <= 1000; i++)
	{
		user.name = "user" + to_string(i);
		user.public_key = sha256(user.name);
		user.balance = rand() % 999900 + 100;
		users.push_back(user);
	}

	ofstream uout("users.txt");

	for (int i = 0; i < users.size(); i++) {
		uout << users.at(i).name << " ";
		uout << users.at(i).public_key << " ";
		uout << users.at(i).balance << endl;
	}
	uout.close();
}

void generateTransactions(vector<user> users, vector <transaction> &transactions)
{
	transaction transaction;
	for (int i = 0; i < 10000; i++)
	{
		transaction.sender = users.at(rand() % 1000).public_key;
		transaction.receiver = users.at(rand() % 1000).public_key;
		transaction.sum = rand() % 10000 + 1;
		transaction.transactionID = sha256(transaction.sender + transaction.receiver + to_string(transaction.sum));
		transactions.push_back(transaction);
	}

	ofstream tout("transactions.txt");

	for (int i = 0; i < transactions.size(); i++) {
		tout << transactions.at(i).transactionID << " ";
		tout << transactions.at(i).sender << " ";
		tout << transactions.at(i).receiver << " ";
		tout << transactions.at(i).sum << endl;
	}
	tout.close();
}