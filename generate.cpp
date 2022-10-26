#include "headers.h"
#include "SHA256.h"


void generateUsers(vector<user> &users)
{
	user user("","",0);
	for (int i = 1; i <= 1000; i++)
	{
		user.setName("user" + to_string(i));
		user.setPublicKey(sha256(user.getName()));
		user.setBalance(rand() % 999900 + 100);
		users.push_back(user);
	}

	ofstream uout("users.txt");

	for (int i = 0; i < users.size(); i++) {
		uout << "User" + to_string(i+1) << ":" << endl;
		uout << "Name: " << users.at(i).getName() << endl;
		uout << "Public key: " << users.at(i).getPublicKey() << endl;
		uout << "Balance: " << users.at(i).getBalance() << endl;
		uout << endl;
	}
	uout.close();
}

void generateTransactions(vector<user> users, vector <transaction> &transactions)
{
	transaction transaction("","","",0);
	for (int i = 0; i < 10000; i++)
	{
		transaction.setSender(users.at(rand() % 1000).getPublicKey());
		transaction.setReceiver(users.at(rand() % 1000).getPublicKey());
		transaction.setSum(rand() % 10000 + 1);
		transaction.setTransactionID(sha256(transaction.getSender() + transaction.getReceiver() + to_string(transaction.getSum())));
		transactions.push_back(transaction);
	}

	ofstream tout("transactions.txt");

	for (int i = 0; i < transactions.size(); i++) {
		tout << "Transaction" + to_string(i+1) << ":" << endl;
		tout << "Transaction ID :" << transactions.at(i).getTransactionID() << endl;
		tout << "Sender: " << transactions.at(i).getSender() << endl;
		tout << "Receiver: " << transactions.at(i).getReceiver() << endl;
		tout << "Sum: " << transactions.at(i).getSum() << endl;
		tout << endl;
	}
	tout.close();
}