// Section 13 Default Constructor Parameters
//
// This example demonstrates how to use *default parameter values*
// in constructors instead of writing multiple overloaded constructors.
//
// Default parameters make it possible to call the same constructor
// with varying numbers of arguments. Missing arguments will automatically
// use their default values.
//
// Syntax example:
// Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
//
// This means:
// - If no arguments are given, all defaults are used.
// - If one argument is given, the remaining ones use their defaults.
// - If two are given, the last one uses its default, and so on.

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    // Data members
    std::string name;
    int health;
    int xp; // "xp" means experience points

public:
    // Constructor with default parameter values
    //
    // If you provide no values, defaults ("None", 0, 0) will be used.
    // This single constructor replaces the need for multiple overloaded ones.
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

    // Note: You cannot also define a separate "Player()" constructor
    // if this one already has all default parameters. It would cause a compiler error
    // because the compiler could not tell which constructor to call when no arguments are passed.
};

// Constructor definition
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
    cout << "Constructor called: "
         << "name='" << name << "', "
         << "health=" << health << ", "
         << "xp=" << xp << endl;
}

// Main function to demonstrate how default constructor parameters work
int main() {

    // Example 1: No arguments
    // All parameters take their default values.
    Player empty; // Equivalent to Player("None", 0, 0)

    // Example 2: One argument
    // health and xp use default values (0, 0)
    Player player_one{"PlayerOne"}; // Equivalent to Player("PlayerOne", 0, 0)

    // Example 3: Two arguments
    // xp uses default value (0)
    Player player_two{"PlayerTwo", 100}; // Equivalent to Player("PlayerTwo", 100, 0)

    // Example 4: Three arguments
    // All parameters are provided; no defaults are used.
    Player player_three{"PlayerThree", 100, 55};

    // When main ends, destructors run automatically (compiler-provided).
    return 0;
}

/*
Summary Notes:
1. Default parameter values allow you to write a single constructor
   instead of multiple overloaded ones.
   Example: Player("Hero"), Player("Hero", 100), Player("Hero", 100, 50)
   can all work with one definition.

2. You cannot define both:
       Player();
       Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
   because they would both match a call with no arguments, causing ambiguity.

3. When an argument is omitted, the compiler automatically substitutes the default value.

4. The order of default parameters matters.
   Defaults can only be omitted from right to left.
   Example: If xp_val has a default, health_val must also have one.

5. Advantages:
   - Reduces code duplication.
   - Simplifies constructor lists.
   - Makes code easier to maintain.

6. This pattern is common in modern C++ when simple defaults are sufficient
   instead of creating multiple overloaded constructors.
*/
