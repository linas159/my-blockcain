#define _CRT_SECURE_NO_WARNINGS
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

string mineBlock(vector<blockChain> bc, int b)
{
	int x;
	string newhash;
	if (b == 1)
		bc.at(b).prevHash = sha256("1");
	else
		bc.at(b).prevHash = bc.at(b - 1).blocks.hash;

	bc.at(b).timestamp = time(nullptr);
	bc.at(b).version = "v" + to_string(b) + ".0";
	bc.at(b).diff = "0";

	for (int i = 0; i < 100; i++)
		bc.at(b).merkelRoot += bc.at(b).blocks.transactions.at(i).getTransactionID();

	x = bc.at(b).diff.size()-1;

	for (int i = 0; i < 69; i++) {
		bc.at(b).nonce = rand() % 1000000;
		newhash = sha256(bc.at(b).diff + bc.at(b).merkelRoot + bc.at(b).prevHash + to_string(bc.at(b).timestamp) + bc.at(b).version + to_string(bc.at(b).nonce));
		if (newhash.substr(1, x) == bc.at(b).diff)
			return newhash;
	}

	return "0";
}

blockChain gen_block(int difficulty, int number, vector<transaction>& transaction, int block_count)
{
	blockChain blockchain;

	string all_transactions;

	blockchain.version = "0.1";

	blockchain.nonce = number;
	blockchain.blocks.hash = sha256(to_string(number));

	for (int i = 0; i < 100; i++)
	{
		int transaction_id = rand()%transaction.size();

		blockchain.blocks.transactions.push_back(transaction[transaction_id]);
		//cout << transaction[transaction_id].sum <<endl;

		all_transactions += blockchain.blocks.transactions.back().getTransactionID();

		transaction.erase(transaction.begin() + transaction_id);
	}

	blockchain.merkelRoot = sha256(all_transactions);

	if (block_count != 0)
		blockchain.prevHash = blockchain.blocks.hash;

	blockchain.diff = difficulty;

	return blockchain;
}
void print_to_file(vector<blockChain> blockchain_blocks, int x)
{
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	ofstream fr;
	fr.open("result.txt", fstream::app);

	fr << "Block of the blockchain " << x + 1 << ": " << endl;
	fr << "Hash: " << blockchain_blocks.back().blocks.hash << endl;
	fr << "Timestamp: " << ctime(&end_time);
	fr << "Version: " << blockchain_blocks.back().version << endl;
	fr << "Merkel Root Hash: " << blockchain_blocks.back().merkelRoot << endl;
	fr << "Nonce: " << blockchain_blocks.back().nonce << endl;
	fr << "Difficulty: " << blockchain_blocks.back().diff << endl;
	fr << "Number of transactions: " << blockchain_blocks.back().blocks.transactions.size() << endl;
	fr << endl;

	fr.close();
}