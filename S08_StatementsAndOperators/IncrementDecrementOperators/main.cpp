// Section 8: Increment and Decrement Operators
//
// This program demonstrates the increment (++) and decrement (--) operators in C++.
// These operators increase or decrease a variable's value by 1.
// They can be used in prefix (++x) or postfix (x++) form.

#include <iostream>
using namespace std;

int main() {

    int counter {10};
    int result {0};

    /************************************************************
     * 1) Simple Increment Example
     ************************************************************/
    cout << "=== Simple Increment Example ===" << endl;
    cout << "Initial counter: " << counter << endl;

    counter = counter + 1;
    cout << "After counter = counter + 1; counter = " << counter << endl;

    counter++;
    cout << "After counter++; counter = " << counter << endl;

    ++counter;
    cout << "After ++counter; counter = " << counter << endl;

    /************************************************************
     * 2) Pre-increment Example (++var)
     ************************************************************/
    counter = 10;
    result = 0;

    cout << "\n=== Pre-Increment Example ===" << endl;
    cout << "Initial counter: " << counter << endl;

    result = ++counter;  // counter incremented first, then assigned
    cout << "After result = ++counter;" << endl;
    cout << "Counter: " << counter << ", Result: " << result << endl;

    /************************************************************
     * 3) Post-increment Example (var++)
     ************************************************************/
    counter = 10;
    result = 0;

    cout << "\n=== Post-Increment Example ===" << endl;
    cout << "Initial counter: " << counter << endl;

    result = counter++;  // counter assigned first, then incremented
    cout << "After result = counter++;" << endl;
    cout << "Counter: " << counter << ", Result: " << result << endl;

    /************************************************************
     * 4) Pre-increment in an Expression
     ************************************************************/
    counter = 10;
    result = 0;

    cout << "\n=== Pre-Increment in an Expression ===" << endl;
    cout << "Initial counter: " << counter << endl;

    result = ++counter + 10;  // counter incremented first, then used in addition
    cout << "After result = ++counter + 10;" << endl;
    cout << "Counter: " << counter << ", Result: " << result << endl;

    /************************************************************
     * 5) Post-increment in an Expression
     ************************************************************/
    counter = 10;
    result = 0;

    cout << "\n=== Post-Increment in an Expression ===" << endl;
    cout << "Initial counter: " << counter << endl;

    result = counter++ + 10;  // counter used first, then incremented
    cout << "After result = counter++ + 10;" << endl;
    cout << "Counter: " << counter << ", Result: " << result << endl;

    /************************************************************
     * 6) Decrement Operator Examples (--var, var--)
     ************************************************************/
    counter = 5;
    cout << "\n=== Decrement Operator Examples ===" << endl;
    cout << "Initial counter: " << counter << endl;

    --counter;
    cout << "After --counter; counter = " << counter << endl;

    counter--;
    cout << "After counter--; counter = " << counter << endl;

    /************************************************************
     * 7) Notes on Caution
     ************************************************************/
    cout << "\n=== Important Notes ===" << endl;
    cout << "• Avoid using multiple increments/decrements on the same variable in one statement." << endl;
    cout << "  Example: result = counter++ + ++counter;  // undefined behavior!" << endl;
    cout << "• Use ++ and -- carefully, especially inside complex expressions." << endl;
    cout << "• Prefer clarity over brevity — when in doubt, separate operations into multiple lines." << endl;

    cout << "\nProgram complete." << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON INCREMENT (++) AND DECREMENT (--) OPERATORS
=====================================================================

1. Purpose:
------------
The increment (++) and decrement (--) operators increase or decrease
their operand’s value by 1.

    ++x  → Prefix increment: increments first, then uses the new value.
    x++  → Postfix increment: uses current value first, then increments.

    --x  → Prefix decrement: decrements first, then uses the new value.
    x--  → Postfix decrement: uses current value first, then decrements.

---------------------------------------------------------------------

2. Example Behavior:
--------------------
int counter = 10;
int result;

Prefix (++x)
--------------
result = ++counter;
(counter becomes 11, result = 11)

Postfix (x++)
--------------
result = counter++;
(result = 10, counter becomes 11)

---------------------------------------------------------------------

3. Valid Types:
----------------
These operators can be used with:
- Integers
- Floating-point numbers
- Pointers (moves pointer to next/previous memory location)

---------------------------------------------------------------------

4. Important Rules:
-------------------
- Never apply multiple increments/decrements to the same variable
  in one statement (undefined behavior):
    result = counter++ + ++counter; // Avoid this!

- The prefix and postfix versions have different performance
  implications for complex types (like iterators in STL).

---------------------------------------------------------------------

5. Common Use Cases:
--------------------
- Loop counters (for, while)
- Incrementing indexes or counters
- Navigating through arrays or containers

Example:
    for (int i = 0; i < 5; ++i)
        cout << i << " ";

*/
