// File7: main.cpp
// ---------------------------------------------------------------
// Demonstrates three ways to access Player's private data using friends:
// 1) A free function made friend of Player.
// 2) A specific member function of Other_class made friend of Player.
// 3) An entire Friend_class made friend of Player.
//
// Also shows that without friendship, private members are not accessible.
// ---------------------------------------------------------------
#include <iostream>
#include <string>
#include "Player.h"
#include "Other_class.h"
#include "Friend_class.h"

// Free function that will be declared as a friend inside Player.
// Because of that friend declaration, this function can access private members.
void display_player(Player& p) {
    std::cout << "[Free function view] Name: "   << p.name   << std::endl;
    std::cout << "[Free function view] Health: " << p.health << std::endl;
    std::cout << "[Free function view] XP: "     << p.xp     << std::endl;
}

int main() {
    // Create a Player object with generic sample values
    Player main_hero{"MainHero", 100, 35};

    // 1) Use the friend free function
    display_player(main_hero);

    // 2) Use the friend member function of Other_class
    Other_class inspector;
    inspector.display_player(main_hero);

    // 3) Use the friend class to both modify and display private data
    Friend_class editor;
    editor.set_hero_name(main_hero, "RenamedHero");
    editor.display_player(main_hero);

    // Show current live player count using a static class member function
    std::cout << "Live Player objects: " << Player::get_num_players() << std::endl;

    return 0;
}

/*
Summary Notes:
1) What friendship does:
   - A friend function or friend class can access private and protected members
     of the class that grants the friendship.
   - Friendship is not symmetric, not transitive, and not inherited.
     Symmetric means: if A is friend of B, B is not automatically friend of A.
     Transitive means: if A is friend of B and B is friend of C, A is not automatically friend of C.
     Inherited means: if Base grants friendship to X, Derived does not automatically grant it.

2) When to use friends:
   - When a non-member function must work closely with the internals of a class.
   - When utility or helper classes need low-level access for performance or design reasons.

3) Use with care:
   - Friends break encapsulation, so they should be rare and intentional.
   - Consider whether a public API or a different design can solve the problem first.

4) Forward declarations:
   - Use them to break circular dependencies between headers.
   - Here, Player needs to mention Other_class::display_player as a friend.
     We include Other_class.h in Player.h so the compiler knows that member exists.
   - For Friend_class, a forward declaration is enough in Player.h because we only
     name the type there; definitions live in Friend_class.h/cpp.

5) Static members:
   - Player::num_players tracks the number of live Player objects.
   - Always define static data exactly once in a .cpp file.
*/
