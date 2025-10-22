// Section 13: Copy Constructor
// The copy constructor is a special constructor used to create a new object
// as a copy of an existing object. It performs *member-wise copying* by default,
// but you can define your own version for more control (for example, deep copies).
//
// Syntax:
// Player(const Player &source);
//
// The ampersand (&) means we are passing the object by reference,
// and 'const' ensures the original object is not modified during copying.

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    // Private data members
    std::string name;
    int health;
    int xp;

public:
    // Getter functions to read private data safely
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() { return xp; }

    // Constructor with default parameters
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

    // Copy constructor
    Player(const Player &source);

    // Destructor (just to show when an object is destroyed)
    ~Player() { 
        cout << "Destructor called for: " << name << endl; 
    }
};

// Regular (parameterized) constructor definition
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} 
{
    cout << "Three-args constructor called for: " << name << endl;
}

// Copy constructor definition
Player::Player(const Player &source)
    // Delegates to the three-argument constructor to reuse initialization logic
    : Player{source.name, source.health, source.xp}
{
    cout << "Copy constructor - created a copy of: " << source.name << endl;
}

// A function that takes a Player object *by value*
// This triggers the copy constructor because the argument must be copied into the function.
void display_player(Player p) {
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;
}

int main() {
    // Example 1: Create a Player object using the 3-argument constructor
    Player base_player{"BasePlayer", 100, 50};

    // Example 2: Create a copy of 'base_player' using the copy constructor
    Player player_copy{base_player};  // Calls copy constructor
    // This creates a new Player object with the same values as base_player

    // Example 3: Pass an object by value to a function
    // When display_player() is called, the argument is passed *by value*,
    // which means the copy constructor runs again to make a temporary copy.
    display_player(base_player);

    // Example 4: Create a few more Player objects using normal constructors
    Player player_one{"PlayerOne"};
    Player player_two{"PlayerTwo", 100};
    Player player_three{"PlayerThree", 100, 55};

    // When main() ends:
    // Destructors will run automatically for each object (in reverse order of creation)
    // This shows how copy-constructed and normally-constructed objects are both destroyed properly.

    return 0;
}

/*
Summary Notes:
1. The copy constructor is called in these cases:
   - When a new object is created as a copy of another (e.g., Player p2{p1};)
   - When an object is passed to a function *by value*
   - When an object is returned *by value* from a function

2. The default compiler-generated copy constructor performs a *shallow copy*
   (copies values of all member variables).
   You can define your own if your class manages dynamic memory or resources.

3. Syntax:
       ClassName(const ClassName &source);

4. Why use const reference (&):
   - Prevents modification of the original object.
   - Avoids unnecessary copying (efficient).

5. Delegating inside the copy constructor:
   - Here, we call the three-argument constructor from within the copy constructor
     to reuse initialization code and avoid duplication.

6. If your class does not manage dynamic memory (for example, uses only standard types
   like std::string, int, etc.), the default copy constructor works fine.

7. If your class allocates resources manually (e.g., with new),
   you must implement your own copy constructor and destructor carefully
   to prevent shallow copy issues and memory leaks.

8. Destructor:
   - Called automatically when an object goes out of scope or is deleted.
   - Used here just to visualize object destruction order.
*/
