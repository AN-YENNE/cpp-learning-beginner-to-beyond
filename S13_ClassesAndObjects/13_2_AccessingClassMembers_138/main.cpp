// Section 13: Accessing Class Members
//
// This example demonstrates how to access and modify class members (attributes and methods)
// in different ways, including both *direct object access* and *pointer-based access*.
//
// It also introduces two example classes: Player and Account, each with simple attributes
// and member functions.
//
// Key concepts:
// 1. Accessing members using the dot operator (object.member).
// 2. Accessing members using the arrow operator (pointer->member).
// 3. Using class objects vs. dynamically allocated objects.

#include <iostream>
#include <string>

using namespace std;

// Define the Player class
class Player {
public:
    // Public attributes (not recommended in production, but fine for this example)
    string name;
    int health;
    int xp;

    // Public methods
    void talk(string text_to_say) {
        cout << name << " says: " << text_to_say << endl;
    }

    bool is_dead(); // Just a placeholder; not implemented here
};

// Define the Account class
class Account {
public:
    // Public attributes
    string name;
    double balance;

    // Public methods
    bool deposit(double bal) {
        balance += bal;
        cout << "Deposit successful. New balance: " << balance << endl;
        return true;
    }

    bool withdraw(double bal) {
        balance -= bal;
        cout << "Withdraw successful. New balance: " << balance << endl;
        return true;
    }
};

// Main function to demonstrate accessing members
int main() {
    // Example 1: Using an Account object directly
    Account frank_account;
    frank_account.name = "Frank's Account";
    frank_account.balance = 5000.0;

    // Accessing member functions using the dot operator
    frank_account.deposit(1000.0);  // Adds 1000 to balance
    frank_account.withdraw(500.0);  // Subtracts 500 from balance

    // Example 2: Using a Player object directly
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;

    // Calling a method using the dot operator
    frank.talk("Hi there!");

    // Example 3: Using a Player object through a pointer
    Player* enemy = new Player;  // Dynamically allocate Player object

    // Accessing attributes using pointer dereference
    (*enemy).name = "Enemy";   // Same as enemy->name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;            // Using arrow operator (preferred)

    // Calling a method using pointer syntax
    enemy->talk("I will destroy you!");

    // Clean up dynamically allocated memory
    delete enemy;

    return 0;
}

/*
Summary Notes:
1. Access operators:
   - Dot operator (.) is used when you have an object.
       Example: frank.name, frank.talk("Hi!");
   - Arrow operator (->) is used when you have a pointer to an object.
       Example: enemy->name, enemy->talk("Attack!");

2. Object vs Pointer:
   - Object created normally (on the stack): automatically destroyed at the end of its scope.
   - Object created with new (on the heap): must be manually deleted with 'delete' to free memory.

3. Class attributes in this example are public for demonstration.
   In practice, make them private and use public setter/getter methods.

4. Returning values from methods:
   - In this example, deposit() and withdraw() always return true.
     In a real program, you would check conditions (e.g., insufficient funds).

5. Best practices:
   - Use meaningful attribute names (balance, health, xp).
   - Avoid raw pointers; use smart pointers (e.g., std::unique_ptr<Player>).
   - Encapsulate attributes (make them private) to protect internal data.
*/
