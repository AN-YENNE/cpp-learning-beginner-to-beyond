// Section 6: Constants
//
// This program demonstrates how to use constants in C++
// while creating a simple estimate calculator for a carpet cleaning service.
//
// Key concepts covered:
// 1) Declaring and using constants with the `const` keyword
// 2) Basic input/output
// 3) Performing arithmetic calculations
// 4) Understanding why constants are important
//
// Constants help prevent accidental modification of values
// that should not change during program execution.

#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Sparkle Carpet Cleaning Service!" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\nHow many rooms would you like cleaned? ";

    // Ask user for input
    int number_of_rooms {0};
    cin >> number_of_rooms;

    // Constant declarations (these values should never change)
    const double price_per_room {35.0};     // price per room in dollars
    const double sales_tax_rate {0.06};     // 6% tax
    const int estimate_expiry_days {30};    // offer validity period

    // Compute the estimate
    double cost {price_per_room * number_of_rooms};
    double tax {cost * sales_tax_rate};
    double total_estimate {cost + tax};

    // Display the estimate summary
    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Number of rooms:   " << number_of_rooms << endl;
    cout << "Price per room:    $" << price_per_room << endl;
    cout << "Cost:              $" << cost << endl;
    cout << "Tax:               $" << tax << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Total estimate:    $" << total_estimate << endl;
    cout << "This estimate is valid for " << estimate_expiry_days << " days." << endl;
    cout << endl;

    return 0;
}

/*
=============================================================
Notes on Constants in C++
=============================================================

Like variables, constants:
- Have names
- Occupy memory
- Are strongly typed
But, unlike variables — their value **cannot change** once declared!

-------------------------------------------------------------
Types of Constants in C++
-------------------------------------------------------------

1) **Literal Constants**
   Directly written values.
   Example: 10, 3.14, 'A', true

   ```cpp
   cout << 3.14 * 2 << endl;   // 3.14 is a literal constant

2)Declared Constants (const keyword)
Use the const keyword to declare read-only variables.
Example:

const double gravity {9.81};
const int days_in_week {7};


3)Constant Expressions (constexpr keyword)
Evaluated at compile time.
Example:

constexpr int max_buffer_size {1024};
constexpr double pi {3.1415926535};


4)Enumerated Constants (enum keyword)
Define a list of related integer constants.
Example:

enum Direction { North, South, East, West };
Direction heading = North;


5)Defined Constants (#define preprocessor macro)
A C-style way to define constants (less preferred in modern C++).
Example:

#define TAX_RATE 0.06

Why use constants?
Makes your code easier to read and understand.
Prevents accidental value changes.
Simplifies updates (change once, apply everywhere).
Allows the compiler to optimize better.
Modern Best Practice:

Use const for runtime constants.
Use constexpr for compile-time constants.
Avoid #define for defining constants in modern C++.

*/