#include <fstream>
#include <iostream>

using std::ios;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;

struct clientData {
    int account;
    char lastName[16];
    char firstName[16];
    float balance;
};

void append(clientData& client);
clientData findByAccount(int account);
void changeBalance(int account, float newBalance);

/*
  account
  [ id | firstName | lastName | balance ]
  [ 01 | Pesho     | lastName | 12.10   ]
  [ 13 | Mariika   | lastName | 12.10   ]
*/

int main()
{
    clientData client1 = { 41, "Ivan", "Petrov", 12.10 };
    clientData client2 = { 42, "Petar", "Ivanov", 14.10 };
    clientData client3 = { 43, "Gosho", "Petrov", 43.10 };
    append(client1);
    append(client2);
    append(client3);

    changeBalance(43, 50.00);
    cout << findByAccount(43).lastName << endl;
    cout << findByAccount(43).firstName << endl;
    cout << findByAccount(43).balance << endl;
    cout << findByAccount(43).account << endl;
    return 0;
}

void append(clientData& client)
{
    ofstream file("clients.dat", ios::binary | ios::app);
    file.write(reinterpret_cast<char*>(&client), sizeof(client));
    file.close();
}

clientData findByAccount(int account)
{
    ifstream file("clients.dat", ios::binary | ios::in | ios::out);

    clientData client;
    while (file.read(reinterpret_cast<char*>(&client), sizeof(client))) {
        if (client.account == account) {
            file.close();
            return client;
        }
    }

    file.close();
    return clientData();
}

void changeBalance(int account, float newBalance)
{
    fstream file("clients.dat", ios::binary | ios::in | ios::out);

    clientData client;
    while (file.read(reinterpret_cast<char*>(&client), sizeof(client))) {
        if (client.account == account) {
            file.seekp(-sizeof(client), ios::cur);
            client.balance = newBalance;

            file.write(reinterpret_cast<char*>(&client), sizeof(client));

            file.close();
        }
    }

    file.close();
}
