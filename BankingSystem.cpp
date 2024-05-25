#include "BankingSystem.h"
#include <iostream> 
using namespace std;

//constructor
BankingSystem::BankingSystem() {
    nextAccountNumber = 1;
}


//create a new account
void BankingSystem::createAccount(const string& name, double initialBalance) {
    cout << "Creating account for " << name << " with initial balance: " << initialBalance << endl;
    Account* newAccount = new Account(nextAccountNumber, name, initialBalance);
    accounts.push_back(newAccount);
    nextAccountNumber++;
}
//delete an account
bool BankingSystem::deleteAccount(int accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            cout << "Deleting account " << accountNumber << endl;
            delete accounts[i];
            accounts.erase(accounts.begin() + i);
            return true;
        }
    }
    return false;
}

bool BankingSystem::deposit(int accountNumber, double amount) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            cout << "Depositing " << amount << " to account " << accountNumber << endl;
            accounts[i]->deposit(amount);
            return true;
        }
    }
    return false;
}

bool BankingSystem::withdraw(int accountNumber, double amount) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            cout << "Withdrawing " << amount << " from account " << accountNumber << endl;
            return accounts[i]->withdraw(amount);
        }
    }
    return false;
}

double BankingSystem::checkBalance(int accountNumber) const {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            return accounts[i]->getBalance();
        }
    }
    return -1; 
}
