// Section 8 Equality Operators (== and !=)
//
// This example demonstrates how equality (==) and inequality (!=) operators work with different data types such as integers, characters, and floating-point numbers.

#include <iostream>
using namespace std;

int main() {

    bool equal_result {false};
    bool not_equal_result {false};

    cout << boolalpha; // display true/false instead of 1/0

    /************************************************************
     * 1) Comparing Integers
     ************************************************************/
    int num1{}, num2{};

    cout << "=== Integer Comparison ===" << endl;
    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;

    equal_result = (num1 == num2);
    not_equal_result = (num1 != num2);

    cout << "Are the numbers equal? " << equal_result << endl;
    cout << "Are the numbers not equal? " << not_equal_result << endl;

    /************************************************************
     * 2) Comparing Characters
     ************************************************************/
    char char1{}, char2{};

    cout << "\n=== Character Comparison ===" << endl;
    cout << "Enter two characters separated by a space: ";
    cin >> char1 >> char2;

    equal_result = (char1 == char2);
    not_equal_result = (char1 != char2);

    cout << "Are the characters equal? " << equal_result << endl;
    cout << "Are the characters not equal? " << not_equal_result << endl;

    /************************************************************
     * 3) Comparing Doubles (Floating-point values)
     ************************************************************/
    double double1{}, double2{};

    cout << "\n=== Floating-point Comparison ===" << endl;
    cout << "Enter two decimal numbers separated by a space: ";
    cin >> double1 >> double2;

    equal_result = (double1 == double2);
    not_equal_result = (double1 != double2);

    cout << "Are the numbers equal? " << equal_result << endl;
    cout << "Are the numbers not equal? " << not_equal_result << endl;

    /************************************************************
     * 4) Comparing Integer with Double
     ************************************************************/
    cout << "\n=== Mixed-Type Comparison (int and double) ===" << endl;
    cout << "Enter an integer and a decimal number separated by a space: ";
    cin >> num1 >> double1;

    equal_result = (num1 == double1);
    not_equal_result = (num1 != double1);

    cout << "Are the values equal? " << equal_result << endl;
    cout << "Are the values not equal? " << not_equal_result << endl;

    cout << "\nProgram complete." << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON EQUALITY OPERATORS
=====================================================================

1. Equality (==)
   - Returns true if both operands are equal.
   - Example:
        int a = 10, b = 10;
        (a == b) → true

2. Inequality (!=)
   - Returns true if operands are not equal.
   - Example:
        int a = 10, b = 20;
        (a != b) → true

---------------------------------------------------------------------

3. Comparison Between Data Types:
   - Works for integers, characters, floating-point numbers, and booleans.
   - When comparing different types (like int and double),
     C++ performs implicit type conversion (coercion).

   Example:
        int x = 10;
        double y = 10.0;
        (x == y) → true  // int is promoted to double before comparison

---------------------------------------------------------------------

4. Floating-Point Precision Warning:
   - Floating-point comparisons can be unreliable due to rounding errors.
   - Two numbers that *look* equal may differ slightly in memory.

   Example:
        double a = 1.0 / 3;
        double b = 0.333333;
        (a == b) → false (depends on representation)

   Recommended approach:
        Use a tolerance (epsilon) for approximate comparison:
            const double epsilon = 1e-6;
            if (fabs(a - b) < epsilon)
                cout << "They are approximately equal.";

---------------------------------------------------------------------

5. Character Comparisons:
   - Characters are compared using their ASCII values.
   - Example:
        'A' == 'A' → true
        'A' == 'a' → false  (different ASCII values)

---------------------------------------------------------------------

6. Common Pitfalls:
   - Using '=' instead of '=='
       Example: if (a = b)  // assigns b to a, not compare!
   - Comparing floating-point numbers directly.
   - Forgetting implicit type conversion when mixing int/double.

---------------------------------------------------------------------
   - Be careful with floating-point comparisons.
   - Prefer `boolalpha` for human-readable true/false output.

=====================================================================
*/ 
