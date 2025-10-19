// --------------------------------------------------------------
// C++ Example: Scoped Enumerations & Class Enums with Functions
// --------------------------------------------------------------

// Required headers
#include <iostream>   // For input/output operations (std::cout, std::endl)
#include <vector>     // For std::vector container
#include <string>     // For std::string (used in Player class)

// --------------------------------------------------------------
// TEST 1 - Scoped Enumeration: Grocery Items
// --------------------------------------------------------------

// Scoped enumeration to represent grocery items with their codes (in cents)
enum class Grocery_Item { Milk = 350, Bread = 250, Apple = 132, Orange = 100 };

// -------------------------------------------------------------------------
// Overloaded output stream operator (<<) for Grocery_Item.
// Displays the item name and its underlying value.
// -------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
    using underlying_t = std::underlying_type_t<Grocery_Item>;
    underlying_t value = static_cast<underlying_t>(grocery_item);

    switch (grocery_item) {
        case Grocery_Item::Milk:
            os << "Milk";
            break;
        case Grocery_Item::Bread:
            os << "Bread";
            break;
        case Grocery_Item::Apple:
            os << "Apple";
            break;
        case Grocery_Item::Orange:
            os << "Orange";
            break;
        default:
            os << "Invalid item";
            break;
    }

    os << " : " << value;
    return os;
}

// -------------------------------------------------------------------------
// Helper function to check if a Grocery_Item is valid.
// -------------------------------------------------------------------------
bool is_valid_grocery_item(Grocery_Item grocery_item)
{
    switch (grocery_item) {
        case Grocery_Item::Milk:
        case Grocery_Item::Bread:
        case Grocery_Item::Apple:
        case Grocery_Item::Orange:
            return true;
        default:
            return false;
    }
}

// -------------------------------------------------------------------------
// Displays all items in a grocery list and counts valid/invalid entries.
// -------------------------------------------------------------------------
void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{
    std::cout << "Grocery List\n==============================" << std::endl;

    int valid_item_count {0};
    int invalid_item_count {0};

    for (Grocery_Item item : grocery_list) {
        std::cout << item << std::endl;  // Uses overloaded operator<<

        if (is_valid_grocery_item(item))
            valid_item_count++;
        else
            invalid_item_count++;
    }

    std::cout << "==============================" << std::endl;
    std::cout << "Valid items:   " << valid_item_count << std::endl;
    std::cout << "Invalid items: " << invalid_item_count << std::endl;
    std::cout << "Total items:   " << valid_item_count + invalid_item_count << std::endl;
}

// -------------------------------------------------------------------------
// TEST FUNCTION 1
// Demonstrates the use of a scoped enum and its validation/display.
// -------------------------------------------------------------------------
void test1()
{
    std::cout << "\n--- Test1: Grocery Items --------------------------\n" << std::endl;

    std::vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Grocery_Item::Apple);
    shopping_list.push_back(Grocery_Item::Milk);
    shopping_list.push_back(Grocery_Item::Orange);

    int Helicopter { 1000 };

    // shopping_list.push_back(Helicopter); // ❌ Compile error - type safe
    shopping_list.push_back(Grocery_Item(Helicopter));  // Will be treated as invalid item
    shopping_list.push_back(Grocery_Item(350));         // Will add "Milk" again

    display_grocery_list(shopping_list);
}

// --------------------------------------------------------------
// TEST 2 - Player Class using Enums
// --------------------------------------------------------------

// A simple class that might model a Player in a game.
// The player has a name, a mode (state of action), and a direction they face.
class Player {
    friend std::ostream &operator<<(std::ostream &os, const Player &p);

public:
    // Player state enumerations
    enum class Mode { Attack, Defense, Idle };
    enum class Direction { North, South, East, West };

    Player(std::string name,
           Mode mode = Mode::Idle,
           Direction direction = Direction::North)
        : name{name}, mode{mode}, direction{direction} {}

    // Getters and setters
    std::string get_name() const { return name; }
    void set_name(const std::string &n) { name = n; }

    Mode get_mode() const { return mode; }
    void set_mode(Mode m) { mode = m; }

    Direction get_direction() const { return direction; }
    void set_direction(Direction d) { direction = d; }

private:
    std::string name;
    Mode mode;
    Direction direction;
};

// -------------------------------------------------------------------------
// Returns string representation of Player::Mode
// -------------------------------------------------------------------------
std::string get_player_mode(Player::Mode mode)
{
    switch (mode) {
        case Player::Mode::Attack:  return "Attack";
        case Player::Mode::Defense: return "Defense";
        case Player::Mode::Idle:    return "Idle";
    }
    return "Unknown";
}

// -------------------------------------------------------------------------
// Returns string representation of Player::Direction
// -------------------------------------------------------------------------
std::string get_player_direction(Player::Direction direction)
{
    switch (direction) {
        case Player::Direction::North: return "North";
        case Player::Direction::South: return "South";
        case Player::Direction::East:  return "East";
        case Player::Direction::West:  return "West";
    }
    return "Unknown";
}

// -------------------------------------------------------------------------
// Overloaded output stream operator for Player
// Makes printing Player objects easy and clean.
// -------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, const Player &p)
{
    os << "Player name:      " << p.get_name() << "\n"
       << "Player mode:      " << get_player_mode(p.get_mode()) << "\n"
       << "Player direction: " << get_player_direction(p.get_direction()) << std::endl;
    return os;
}

// -------------------------------------------------------------------------
// TEST FUNCTION 2
// Demonstrates use of Player class with enum states and output formatting.
// -------------------------------------------------------------------------
void test2()
{
    std::cout << "\n--- Test2: Player Class --------------------------\n" << std::endl;

    Player p1{"Cloud Strife", Player::Mode::Attack,  Player::Direction::North};
    Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
    Player p3{"Sephiroth",     Player::Mode::Idle,    Player::Direction::South};

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
}

// --------------------------------------------------------------
// main()
// --------------------------------------------------------------
int main()
{
    test1();
    test2();

    std::cout << "\nProgram finished successfully ✅" << std::endl;
    return 0;
}
