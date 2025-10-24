// Section 13: Static class members
//
// This program shows how a static class member can track how many
// Player objects are currently alive. We print the count at different
// points to observe how it changes as objects are created and destroyed.

#include <iostream>
#include "Player.h"

using namespace std;

// Helper function that uses the class-level static function.
// Note that we do not need a Player object to call get_num_players().
void display_active_players() {
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main() {
    // At program start there are no Player objects yet.
    display_active_players();

    // Create a Player on the stack. Constructor increments the counter.
    Player player_one{"PlayerOne"};
    display_active_players();

    // Create a nested scope to demonstrate automatic destruction at scope end.
    {
        Player player_two{"PlayerTwo"};
        display_active_players();
        // player_two will be destroyed when this block ends,
        // calling the destructor and decrementing the counter.
    }
    // After the inner scope, player_two is gone.
    display_active_players();

    // Create a Player dynamically on the heap using new.
    // This also increments the static counter.
    Player* enemy_npc = new Player("EnemyNPC", 100, 100);
    display_active_players();

    // Manually delete the heap-allocated object to avoid a memory leak.
    // Destructor runs and decrements the counter.
    delete enemy_npc;
    display_active_players();

    // When main returns, player_one goes out of scope and its destructor runs,
    // bringing the count back down by one more (not shown since program ends).
    return 0;
}

/*
Summary Notes:
1) Static data member (Player::num_players):
   - One per class, shared by all objects.
   - Tracks live instances in this example.

2) Static member function (Player::get_num_players):
   - Can be called without an instance: Player::get_num_players().
   - Only accesses static data.

3) Object lifetime:
   - Stack objects are destroyed automatically at end of scope.
   - Heap objects must be deleted manually (or use smart pointers).

4) Good practice:
   - Prefer smart pointers (std::unique_ptr<Player>) for dynamic allocation
     to avoid manual delete and memory leaks.
   - Example:
       auto enemy = std::make_unique<Player>("EnemyNPC", 100, 100);
       display_active_players();
       // When 'enemy' goes out of scope, it is deleted automatically.
*/
