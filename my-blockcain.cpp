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

    int difficulty = 1;
    int x = 0;

    ofstream out;
    out.open("result.txt", fstream::trunc);

    while (transactions.size() > 0)
    {
        //cout << " here " <<endl;
            //cout << "here " <<endl;
        int counting_0 = 0;
        unsigned int number = rand();
        string number_hash = sha256(to_string(number));


        for (int j = 0; j < difficulty; j++)
        {
            if (number_hash[j] == '0')
                counting_0++;
        }


        if (counting_0 == difficulty)
        {
            blockchain.push_back(gen_block(difficulty, number, transactions, x));

            print_to_file(blockchain, x);

            x++;
        }
    }
    //blockChain temp;
    //int k = 0;
    //while (transactions.size())
    //{
    //    while ((!blockchain.size() || blockchain.at(k).blocks.transactions.size()) != 100 && transactions.size() != 0) //block'ą sudaro 100 transakcijų
    //    {
    //        
    //        int random = rand() % transactions.size(), i;

    //        for (i = 0; i < 1000; i++)
    //        {
    //            if (transactions.at(random).getSender() == users.at(i).getPublicKey())
    //            {
    //                break;
    //            }
    //        }
    //        
    //        if (users.at(i).getBalance() >= transactions.at(random).getSum()) {
    //            blockchain.at(k).blocks.transactions.push_back(transactions.at(random));
    //            transactions.erase(transactions.begin() + random - 1);
    //        }
    //        else {
    //            transactions.erase(transactions.begin() + random - 1);
    //        }
    //        cout << "atejau" << endl;
    //    }

    //    if (blockchain.at(k).blocks.transactions.size() == 100)
    //        k++;

    //    string temp = "0";
    //    int n = 1;
    //    while (temp == "0") 
    //    {
    //            temp = mineBlock(blockchain, k);
    //    }
    //    cout << "Block mined! hash: " << temp << endl;

    //    for (auto tran : blockchain.at(k).blocks.transactions) {
    //        int send = 0, get = 0;
    //        for (int i = 0; i < 1000; i++) {
    //            if (users.at(i).getPublicKey() == tran.getSender())
    //                send = i;
    //            else if (users.at(i).getPublicKey() == tran.getReceiver())
    //                get = i;
    //            if (send != 0 && get != 0)
    //                break;
    //        }

    //        users.at(send).setBalance(users.at(send).getBalance() - tran.getSum());
    //        users.at(get).setBalance(users.at(send).getBalance() + tran.getSum());
    //    }
    //}
}
