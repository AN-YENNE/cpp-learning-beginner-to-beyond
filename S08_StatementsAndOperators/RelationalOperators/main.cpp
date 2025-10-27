// Section 8: Relational Operators
//
// This simple program demonstrates the use of relational operators in C++ such as >, >=, <, <=, ==, and !=
// These operators are used to compare two values and return a boolean result (true or false).

#include <iostream>
using namespace std;

int main() {

    int num1{}, num2{};

    cout << boolalpha; // print true/false instead of 1/0

    /************************************************************
     * 1) Basic relational comparisons between two integers
     ************************************************************/
    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;

    cout << "\nComparing " << num1 << " and " << num2 << ":" << endl;
    cout << num1 << " > " << num2  << " : " << (num1 > num2) << endl;
    cout << num1 << " >= " << num2 << " : " << (num1 >= num2) << endl;
    cout << num1 << " < " << num2  << " : " << (num1 < num2) << endl;
    cout << num1 << " <= " << num2 << " : " << (num1 <= num2) << endl;
    cout << num1 << " == " << num2 << " : " << (num1 == num2) << endl;
    cout << num1 << " != " << num2 << " : " << (num1 != num2) << endl;

    /************************************************************
     * 2) Range checking example
     ************************************************************/
    const int lower {10};
    const int upper {20};

    cout << "\nEnter an integer that is greater than " << lower << " : ";
    cin >> num1;
    cout << num1 << " > " << lower << " is " << (num1 > lower) << endl;

    cout << "\nEnter an integer that is less than or equal to " << upper << " : ";
    cin >> num1;
    cout << num1 << " <= " << upper << " is " << (num1 <= upper) << endl;

    cout << "\nProgram complete." << endl;

    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON RELATIONAL OPERATORS
=====================================================================

Relational operators compare two operands and return a boolean result:
true (condition satisfied) or false (condition not satisfied).

- These operators can be used with all built-in numeric types (int, float, double, etc.)
  and even characters (based on ASCII values).
- They are often used in conditions for `if`, `while`, and other control statements.

Example:
    if (score >= 90)
        cout << "Excellent!" << endl;

---------------------------------------------------------------------

Tips:
- Always use `==` for equality and `!=` for inequality.
  Using `=` instead of `==` is a common bug (it’s assignment, not comparison).
- Use `boolalpha` for more readable boolean output (prints true/false).
- Parentheses around comparisons make complex expressions clearer.

=====================================================================
*/
