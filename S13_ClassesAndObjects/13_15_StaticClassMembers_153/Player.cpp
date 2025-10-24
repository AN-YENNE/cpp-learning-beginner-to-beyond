#include "Player.h"

// Definition of the static data member.Must be defined exactly once in a single translation unit (a .cpp file).
int Player::num_players{0};

// Constructor definition: Increments the global count of active Player objects.
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
    ++num_players; // one more Player is now alive
}

// Copy constructor definition.
// Delegates to the main constructor to avoid code duplication.
// Also increments num_players because we are creating a new object.
Player::Player(const Player& source)
    : Player{source.name, source.health, source.xp}
{
    // Nothing else needed here; delegation handled initialization.
}

// Destructor definition: Decrements the count because this Player is being destroyed.
Player::~Player()
{
    --num_players; // one fewer Player is alive
}

// Static function definition: Returns the current number of live Player objects.
int Player::get_num_players()
{
    return num_players;
}

/*
Notes:
1) Why the static counter works:
   - Every time the constructor runs, we increment num_players.
   - Every time the destructor runs, we decrement num_players.
   - The result is the number of currently "alive" Player objects.

2) Where to define static data:
   - Declare in the class (header).
   - Define exactly once in a .cpp file.

3) Design tips:
   - Keep object state modifications inside constructors/destructors consistent
     so the count stays correct even if exceptions are thrown elsewhere.
   - If you add move/copy assignment operators later, ensure the counter remains correct
     (assignment does not create or destroy an object, so it should not change the count).

4) Alternatives:
   - For thread-safe counting in multithreaded programs, consider std::atomic<int>.
*/
