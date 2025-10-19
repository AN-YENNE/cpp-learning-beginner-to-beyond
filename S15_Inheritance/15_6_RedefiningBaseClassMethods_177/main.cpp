// Section 15
// Redefining and Using Base Class Methods

#include <iostream>
#include "Savings_Account.h"

using namespace std;

int main() {
    cout << "\n===== Account class ===================" << endl;

    Account a1{1000.0};         // create Account with initial balance
    cout << a1 << endl;

    a1.deposit(500.0);          // deposit into account
    cout << a1 << endl;

    a1.withdraw(1000);          // withdraw within balance
    cout << a1 << endl;

    a1.withdraw(5000.0);        // attempt to withdraw more than balance
    cout << a1 << endl;

    cout << "\n===== Savings Account class ===========" << endl;

    Savings_Account s1{1000, 5.0};  // create Savings_Account with balance and interest rate
    cout << s1 << endl;

    s1.deposit(1000);           // deposit with interest applied
    cout << s1 << endl;

    s1.withdraw(2000);          // withdraw within balance
    cout << s1 << endl;

    s1.withdraw(1000);          // attempt to withdraw more than balance
    cout << s1 << endl;

    return 0;
}

/*Savings_Account::deposit() overrides the base method by adding interest before depositing.

withdraw() is inherited directly from Account.

Output operators (<<) are overloaded to print object states.

Constructors initialize base and derived class members using initializer lists.*/