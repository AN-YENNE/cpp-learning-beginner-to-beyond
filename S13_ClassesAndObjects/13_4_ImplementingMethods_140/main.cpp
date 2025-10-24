// Section 13 Implementing Member Methods
//
// This example demonstrates how to declare and implement class methods
// (also called "member functions") in two ways:
// 1. Inline - defined directly inside the class definition.
// 2. Outside the class - using the scope resolution operator (::).
//
// Concepts covered:
// - Defining class methods inside and outside the class.
// - Using 'private' attributes with 'public' methods to control access.
// - Performing simple operations like deposit and withdraw safely.

#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    // Private attributes: cannot be accessed directly outside the class.
    // They represent the internal state of the Account object.
    string name;
    double balance;

public:
    // Inline methods:
    // Defined inside the class declaration.
    // Typically used for very short or trivial methods.
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }

    // Method declarations (defined later outside the class)
    void set_name(string n);
    string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

// Implementation of methods outside the class
// Use the scope resolution operator (::) to associate the method
// with its class name.

// Sets the account holder's name
void Account::set_name(string n) {
    name = n;
}

// Returns the account holder's name
string Account::get_name() {
    return name;
}

// Deposit method: adds money to the account
bool Account::deposit(double amount) {
    // You could add input validation here (e.g., disallow negative deposits)
    balance += amount;
    cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    return true;
}

// Withdraw method: deducts money if sufficient balance exists
bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
        return true;
    } else {
        cout << "Insufficient funds for withdrawal of " << amount << endl;
        return false;
    }
}

// Main function demonstrating object usage
int main() {
    Account frank_account;

    // Set account name and initial balance using public methods
    frank_account.set_name("Sample Account");
    frank_account.set_balance(1000.0);

    // Deposit money into the account
    if (frank_account.deposit(200.0))
        cout << "Deposit successful" << endl;
    else
        cout << "Deposit failed" << endl;

    // Withdraw money from the account
    if (frank_account.withdraw(500.0))
        cout << "Withdrawal successful" << endl;
    else
        cout << "Withdrawal failed" << endl;

    // Attempt to withdraw more than the available balance
    if (frank_account.withdraw(1500.0))
        cout << "Withdrawal successful" << endl;
    else
        cout << "Not enough balance to withdraw that amount" << endl;

    return 0;
}

/*
Summary Notes:
1. Declaring vs Defining Methods:
   - Declaration tells the compiler that the method exists.
   - Definition provides the actual implementation (code body).
   - Outside the class, we use ClassName::MethodName().

2. Inline vs Out-of-class:
   - Inline methods (inside class) are short and may improve performance slightly.
   - Larger methods are better implemented outside the class for readability.

3. Access Control:
   - 'private' attributes (name, balance) can’t be accessed directly from main().
   - Use public setters and getters to safely read and modify them.

4. The deposit() and withdraw() methods:
   - deposit(): adds the given amount to balance.
   - withdraw(): subtracts the amount only if enough funds exist.
   - Both return true/false to indicate success or failure.

5. Using Methods:
   - Access class members using the dot operator (e.g., object.method()).

6. Best Practices:
   - Always initialize attributes (use constructors for real-world code).
   - Add validation to prevent invalid deposits or withdrawals.
   - Use const with getter methods (e.g., double get_balance() const) if they don't modify the object.
   - Consider returning error messages or using exceptions in advanced cases.

7. Scope Resolution Operator (::):
   - Used to define class methods outside the class.
   - Example: void Account::set_name(string n) { name = n; }

By mastering these fundamentals, you can begin writing well-structured C++ classes that encapsulate data and provide clear interfaces for interaction.
*/
