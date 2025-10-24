// File6: Friend_class.cpp
// ---------------------------------------------------------------
// Implements Friend_class. Because Player declared "friend class Friend_class;"
// every member function here can read or modify Player's private members.
// ---------------------------------------------------------------
#include <iostream>
#include "Friend_class.h"
// Player.h already included via Friend_class.h

void Friend_class::set_hero_name(Player& p, std::string name) {
    p.name = name;  // allowed due to friend class
}

void Friend_class::display_player(Player& p) {
    std::cout << "[Friend_class view] Name: "   << p.name   << std::endl;
    std::cout << "[Friend_class view] Health: " << p.health << std::endl;
    std::cout << "[Friend_class view] XP: "     << p.xp     << std::endl;
}
