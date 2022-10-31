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

void generateMerkelRoot(blockChain &bc)
{
	for (int i = 0; i < bc.blocks.transactions.size(); i++)
	{
		bc.merkelRoot += bc.blocks.transactions.at(i).getTransactionID();
	}
	bc.merkelRoot = sha256(bc.merkelRoot);
}

string mineBlock(blockChain& bc, string prevHash, int k)
{
	if (k == 1)
		bc.prevHash = sha256("1");
	else
		bc.prevHash = prevHash;

	bc.timestamp = time(nullptr);
	bc.version = "v" + to_string(k) + ".0";
	bc.diff = "0";

	generateMerkelRoot(bc);
		
	int x = bc.diff.size();
	string newhash;
	int nonce = 0;
	while (true)
	{
		newhash = sha256(bc.diff + bc.merkelRoot + bc.prevHash + to_string(bc.timestamp) + bc.version + to_string(nonce));
		if (newhash.substr(0, x) == bc.diff) {
			bc.nonce = nonce;
			return newhash;
		}
		nonce++;
	}

	return "0";
}

void mineBlocks(vector<user>& users, vector<transaction>& transactions, vector<blockChain>& blockchain) 
{
	int k = 0;
	while (transactions.size() != 0)
	{
		blockChain tempbc;
		while (tempbc.blocks.transactions.size() != 100 && transactions.size() != 0) // block'ą sudaro 100 transakcijų
		{

			uniform_int_distribution<> distr(0, transactions.size() - 1);
			int random = rand() % transactions.size(), i;

			for (i = 0; i < 1000; i++)
			{
				if (transactions.at(random).getSender() == users.at(i).getPublicKey())
				{
					break;
				}
			}

			if (users.at(i).getBalance() >= transactions.at(random).getSum()) {
				tempbc.blocks.transactions.push_back(transactions.at(random));
				transactions.erase(transactions.begin() + random);
			}
			else {
				transactions.erase(transactions.begin() + random);
			}
		}

		k++;
		if (k == 1)
		{
			tempbc.blocks.hash = mineBlock(tempbc, "", k);
		}
		else
		{

			tempbc.blocks.hash = mineBlock(tempbc, blockchain.at(k - 2).blocks.hash, k);
		}

		blockchain.push_back(tempbc);
		cout << "Block mined! hash: " << blockchain.at(k - 1).blocks.hash << endl;

		for (auto tran : blockchain.at(k - 1).blocks.transactions) {
			int send = 0, get = 0;
			for (int i = 0; i < 1000; i++) {
				if (users.at(i).getPublicKey() == tran.getSender())
					send = i;
				else if (users.at(i).getPublicKey() == tran.getReceiver())
					get = i;
				if (send != 0 && get != 0)
					break;
			}

			users.at(send).setBalance(users.at(send).getBalance() - tran.getSum());
			users.at(get).setBalance(users.at(send).getBalance() + tran.getSum());
		}
	}
}

