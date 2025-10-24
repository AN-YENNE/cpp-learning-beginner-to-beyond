// Section 13
// Const in Classes - beginner friendly version
//
// This example demonstrates how the 'const' keyword is used inside class methods
// to protect data from unintended modification.
//
// When a method is marked as const, it promises NOT to change any of the object's data members.
// This allows const objects (like 'const Player villain') to safely call that method.
//
// Syntax reminder:
//   ReturnType functionName() const { ... }
//
// The 'const' after the parameter list applies to the *object* on which the method is called,
// meaning the function cannot modify member variables or call non-const methods.

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    std::string name;
    int health;
    int xp;  // Experience points

public:
    // Const method example
    // Because this function does not modify the object,
    // we declare it as 'const' so that it can be called on const objects.
    std::string get_name() const {
        return name;  // Safe to access, no modification
    }

    // Setter method (non-const)
    // This method *modifies* the object, so it cannot be marked const.
    void set_name(std::string name_val) {
        name = name_val;
    }

    // Constructors
    Player();  // Default constructor
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

// Default constructor delegates to the 3-argument constructor
Player::Player()
    : Player{"None", 0, 0} {
    cout << "Default constructor called" << endl;
}

// One-argument constructor delegates to the 3-argument constructor
Player::Player(std::string name_val)
    : Player{name_val, 0, 0} {
    cout << "One-argument constructor called" << endl;
}

// Three-argument constructor initializes all members directly
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
    cout << "Three-argument constructor called for: " << name << endl;
}

// Function that accepts a const reference
// Since p is const, only const methods of Player can be called on it.
void display_player_name(const Player& p) {
    cout << "Player name (via const reference): " << p.get_name() << endl;
}

int main() {
    // Example 1: Create a const object
    // A const object cannot call non-const member functions.
    const Player villain{"Villain", 100, 55};

    // Example 2: Create a non-const object
    Player hero{"Hero", 100, 15};

    // This would cause a compiler error because set_name is non-const:
    // villain.set_name("Super Villain");

    // However, get_name() is const, so it works:
    cout << "Villain name: " << villain.get_name() << endl;

    // Works for non-const objects too
    cout << "Hero name: " << hero.get_name() << endl;

    // Pass both const and non-const objects to a function
    // The function takes a const reference, so it accepts both types safely.
    display_player_name(villain);
    display_player_name(hero);

    return 0;
}

/*
Summary Notes:
1. Const methods:
   - A const method cannot modify any member variables.
   - Declared with 'const' after the function parameters.
   - Can only call other const methods within its body.

2. Const objects:
   - A const object cannot have its data modified.
   - You can only call const methods on const objects.

3. Why use const:
   - Improves code safety and clarity.
   - Prevents accidental data modification.
   - Allows functions to accept const references (avoiding unnecessary copies).

4. Function parameters:
   - Passing by 'const reference' (const Player& p) avoids copying the object
     while also preventing modification inside the function.

5. Compiler enforcement:
   - If a non-const method tries to modify data on a const object, the compiler
     will generate an error.
   - Const correctness is an important best practice for clean, safe class design.

6. Typical const usage in classes:
   - Getters should almost always be const.
   - Setters and mutators should not be const because they change object state.
*/
