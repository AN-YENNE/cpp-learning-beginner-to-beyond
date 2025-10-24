// Section 13 Declare Classes and Objects
//
// This example demonstrates how to declare and create class objects in C++,
// both statically (on the stack) and dynamically (on the heap).
//
// It also shows how to work with arrays and vectors of class objects.
//
// Key concepts covered:
// 1. Declaring classes with attributes and methods.
// 2. Creating objects (instances) of a class.
// 3. Using arrays and vectors of objects.
// 4. Creating objects dynamically using pointers and 'new' / 'delete'.
// 5. Understanding where and when objects are destroyed.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class definitions

class Player {
    // Attributes (data members)
    string name {"Player"};  // Default initialized name
    int health {100};        // Default health points
    int xp {3};              // Default experience points

    // Methods (member functions)
    void talk(string message);  // Function declaration
    bool is_dead();             // Function declaration
};

class Account {
    // Attributes
    string name {"Account"};    // Default name
    double balance {0.0};       // Default balance

    // Methods
    bool deposit(double amount);  // Function declaration
    bool withdraw(double amount); // Function declaration
};

// Main function to demonstrate declaring objects
int main() {
    // 1. Creating individual objects (stack allocation)
    // Each object is created automatically and destroyed when it goes out of scope.
    Account frank_account;  // Create an Account object named frank_account
    Account jim_account;    // Another Account object named jim_account

    // Similarly, create Player objects
    Player frank;  // Player object named frank
    Player hero;   // Player object named hero

    // 2. Creating an array of objects
    // Arrays of objects can be declared and initialized like arrays of basic types.
    Player players[] {frank, hero};  // Array containing two Player objects

    // 3. Using a vector to store objects dynamically
    // std::vector can grow in size and automatically manages memory.
    vector<Player> player_vec {frank};  // Initialize vector with one Player
    player_vec.push_back(hero);         // Add another Player to the vector

    // 4. Creating objects dynamically using pointers
    // Dynamically allocated objects live on the heap until deleted.
    Player* enemy {nullptr};   // Declare a pointer to a Player object, currently null
    enemy = new Player;        // Allocate a new Player object on the heap

    // ... use the 'enemy' object here if needed ...
    // Example: enemy->talk("Attack!");

    // Always delete dynamically allocated objects to free memory
    delete enemy;              // Destroys the object and frees its memory
    enemy = nullptr;           // Set pointer to null to avoid dangling pointer

    return 0;
}

/*
Summary Notes:
1. Object creation:
   - Stack objects (e.g., Player frank;) are automatically destroyed when they go out of scope.
   - Heap objects (e.g., new Player) persist until manually deleted.

2. Arrays of objects:
   - Fixed size, all objects are created and destroyed automatically.
   - Example: Player team[5];  // creates 5 Player objects.

3. Vectors of objects:
   - Dynamic containers that grow and shrink automatically.
   - Use push_back() to add new elements.
   - No need to manually delete objects; memory is managed automatically.

4. Pointers to objects:
   - Used for dynamic memory allocation or to reference existing objects.
   - Use the arrow operator (->) to access members through a pointer.
   - Always remember to 'delete' what you 'new' to prevent memory leaks.

5. Object lifetime:
   - Stack objects: automatically cleaned up when they go out of scope.
   - Heap objects: must be deleted manually or managed using smart pointers
     (like std::unique_ptr or std::shared_ptr).

6. Best practices:
   - Use stack or container-managed objects whenever possible.
   - Only use dynamic allocation when necessary.
   - Prefer smart pointers over raw pointers for safety.
*/
