// File1: Player.h
// ---------------------------------------------------------------
// Section 13 - Friends in Classes (Beginner Friendly Version)
// This header defines a Player class and demonstrates the friend
// function and friend class features.
// 
// What you will learn here:
// 1) How a non-member function can be granted access to private data
//    via "friend void display_player(Player& p);"
// 2) How a member function of another class can be a friend
//    via "friend void Other_class::display_player(Player& p);"
// 3) How an entire class can be granted access to private data
//    via "friend class Friend_class;"
// 4) How to forward declare types to avoid circular includes.
//
// Notes:
// - Friends break encapsulation on purpose, so use them sparingly.
// - Friend declarations appear inside the class whose private data
//   you want to grant access to.
// ---------------------------------------------------------------
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

// Forward declarations to avoid circular dependencies.
// We need Other_class and the free function display_player later.
#include "Other_class.h"   // declares Other_class and its member function
class Friend_class;        // forward declare the class type (no header needed here yet)

class Player {
    // Grant friendship to a specific member function of another class.
    // This allows Other_class::display_player to access private members of Player.
    friend void Other_class::display_player(Player& p);

    // Grant friendship to a free function.
    // This allows the non-member function display_player to access private members.
    friend void display_player(Player& p);

    // Grant friendship to an entire class.
    // All member functions of Friend_class can access Player's private members.
    friend class Friend_class;

private:
    // Static data is shared across all Player objects.
    static int num_players;

    // Regular instance data. These are private by design.
    std::string name;
    int health;
    int xp;

public:
    // Simple accessors. In production, prefer const-correctness on getters.
    std::string get_name()        { return name; }
    int         get_health()      { return health; }
    int         get_xp()          { return xp; }

    // Constructor with defaults so we can create Players easily.
    Player(std::string name_val = "Unnamed", int health_val = 0, int xp_val = 0);

    // Copy constructor for completeness.
    Player(const Player& source);

    // Destructor updates the live instance counter.
    ~Player();

    // Static query for current number of live Player objects.
    static int get_num_players();
};

#endif // _PLAYER_H_
