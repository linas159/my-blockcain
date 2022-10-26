#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <chrono>

using namespace std;

class user
{
private:
    string name;
    string public_key;
    int balance;

public:
    user(string name, string pk, int bal);

    string getName();
    string getPublicKey();
    int getBalance();

    void setName(string name);
    void setPublicKey(string key);
    void setBalance(int bal);
};


class transaction
{
private:
    string transactionID;
    string sender;
    string receiver;
    double sum;

public:
    transaction(string transID, string send, string rec, int sum);

    string getTransactionID();
    string getSender();
    string getReceiver();
    int getSum();

    void setTransactionID(string transactionID);
    void setSender(string sender);
    void setReceiver(string receiver);
    void setSum(int sum);
};

struct block
{
    string hash;
    vector<transaction> transactions;
};

struct blockChain 
{
    string prevHash;
    int timestamp;
    string version;
    string merkelRoot;
    int nonce;
    string diff;
    block blocks;
};


void generateUsers(vector<user> &users);
void generateTransactions(vector<user> users, vector <transaction> &transactions);
string mineBlock(vector<blockChain> bc, int b);
blockChain gen_block(int difficulty, int number, vector<transaction>& transaction, int block_count);
void print_to_file(vector<blockChain> blockchain_blocks, int x);