#include "headers.h"
#include "SHA256.h"

void generateUsers(vector<user> users)
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
		uout << users.at(i).balance << setprecision(7) << endl;
	}
	uout.close();
}

void generateTransactions(vector<user> users, vector <transaction> transactions)
{

}