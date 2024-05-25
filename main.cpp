#include <iostream>
#include "BankingSystem.h"
using namespace std;

void displayMenu() {
    cout << "                      \n";
    cout << "1- Create account\n";
    cout << "2- Delete account\n";
    cout << "3- Deposit\n";
    cout << "4- Withdraw\n";
    cout << "5- Check account balance\n";
    cout << "0- Exit\n";
    cout << "***********************\n";
    cout << "Choose an option: ";
    cout << "\n                        \n";
}

int main() {

    BankingSystem bankingSystem;
    int choice = 0;

    while(choice == 0) {
        displayMenu();
        cin >> choice;
        bool check = false;
        switch (choice) {
            case 1: {
                string name;
                double initialBalance;
                cout << "Enter account holder name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                bankingSystem.createAccount(name, initialBalance);
                cout << "Account created successfully.\n";
                break;
            }
            case 2: {
                int accountNumber;
                cout << "Enter account number to delete: ";
                cin >> accountNumber;
                if (bankingSystem.deleteAccount(accountNumber)) {
                    cout << "Account deleted successfully.\n";
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if (bankingSystem.deposit(accountNumber, amount)) {
                    cout << "Amount deposited successfully.\n";
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (bankingSystem.withdraw(accountNumber, amount)) {
                    cout << "Amount withdrawn successfully.\n";
                } else {
                    cout << "Account not found or insufficient funds.\n";
                }
                break;
            }
            case 5: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                double balance = bankingSystem.checkBalance(accountNumber);
                if (balance != -1) {
                    cout << "Account balance: " << balance << "\n";
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 0:{
                check = true;
                cout << "Exiting the system. Goodbye!\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        
        if(check == true)break;
        choice = 0;
    } 

    return 0;
}
