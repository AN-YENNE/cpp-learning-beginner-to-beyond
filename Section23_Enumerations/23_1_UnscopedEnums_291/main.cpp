// --------------------------------------------------------------
// C++ Example: Unscoped Enumerations
// --------------------------------------------------------------

// Header files
#include <iostream>   // For input/output operations (std::cout, std::cin, std::endl)
#include <vector>     // For std::vector container to hold lists of enum values
#include <string>     // For std::string used in helper functions

// --------------------------------------------------------------
// TEST 1 - Unscoped Enum: Direction
// --------------------------------------------------------------

// Unscoped enumeration representing directions.
// Note: Unscoped enums automatically convert to their underlying integral type.
enum Direction { North = 1, South = 10, East, West };

// -------------------------------------------------------------------------
// Converts a Direction enum value to its string representation.
// -------------------------------------------------------------------------
std::string direction_to_string(Direction direction) {
    switch (direction) {
        case North: return "North";
        case South: return "South";
        case East:  return "East";
        case West:  return "West";
        default:    return "Unknown direction";
    }
}

// -------------------------------------------------------------------------
// Demonstrates basic usage of an unscoped enum and casting behavior.
// -------------------------------------------------------------------------
void test1() {
    std::cout << "\n--- Test1: Direction Enum --------------------------\n" << std::endl;

    Direction direction {North};

    // Implicitly prints the underlying integer value (unscoped enums behave like ints)
    std::cout << "Current Direction (raw): " << direction << std::endl;
    std::cout << "Current Direction (string): " << direction_to_string(direction) << std::endl;

    // Changing direction
    direction = West;
    std::cout << "\nUpdated Direction (raw): " << direction << std::endl;
    std::cout << "Updated Direction (string): " << direction_to_string(direction) << std::endl;

    // direction = 5;  //Compiler error — implicit assignment from int not allowed

    // Warning: But casting can bypass type-safety
    direction = Direction(100);
    std::cout << "\nDirection after unsafe cast (raw): " << direction << std::endl;
    std::cout << "Direction after unsafe cast (string): " << direction_to_string(direction) << std::endl;

    direction = static_cast<Direction>(100);
    std::cout << "\nDirection after static_cast (raw): " << direction << std::endl;
    std::cout << "Direction after static_cast (string): " << direction_to_string(direction) << std::endl;
}

// --------------------------------------------------------------
// TEST 2 - Unscoped Enum: Grocery Items
// --------------------------------------------------------------

// Unscoped enumeration for grocery list items
enum Grocery_Item { Milk, Bread, Apple, Orange };

// -------------------------------------------------------------------------
// Overloaded output stream operator for Grocery_Item.
// Converts enum to a readable string when printing.
// -------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
    switch (grocery_item) {
        case Milk:   os << "Milk"; break;
        case Bread:  os << "Bread"; break;
        case Apple:  os << "Apple"; break;
        case Orange: os << "Orange"; break;
        default:     os << "Invalid item"; break;
    }
    return os;
}

// -------------------------------------------------------------------------
// Checks if a Grocery_Item is valid (i.e., one of the defined enum values).
// -------------------------------------------------------------------------
bool is_valid_grocery_item(Grocery_Item grocery_item)
{
    switch (grocery_item) {
        case Milk:
        case Bread:
        case Apple:
        case Orange:
            return true;
        default:
            return false;
    }
}

// -------------------------------------------------------------------------
// Displays grocery list and counts valid vs. invalid items.
// -------------------------------------------------------------------------
void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{
    std::cout << "Grocery List\n==============================" << std::endl;
    int valid_count {0};
    int invalid_count {0};

    for (Grocery_Item item : grocery_list) {
        std::cout << item << std::endl;  // Uses overloaded operator<<

        if (is_valid_grocery_item(item))
            ++valid_count;
        else
            ++invalid_count;
    }

    std::cout << "==============================" << std::endl;
    std::cout << "Valid items:   " << valid_count << std::endl;
    std::cout << "Invalid items: " << invalid_count << std::endl;
    std::cout << "Total items:   " << valid_count + invalid_count << std::endl;
}

// -------------------------------------------------------------------------
// Demonstrates unscoped enums with a grocery list and type safety issues.
// -------------------------------------------------------------------------
void test2() {
    std::cout << "\n--- Test2: Grocery Items Enum --------------------------\n" << std::endl;

    std::vector<Grocery_Item> shopping_list;
    shopping_list.push_back(Apple);
    shopping_list.push_back(Apple);
    shopping_list.push_back(Milk);
    shopping_list.push_back(Orange);

    int Helicopter {1000};

    // shopping_list.push_back(Helicopter); // Beware of Compiler error
    shopping_list.push_back(Grocery_Item(Helicopter));  // Beware Unsafe cast — invalid item
    shopping_list.push_back(Grocery_Item(0));           // Valid — adds Milk again

    display_grocery_list(shopping_list);
}

// --------------------------------------------------------------
// TEST 3 - Unscoped Enum: Rocket Launch States
// --------------------------------------------------------------

// Unscoped enumerations for rocket launch state and sequence
enum State { Engine_Failure, Inclement_Weather, Nominal, Unknown };
enum Sequence { Abort, Hold, Launch };

// -------------------------------------------------------------------------
// Overloaded input stream operator (>>) for State.
// Allows the user to input a number to set the State.
// -------------------------------------------------------------------------
std::istream &operator>>(std::istream &is, State &state)
{
    std::underlying_type_t<State> user_input {};
    is >> user_input;

    switch (user_input) {
        case Engine_Failure:
        case Inclement_Weather:
        case Nominal:
        case Unknown:
            state = static_cast<State>(user_input);
            break;
        default:
            std::cout << "Invalid input. Defaulting to Unknown state." << std::endl;
            state = Unknown;
    }
    return is;
}

// -------------------------------------------------------------------------
// Overloaded output stream operator for Sequence.
// Prints the sequence name as a string.
// -------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
    switch (sequence) {
        case Abort:   os << "Abort"; break;
        case Hold:    os << "Hold"; break;
        case Launch:  os << "Launch"; break;
    }
    return os;
}

// -------------------------------------------------------------------------
// Prints an action message based on the launch sequence.
// -------------------------------------------------------------------------
void initiate(Sequence sequence)
{
    std::cout << "Initiating " << sequence << " sequence!" << std::endl;
}

// -------------------------------------------------------------------------
// Demonstrates using unscoped enums with input/output to control a rocket launch.
// -------------------------------------------------------------------------
void test3() {
    std::cout << "\n--- Test3: Rocket Launch State --------------------------\n" << std::endl;

    State state;
    std::cout << "Enter launch state (0 = Engine_Failure, 1 = Inclement_Weather, 2 = Nominal, 3 = Unknown): ";
    std::cin >> state;  // Uses overloaded operator >>

    switch (state) {
        case Engine_Failure:
        case Unknown:
            initiate(Abort);
            break;
        case Inclement_Weather:
            initiate(Hold);
            break;
        case Nominal:
            initiate(Launch);
            break;
    }
}

// --------------------------------------------------------------
// main()
// --------------------------------------------------------------
int main()
{
    test1();
    test2();
    test3();

    std::cout << "\nProgram finished successfully" << std::endl;
    return 0;
}