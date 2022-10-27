#include "headers.h"
#include "SHA256.h"

int main()
{
    srand(time(0)+1);
    
    vector<user> users;
    generateUsers(users);
    vector<transaction> transactions;
    generateTransactions(users, transactions);
    vector<blockChain> blockchain;
    string command;

    while (true)
    {
        cout << "Type wanted command: ";
        cin >> command;

        if (command == "genUsers")
        {
            generateUsers(users);
        }

        else if (command == "printUsers")
        {
            for (int i = 0; i < users.size(); i++) {
                cout << "User" + to_string(i + 1) << ":" << endl;
                cout << "Name: " << users.at(i).getName() << endl;
                cout << "Public key: " << users.at(i).getPublicKey() << endl;
                cout << "Balance: " << users.at(i).getBalance() << endl;
                cout << endl;
            }
        }

        else if (command == "printUser")
        {
            int i;
            cin >> i;
            i--;
            cout << "User" + to_string(i + 1) << ":" << endl;
            cout << "Name: " << users.at(i).getName() << endl;
            cout << "Public key: " << users.at(i).getPublicKey() << endl;
            cout << "Balance: " << users.at(i).getBalance() << endl;
            cout << endl;
        }

        else if (command == "genTransactions")
        {
            generateTransactions(users, transactions);
        }

        else if (command == "printTransactions")
        {
            for (int i = 0; i < transactions.size(); i++) {
                cout << "Transaction" + to_string(i + 1) << ":" << endl;
                cout << "Transaction ID :" << transactions.at(i).getTransactionID() << endl;
                cout << "Sender: " << transactions.at(i).getSender() << endl;
                cout << "Receiver: " << transactions.at(i).getReceiver() << endl;
                cout << "Sum: " << transactions.at(i).getSum() << endl;
                cout << endl;
            }
        }

        else if (command == "printTransaction")
        {
            int i;
            cin >> i;
            i--;
            cout << "Transaction" + to_string(i + 1) << ":" << endl;
            cout << "Transaction ID :" << transactions.at(i).getTransactionID() << endl;
            cout << "Sender: " << transactions.at(i).getSender() << endl;
            cout << "Receiver: " << transactions.at(i).getReceiver() << endl;
            cout << "Sum: " << transactions.at(i).getSum() << endl;
            cout << endl;
        }

        else if (command == "startMining")
        {
            mineBlocks(users, transactions, blockchain);
        }

        else if (command == "printBlock")
        {
            int i;
            cin >> i;
            i--;
            cout << "Block number " << i + 1 << ":" << endl;
            cout << "Block hash: " << blockchain.at(i).blocks.hash << endl;
            cout << "Previous block hash: " << blockchain.at(i).prevHash << endl;
            cout << "Timestamp: " << blockchain.at(i).timestamp << endl;
            cout << "Version: " << blockchain.at(i).version << endl;
            cout << "Merkle Root hash: " << blockchain.at(i).merkelRoot.substr(0, 64) << endl;
            cout << "Nonce: " << blockchain.at(i).nonce << endl;
            cout << "Difficulty: " << blockchain.at(i).diff << endl;
        }

        else if (command == "printAllBlocks")
        {
            for (int i = 0; i < blockchain.size(); i++)
            {
                cout << "Block number " << i + 1 << ":" << endl;
                cout << "Block hash: " << blockchain.at(i).blocks.hash << endl;
                cout << "Previous block hash: " << blockchain.at(i).prevHash << endl;
                cout << "Version: " << blockchain.at(i).version << endl;
                cout << "Merkle Root: " << blockchain.at(i).merkelRoot.substr(0, 64) << endl;
                cout << "Nonce: " << blockchain.at(i).nonce << endl;
                cout << "Mined on: " << blockchain.at(i).timestamp << endl;
                cout << "Difficulty: " << blockchain.at(i).diff << endl;
                cout << endl;
            }
        }

        else if (command == "quit")
        {
            break;
        }
        cout << endl;
    }
}
