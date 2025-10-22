// Section 13
// Default Constructors - beginner friendly version
//
// In this example, we will understand how constructors work,
// especially the default constructor, and how it initializes object data.
//
// Notes:
// - A constructor is a special method that is automatically called
//   when an object is created.
// - The default constructor is the one that takes no parameters.
// - Constructors are useful for initializing member variables when an object is created.
// - This program defines a Player class and creates a few Player objects
//   using both default and parameterized constructors.

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    // Data members (attributes) of the Player class
    // These are private to enforce encapsulation.
    std::string name;
    int health;
    int xp; // xp means "experience points"

public:
    // Setter method to change the player's name after object creation
    void set_name(std::string name_val) { 
        name = name_val; 
    }

    // Getter method to access the player's name
    std::string get_name() {
        return name;
    }

    // Default constructor (no arguments)
    // This is called when you create a Player object without any parameters.
    // It initializes the object with default values.
    Player() {
        name = "None";   // Default name
        health = 100;    // Default health
        xp = 3;          // Default experience points
        cout << "Default constructor called: name=" << name 
             << ", health=" << health 
             << ", xp=" << xp << endl;
    }

    // Parameterized constructor
    // This is called when you create an object with specific values.
    // It initializes the data members with the given arguments.
    Player(std::string name_val, int health_val, int xp_val) {
        name = name_val;
        health = health_val;
        xp = xp_val;
        cout << "Parameterized constructor called: name=" << name 
             << ", health=" << health 
             << ", xp=" << xp << endl;
    }
};

// Main function - program execution starts here
int main() {
    // Example 1: Using the default constructor
    // Creates a Player object using default values from the constructor
    Player hero;  // Default constructor runs here
    // The hero object now has: name = "None", health = 100, xp = 3

    // Example 2: Using the parameterized constructor
    // Creates a Player object and initializes it with custom values
    Player player_one {"PlayerOne", 100, 13};  // Parameterized constructor runs here

    // The set_name function can modify the object's name after creation
    player_one.set_name("PlayerOne");

    // Display the player's name using get_name()
    cout << "Player name is: " << player_one.get_name() << endl;

    // When main() ends, destructors for all stack objects are automatically called
    // (We did not define one here, so the compiler provides a default destructor)

    return 0;
}

/*
Summary Notes:
1. Constructors are automatically called when objects are created.
2. Default constructors set initial values when no arguments are given.
3. Parameterized constructors allow custom initialization.
4. If you do not define any constructor, C++ creates a default one automatically.
5. Destructors clean up when objects go out of scope (not shown here).
6. Using setter and getter methods allows safe access to private data.
7. The order of execution:
   - When you create an object, a constructor runs.
   - When the object goes out of scope, a destructor runs.
*/
