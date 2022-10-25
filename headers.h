#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <time.h>

using namespace std;

struct user {
	string name;
	string public_key;
	double balance;
};

struct transaction {
	string transactionID;
	string sender;
	string receiver;
	double sum;
};



void generateUsers(vector<user> &users);
void generateTransactions(vector<user> users, vector <transaction> &transactions);