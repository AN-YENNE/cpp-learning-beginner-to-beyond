// Section 8: Logical Operators
//
// This program demonstrates how to use logical operators in C++, including AND (&&), OR (||), and NOT (!).

#include <iostream>
using namespace std;

int main() {

    cout << boolalpha; // Display boolean results as "true" or "false" instead of 1 or 0

    /************************************************************
     * 1) Range Checking with Logical AND (&&)
     ************************************************************/
    int num {};
    const int lower {10};
    const int upper {20};

    cout << "=== Range Checking Using Logical AND (&&) ===" << endl;
    cout << "Enter an integer - the bounds are " << lower << " and " << upper << " : ";
    cin >> num;

    bool within_bounds {false};
    within_bounds = (num > lower && num < upper);

    cout << num << " is between " << lower << " and " << upper << " : "
         << within_bounds << endl;

    /************************************************************
     * 2) Checking if a number is outside a range using OR (||)
     ************************************************************/
    cout << "\n=== Outside Range Check Using Logical OR (||) ===" << endl;
    cout << "Enter another integer - the bounds are " << lower << " and " << upper << " : ";
    cin >> num;

    bool outside_bounds {false};
    outside_bounds = (num < lower || num > upper);

    cout << num << " is outside " << lower << " and " << upper << " : "
         << outside_bounds << endl;

    /************************************************************
     * 3) Checking if a number is exactly on the boundary
     ************************************************************/
    cout << "\n=== On the Boundary Check Using Equality (==) ===" << endl;
    cout << "Enter another integer - the bounds are " << lower << " and " << upper << " : ";
    cin >> num;

    bool on_bounds {false};
    on_bounds = (num == lower || num == upper);

    cout << num << " is on one of the bounds (" << lower << " or " << upper << ") : "
         << on_bounds << endl;

    /************************************************************
     * 4) Weather Example: Using AND (&&) and OR (||)
     ************************************************************/
    cout << "\n=== Weather Example: Coat Decision Using Logical Operators ===" << endl;
    bool wear_coat {false};
    double temperature {};
    int wind_speed {};

    const int wind_speed_for_coat {25};      // wind speed threshold (mph)
    const double temperature_for_coat {45.0}; // temperature threshold (F)

    cout << "Enter the current temperature (in F): ";
    cin >> temperature;
    cout << "Enter the current wind speed (in mph): ";
    cin >> wind_speed;

    // Using OR: require coat if either condition is true
    wear_coat = (temperature < temperature_for_coat || wind_speed > wind_speed_for_coat);
    cout << "Do you need to wear a coat (using OR)? " << wear_coat << endl;

    // Using AND: require coat only if both conditions are true
    wear_coat = (temperature < temperature_for_coat && wind_speed > wind_speed_for_coat);
    cout << "Do you need to wear a coat (using AND)? " << wear_coat << endl;

    /************************************************************
     * 5) Demonstrating Logical NOT (!)
     ************************************************************/
    cout << "\n=== Using Logical NOT (!) ===" << endl;
    bool is_sunny {true};
    cout << "Is it sunny? " << is_sunny << endl;
    cout << "Is it NOT sunny? " << !is_sunny << endl;

    bool has_rain {false};
    cout << "Is it raining? " << has_rain << endl;
    cout << "Is it NOT raining? " << !has_rain << endl;

    cout << "\nProgram completed successfully." << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON LOGICAL OPERATORS AND EXPRESSION EVALUATION
=====================================================================

1. Logical Operators Overview
------------------------------
Operator | Meaning              | Example                | Result
--------- | -------------------- | ---------------------- | -------
!         | Logical NOT          | !(a > b)               | true if a <= b
&&        | Logical AND          | (x > 0 && y < 10)      | true only if both true
||        | Logical OR           | (a == b || c > d)      | true if either is true

All logical operators return a boolean value (true or false).

---------------------------------------------------------------------

2. Example of Logical AND (&&)
-------------------------------
int x = 15;
bool result = (x > 10 && x < 20);
Result: true (since both comparisons are true)

If either operand is false, the result is false.

---------------------------------------------------------------------

3. Example of Logical OR (||)
------------------------------
int x = 25;
bool result = (x < 10 || x > 20);
Result: true (since one condition is true)

If both operands are false, the result is false.

---------------------------------------------------------------------

4. Example of Logical NOT (!)
------------------------------
bool is_hot = false;
cout << !is_hot; // prints true

The NOT operator inverts the logical value.

---------------------------------------------------------------------

5. Short-Circuit Evaluation
----------------------------
When C++ evaluates logical expressions, it stops as soon as the result is known.

Example:
    expr1 && expr2 && expr3
    - If expr1 is false, expr2 and expr3 are not evaluated (since the result must be false).

    expr1 || expr2 || expr3
    - If expr1 is true, expr2 and expr3 are not evaluated (since the result must be true).

This can improve efficiency or prevent runtime errors.

Example:
    if (ptr != nullptr && *ptr == 100)
    The second condition is only checked if ptr is not null (avoiding a crash).

---------------------------------------------------------------------

6. Precedence and Associativity
-------------------------------
Precedence: 
  !  (highest)
  && 
  ||  (lowest)

Associativity: left-to-right for && and ||, right-to-left for !.

Example:
    !a && b || c
  is equivalent to
    ((!a) && b) || c

Use parentheses to clarify:
    if ((a && b) || c)

---------------------------------------------------------------------

7. Common Logical Conditions
-----------------------------
- Checking numeric ranges:
    (num >= lower && num <= upper)

- Checking outside a range:
    (num < lower || num > upper)

- Checking for equality at boundaries:
    (num == lower || num == upper)

- Combining comparisons:
    (x > 10 && x < 100 && y != 0)

---------------------------------------------------------------------

8. Mixed-Type Expressions
--------------------------
C++ converts operands to a common type automatically (type coercion).
Example:
    double avg = static_cast<double>(total) / count;

This applies to arithmetic expressions that feed into logical expressions as well.

---------------------------------------------------------------------

9. Tips
--------
- Always use parentheses for clarity.
- Use boolalpha when printing boolean values.
- Logical operators work only with conditions (not bitwise operations).
- Don’t confuse `&&` (logical AND) with `&` (bitwise AND), or `||` with `|`.

---------------------------------------------------------------------
*/
