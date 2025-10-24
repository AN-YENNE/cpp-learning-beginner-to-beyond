// File2: Player.cpp
// ---------------------------------------------------------------
// Implements Player. Shows how friend declarations in Player.h
// allow external functions/classes to access private members.
// Also tracks number of live Player objects with a static counter.
// ---------------------------------------------------------------
#include "Player.h"

// Define the static data member once in a single translation unit.
int Player::num_players {0};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
    ++num_players;
    // Optional learning output:
    // std::cout << "Player constructed: " << name << "\n";
}

Player::Player(const Player& source)
    : Player{source.name, source.health, source.xp}
{
    // Optional learning output:
    // std::cout << "Player copy-constructed from: " << source.name << "\n";
}

Player::~Player() {
    --num_players;
    // Optional learning output:
    // std::cout << "Player destroyed: " << name << "\n";
}

int Player::get_num_players() {
    return num_players;
}
