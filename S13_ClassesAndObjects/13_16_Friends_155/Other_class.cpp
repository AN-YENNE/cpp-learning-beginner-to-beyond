// File4: Other_class.cpp
// ---------------------------------------------------------------
// Implements Other_class::display_player. Because Player declared
// this specific member function as a friend, we can access p.name,
// p.health, and p.xp even though they are private.
// ---------------------------------------------------------------
#include <iostream>
#include "Other_class.h"
#include "Player.h"

void Other_class::display_player(Player& p) {
    std::cout << "[Other_class view] Name: "   << p.name   << std::endl;
    std::cout << "[Other_class view] Health: " << p.health << std::endl;
    std::cout << "[Other_class view] XP: "     << p.xp     << std::endl;
}
