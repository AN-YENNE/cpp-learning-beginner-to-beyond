// Section 8: Mixed Type Expressions
//
// This program demonstrates how C++ handles arithmetic expressions
// that involve different data types (integers, doubles, etc.).
// It shows how to safely compute the average of integer values
// using type casting to avoid integer division errors.

#include <iostream>
using namespace std;

int main() {
    int total {};                    // Stores the sum of the 3 integers
    int num1 {}, num2 {}, num3 {};   // Inputs from the user
    const int count {3};             // Number of integers to process

    cout << "Enter 3 integers separated by spaces: ";
    cin >> num1 >> num2 >> num3;

    total = num1 + num2 + num3;

    double average {0.0};

    // Method 1 (Preferred Modern Way): Use static_cast for clarity
    average = static_cast<double>(total) / count;

    // Method 2 (Old C-style cast): Not recommended in modern C++
    // average = (double)total / count;

    cout << "\n=== Computation Results ===" << endl;
    cout << "You entered: " << num1 << ", " << num2 << ", " << num3 << endl;
    cout << "Sum of the numbers: " << total << endl;
    cout << "Average of the numbers: " << average << endl;

    cout << "\nThank you for using this program!" << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
 NOTES: EXPRESSIONS AND STATEMENTS IN C++
=====================================================================

1️ Expressions
----------------
Definition:
- An expression is a combination of **operands** (like variables or constants)
  and **operators** (like +, -, *, /) that produces a single value.

Examples:
    5 + 3
    x * y + 2
    (a + b) / 2.0
    ++counter
    static_cast<double>(total) / count

Expressions are the *building blocks* of programs.
Every time a computation or value evaluation happens — that’s an expression.

In this program:
    total = num1 + num2 + num3;
    ➜ The expression (num1 + num2 + num3) computes a sum.

    average = static_cast<double>(total) / count;
    ➜ The expression (static_cast<double>(total) / count) computes a floating-point division.

-------------------------------------------------------------
Note: Integer Division vs Floating-Point Division
-------------------------------------------------------------
If both operands of a division are integers,
C++ performs **integer division**, which truncates the result.

Example:
    int x = 10, y = 3;
    cout << x / y;   // Output: 3, NOT 3.3333

To fix this, convert one operand to double:
    cout << static_cast<double>(x) / y;  // Output: 3.33333

-------------------------------------------------------------

2️ Statements
----------------
Definition:
- A statement is a **complete line of code** that performs an action.
- Statements are usually terminated with a semicolon.

Examples:
    int x = 5;                     // Declaration statement
    total = num1 + num2 + num3;    // Expression statement
    cout << total << endl;         // Output statement

Types of Statements in C++:
    - Expression statements       (e.g., a = b + c;)
    - Declaration statements      (e.g., int count = 0;)
    - Compound statements (blocks) (e.g., { ... })
    - Selection statements        (if, switch)
    - Iteration statements        (for, while, do-while)
    - Jump statements             (break, continue, return)
    - Exception handling          (try, throw, catch)

-------------------------------------------------------------

3️ Casting Between Types
--------------------------
C++ provides multiple ways to convert between types:

- Preferred: Modern C++ style:
    static_cast<double>(total)
    ➜ Explicit, type-safe, preferred

-Not Preferred: Old C style (less safe):
    (double)total

Use static_cast<> when converting between numeric types to make your intent clear.

-------------------------------------------------------------

4️ const Keyword
--------------------------
Declaring variables as `const` means their value cannot be changed.

Example:
    const int count {3};
    // 'count' is a constant; trying to modify it will cause a compile-time error.

Using `const` improves safety and self-documentation in your code.

-------------------------------------------------------------

5 Tips
--------------------------
- Always initialize your variables (use `{}` to zero-initialize safely).
- Use `static_cast` for numeric conversions.
- Use meaningful variable names like `total` and `average`.
- Use `const` for values that should never change.
- Prefer double when division may yield a fractional result.

-------------------------------------------------------------

6 Example of a Compound Statement
--------------------------
{
    int a = 5;
    int b = 10;
    cout << "Sum: " << a + b << endl;
}
This entire block is a compound statement containing multiple smaller statements.

=====================================================================
 SUMMARY
=====================================================================
✔ Expressions compute values.
✔ Statements perform actions.
✔ Integer division truncates — use type casting to fix it.
✔ static_cast<> is the modern, safe C++ casting style.
✔ Constants improve code clarity and prevent accidental modification.
=====================================================================
*/
