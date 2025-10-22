// Section 13: Constructors and Destructors
//
//  What you'll see in this file:
//   • A simple Player class with multiple (overloaded) constructors
//   • A destructor that announces when an object is being destroyed
//   • Examples of stack vs. heap (dynamic) allocation and object lifetimes
//   • Lots of inline tips on syntax, semantics, and best practices
//
//  Note: The extra std::cout lines are here purely so you can *see*
//          when each constructor/destructor runs and what gets initialized.

#include <iostream>   // std::cout, std::endl
#include <string>     // std::string

using namespace std;  
// ^ OK for small examples/demos.
//   In production code prefer writing std::string, std::cout, etc. to avoid name clashes.

class Player
{
private:
    // Data members (a.k.a. "fields" or "instance variables")
    // Keep them private to enforce encapsulation. Expose behavior via public functions.
    std::string name;
    int health;
    int xp;

public:
    // Setter (mutator). We pass by const reference in production to avoid copies,
    //    but for clarity we accept by value here.
    void set_name(std::string name_val) {
        name = name_val;   // "this->name" could be used to be explicit
    }

    // BEST PRACTICE: Provide *sane defaults* via in-class member initializers
    //    or via constructor initializer lists. We’ll use initializer lists
    //    in the constructors below.

    // Default (no-args) constructor called when you create an object with no arguments: Player p;
    Player()
        : name{"Unknown"}, health{0}, xp{0}     // ← initializer list (runs before the body)
    {
        cout << "[Default Ctor] Created Player with default values: "
             << "name='" << name << "', health=" << health << ", xp=" << xp << endl;
    }

    // 1-arg constructor (overloaded), Called when you provide just a name: Player p("PlayerOne");
    Player(std::string name_val)
        : name{name_val}, health{100}, xp{0}    // give a healthy starting point
    {
        cout << "[1-Arg Ctor] Created Player with name='" << name
             << "', health=" << health << ", xp=" << xp << endl;
    }

    // 3-arg constructor (overloaded), Called when you provide name, health, and xp: Player p("X", 50, 10);
    Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val}
    {
        cout << "[3-Arg Ctor] Created Player with name='" << name
             << "', health=" << health << ", xp=" << xp << endl;
    }

    // Destructor: Automatically called when the object’s lifetime ends:
    //    • For stack objects: when they go out of scope
    //    • For heap objects: when you delete the pointer
    ~Player() {
        cout << "[Dtor] Destroying Player '" << name << "' (health=" << health
             << ", xp=" << xp << ")" << endl;
    }

    // Notes:
    //  • Constructors may be *overloaded* as long as their parameter lists differ.
    //  • The *initializer list* is preferred over assignment in the body because:
    //      - It directly constructs members with the given values (no default-then-assign).
    //      - It’s required for const or reference members.
    //  • If you allocate resources (e.g., new[], fopen, etc.), release them in the destructor.
    //    That pattern is called RAII (Resource Acquisition Is Initialization).
    //  • If you manage resources, learn about the "Rule of Three/Five/Zero".
    //  • In modern C++, prefer smart pointers (unique_ptr, shared_ptr) instead of raw new/delete.
};

int main() {

    // ------------------------------------------------------------
    // SCOPE 1: Stack allocation with a nested block
    // ------------------------------------------------------------
    {
        // Stack (automatic storage): object lives until end of this block, then is destroyed.
        Player temporary_player;                 // calls default constructor
        temporary_player.set_name("PlayerTemp"); // setter shows how to modify after construction
        // When this block ends, ~Player() will run automatically for temporary_player.
    } // ← end of scope → destructor runs here for temporary_player

    // ------------------------------------------------------------
    // SCOPE 2: More stack objects showing constructor overloading
    // ------------------------------------------------------------
    {
        Player player_one;                       // default ctor
        player_one.set_name("PlayerOne");

        Player main_hero("MainHero");            // 1-arg ctor
        // setter is optional here since we already set name via the ctor,
        // but we’ll call it to show that you *can* change state later:
        main_hero.set_name("MainHero");

        Player main_villain("MainVillain", 120, 15); // 3-arg ctor
        main_villain.set_name("MainVillain");
        // All three stack objects will be destroyed in reverse order at the end of this block.
    } // ← end of scope → destructors run (main_villain, main_hero, player_one)

    // ------------------------------------------------------------
    // HEAP / DYNAMIC ALLOCATION (use sparingly in beginner code)
    // ------------------------------------------------------------
    // Raw new/delete is error-prone. Prefer smart pointers:
    //    auto enemy_npc = std::make_unique<Player>();
    //    auto boss_npc  = std::make_unique<Player>("BossNPC", 1000, 300);
    //    (Then you don’t need delete; they free automatically.)
    // Here we use raw pointers just to demonstrate constructor/destructor order.

    Player* enemy_npc = new Player;                    // default ctor
    enemy_npc->set_name("EnemyNPC");

    Player* boss_npc = new Player("BossNPC", 1000, 300);  // 3-arg ctor
    boss_npc->set_name("BossNPC");

    // IMPORTANT: Always pair every new with a delete, otherwise you leak memory.
    delete enemy_npc;  // calls ~Player() on the object, then frees memory
    delete boss_npc;   // calls ~Player() on the object, then frees memory

    // ------------------------------------------------------------
    // QUICK RECAP (conceptual, no code):
    // • Constructors run when objects are created; destructors run when they die.
    // • Stack objects are destroyed automatically when they go out of scope.
    // • Heap objects require manual delete (or better: smart pointers to auto-manage).
    // • Overloaded constructors let you offer different ways to create objects.
    // • Use initializer lists to set member variables efficiently and correctly.
    // ------------------------------------------------------------

    return 0;
}
