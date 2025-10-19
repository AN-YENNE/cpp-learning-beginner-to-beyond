// Section 15
// Deriving our First Class

#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main() { 
    
    // === Account ========================================
    cout << "\n=== Account ==================================" << endl;

    Account base_account {};                 // Use meaningful variable names
    base_account.deposit(2000.0);            // deposit to base account
    base_account.withdraw(500.0);            // withdraw from base account

    cout << endl;

    Account *account_ptr {nullptr};          // raw pointer to Account
    account_ptr = new Account();             // dynamically allocate an Account object
    account_ptr->deposit(1000.0);            // deposit using pointer
    account_ptr->withdraw(500.0);            // withdraw using pointer
    delete account_ptr;                      // Always delete what you new (avoid memory leaks)

    // === Savings Account ===============================
    cout << "\n=== Savings Account ==========================" << endl;

    Savings_Account savings_account {};      // derived class object
    savings_account.deposit(2000.0);         // deposit to savings account
    savings_account.withdraw(500.0);         // withdraw from savings account

    cout << endl;

    Savings_Account *savings_ptr {nullptr};  // raw pointer to Savings_Account
    savings_ptr = new Savings_Account();     // dynamically allocate
    savings_ptr->deposit(1000.0);            // deposit using pointer
    savings_ptr->withdraw(500.0);            // withdraw using pointer
    delete savings_ptr;                      // Delete dynamically allocated object

    cout << "\n==============================================" << endl;
    
    return 0;
}
