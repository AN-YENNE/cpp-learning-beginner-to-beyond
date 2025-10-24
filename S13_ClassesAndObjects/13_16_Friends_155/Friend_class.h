// File5: Friend_class.h
// ---------------------------------------------------------------
// Declares a class that will be granted blanket friendship by Player.
// All member functions of Friend_class can access Player's private data.
// ---------------------------------------------------------------
#ifndef _FRIEND_CLASS_H_
#define _FRIEND_CLASS_H_

#include <string>
#include "Player.h"

class Friend_class {
public:
    void set_hero_name(Player& p, std::string name);
    void display_player(Player& p);
};

#endif // _FRIEND_CLASS_H_
