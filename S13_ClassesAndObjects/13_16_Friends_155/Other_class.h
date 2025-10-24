// File3: Other_class.h
// ---------------------------------------------------------------
// Declares a helper class with a member function that will be
// made a friend of Player so it can access Player's private data.
// Note: We forward declare Player here to avoid include cycles.
// ---------------------------------------------------------------
#ifndef _OTHER_CLASS_H_
#define _OTHER_CLASS_H_

class Player;  // forward declaration

class Other_class {
public:
    // This member function will be declared as a friend inside Player.
    // Once it is a friend, it can read Player's private members directly.
    void display_player(Player& p);
};

#endif // _OTHER_CLASS_H_
