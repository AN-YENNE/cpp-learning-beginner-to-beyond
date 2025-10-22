// Section 13
// Delegating Constructors - beginner friendly version
//
// In this example, we will learn about "delegating constructors" in C++.
//
// A delegating constructor allows one constructor to call another constructor
// in the same class. This helps avoid repeating initialization code.
// It improves code readability and maintainability.
//
// Syntax tip:
// ConstructorName() : ConstructorName(arguments) { ... }
// This means: instead of initializing everything again, this constructor
// calls another one (delegates) to do the initialization work.

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    // Private data members (attributes)
    std::string name;
    int health;
    int xp; // "xp" stands for experience points

public:
    // Constructor declarations
    // Each constructor will initialize the Player object in a different way
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

// Definition of constructors outside the class body using the scope resolution operator (::)

// 1. Default constructor (no arguments)
// This constructor delegates its work to the 3-argument constructor.
// The colon (:) introduces an initializer list, and here we call another constructor from it.
Player::Player() 
    : Player{"None", 0, 0}   // Delegates to the 3-argument constructor
{
    cout << "No-args constructor called (delegating to 3-arg constructor)" << endl;
}

// 2. One-argument constructor
// This constructor also delegates to the 3-argument constructor,
// passing the given name and default values for health and xp.
Player::Player(std::string name_val) 
    : Player{name_val, 0, 0} // Delegates to the 3-argument constructor
{
    cout << "One-arg constructor called (delegating to 3-arg constructor)" << endl;
}

// 3. Three-argument constructor
// This is the "primary" constructor that actually initializes the data members.
// The other constructors call this one to avoid repeating code.
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val}
{
    cout << "Three-args constructor called (primary initializer)" << endl;
}

// Main function - where the program starts
int main() {
    // Example 1: Creating a Player with the default constructor
    // This calls Player() which delegates to Player("None", 0, 0)
    Player empty;

    // Example 2: Creating a Player with one argument (name)
    // This calls Player("Frank") which delegates to Player("Frank", 0, 0)
    Player player_one{"PlayerOne"};

    // Example 3: Creating a Player with three arguments
    // This directly calls the 3-argument constructor
    Player player_boss{"PlayerBoss", 100, 55};

    // When main ends, destructors will be called automatically.
    // Since we did not define one, the compiler-generated destructor runs silently.

    return 0;
}

/*
Summary Notes:
1. Delegating constructors reduce duplicate code by letting one constructor call another.
2. The syntax for delegating is:
       ConstructorName() : ConstructorName(arguments) { ... }
3. The constructor that does the actual initialization is sometimes called the "primary" constructor.
4. Constructors that delegate are often used to supply default values or simpler ways to construct the object.
5. Each time a constructor runs, you can track which one is called by printing messages as shown.
6. The order of execution:
   - Delegating constructor first calls the target constructor to initialize data.
   - Then it executes its own body after the delegated one finishes.
7. This is especially helpful when you have multiple constructors sharing similar initialization logic.
*/
