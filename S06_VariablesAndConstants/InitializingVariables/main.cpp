// Section 6: Declaring and Initializing Variables
//
// This example asks the user to input the width and length of a room
// and calculates its area. It demonstrates how to declare and initialize
// variables properly in C++.
//
// Key concepts covered:
// 1) Variable declaration and initialization
// 2) Different initialization syntaxes in C++
// 3) Input (cin) and output (cout)
// 4) Basic arithmetic operations

#include <iostream>
using namespace std;

// This program calculates the area of a rectangular room in square feet.
int main() {
    cout << "=== Room Area Calculator ===" << endl;

    // Prompt the user for width and length.
    // Initialize with 0 to avoid using uninitialized variables.
    cout << "Enter the width of the room (in feet): ";
    int room_width {0};   // C++11 list initialization (preferred)
    cin >> room_width;    // take input from the user and store in room_width

    cout << "Enter the length of the room (in feet): ";
    int room_length {0};  // C++11 list initialization
    cin >> room_length;

    // Compute area using the formula: area = width * length
    int area {room_width * room_length};

    cout << "The area of the room is " << area << " square feet." << endl;

    return 0;
}

/*
-------------------------------------------------------------
Notes: Variable Initialization in C++
-------------------------------------------------------------

You can initialize variables in several ways:

1) **Uninitialized variable (not recommended)**
   int age; 
   // 'age' has an undefined value (garbage). Avoid this!

2) **C-style initialization**
   int age = 21;
   // Uses the assignment operator (=) at declaration time.
   // Common in older C-style code.

3) **Constructor-style initialization**
   int age(21);
   // Uses parentheses, similar to object construction.

4) **List initialization (C++11 and later)**
   int age {21};
   // Preferred modern style.
   // Prevents "narrowing" conversions (e.g., from double to int).

   Example:
   double price {19.99};
   int quantity {2};
   double total_cost {price * quantity};

-------------------------------------------------------------
Tips:
- Always initialize variables before using them.
- Use descriptive variable names (e.g., room_width, room_length).
- List initialization (using { }) is safest and most modern.
- Use `cin` for user input and `cout` for displaying results.
-------------------------------------------------------------
*/