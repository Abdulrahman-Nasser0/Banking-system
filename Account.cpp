#include "Account.h"
using namespace std;

//constructor
Account::Account(int accNum, const string& name, double initialBalance) : accountNumber(accNum), accountHolderName(name), balance(initialBalance) {}

int Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getAccountHolderName() const {
    return accountHolderName;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}
