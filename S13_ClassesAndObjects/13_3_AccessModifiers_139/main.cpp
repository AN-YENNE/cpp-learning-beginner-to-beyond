// Section 13: Access Modifiers
//
// This example demonstrates the concept of access control in C++ classes
// using *access modifiers* (private, public, and protected).
//
// Access modifiers define which parts of the program can access a class's
// data members (attributes) and functions (methods).
//
// - private:    Accessible only inside the class itself.
// - public:     Accessible from anywhere (outside and inside the class).
// - protected:  Accessible inside the class and its derived (child) classes.
//
// The default access level in a class (if not specified) is private.

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    // Private attributes (data members)
    // These can only be accessed by methods of this class.
    string name{"Player"};  // Initialized with a default value
    int health;             // Health points (uninitialized here)
    int xp;                 // Experience points (uninitialized here)

public:
    // Public methods (member functions)
    // These can be accessed from outside the class.
    void talk(string text_to_say) {
        cout << name << " says: " << text_to_say << endl;
    }

    // Example of a method declaration (no definition here).
    // It can be defined later outside the class using the scope resolution operator (::)
    bool is_dead();
};

// Main function demonstrates access levels
int main() {
    Player frank; // Create a Player object named frank

    // The following lines are commented out because they will cause compilation errors:
    // frank.name = "Frank";   // ERROR: name is private and cannot be accessed directly
    // cout << frank.health;   // ERROR: health is private and cannot be accessed directly

    // We can only access *public* methods from outside the class.
    frank.talk("Hello there"); // Valid: talk() is public

    return 0;
}

/*
Summary Notes:
1. Access Modifiers Overview:
   - public: accessible from anywhere.
   - private: accessible only within the class.
   - protected: accessible in the class and its derived classes (not shown here).

2. Why use private?
   - To enforce encapsulation (hiding internal data).
   - Prevents external code from modifying object data directly.
   - Protects against accidental misuse and makes maintenance easier.

3. How to access private data safely:
   - Use public "getter" and "setter" functions to control read/write access.
   Example:
       void set_name(string new_name) { name = new_name; }
       string get_name() const { return name; }

4. Encapsulation principle:
   - Keep data private.
   - Provide public methods for controlled interaction.

5. In this example:
   - Data members (name, health, xp) are private.
   - Public method talk() is used to interact with the object safely.

6. Best practice:
   - Always prefer keeping class data private unless there's a specific reason not to.
   - This makes your class design robust and secure.
*/
