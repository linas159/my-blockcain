#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

struct user {
	string name;
	string public_key;
	int balance;
};

struct transaction {
	string transactionID;
	string sender;
	string receiver;
	double sum;
};



void generateUsers(vector<user> users);