#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H
using namespace std;

#include "Account.h"
#include <vector>

class BankingSystem {
private:
    vector<Account*> accounts;
    int nextAccountNumber;

public:
    BankingSystem();
    void createAccount(const string& name, double initialBalance);
    bool deleteAccount(int accountNumber);
    bool deposit(int accountNumber, double amount);
    bool withdraw(int accountNumber, double amount);
    double checkBalance(int accountNumber) const;
};

#endif // BANKINGSYSTEM_H
