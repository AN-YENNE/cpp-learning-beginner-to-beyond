#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

// Player class demonstrates "static class members" that are shared across all objects.
// We use a static counter (num_players) to track how many Player objects currently exist.
class Player
{
private:
    // Static data member:
    // - Belongs to the class itself, not to individual objects.
    // - Only one copy exists no matter how many Player objects you create.
    static int num_players;

    // Regular (non-static) data members: Each object has its own separate copy of these.
    std::string name;
    int health;
    int xp;

public:
    // Simple getters. In production, consider making these const-qualified.
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() { return xp; }

    // Constructor with default parameters: This single constructor can act like multiple overloads depending on which arguments you pass.
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

    // Copy constructor: Called when creating a new Player as a copy of an existing one.
    Player(const Player& source);

    // Destructor: Called automatically when an object goes out of scope or is deleted.
    ~Player();

    // Static member function:
    // - Can be called without an object: Player::get_num_players()
    // - Has access only to static members of the class (like num_players).
    static int get_num_players();
};
#endif // _PLAYER_H_