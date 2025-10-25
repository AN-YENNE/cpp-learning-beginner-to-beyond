// --------------------------------------------------------------
// Section 14 - Overloading Operators as Member Methods
//
// This example demonstrates how operator overloading lets
// objects behave more like built-in types.
// --------------------------------------------------------------
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    cout << boolalpha << endl;  // print true/false instead of 1/0

    Mystring alpha{"Alpha"};
    Mystring beta{"Beta"};

    Mystring clone = alpha;  // Copy constructor
    alpha.display();
    beta.display();

    // Equality comparison using overloaded ==
    cout << (alpha == beta) << endl;   // false
    cout << (alpha == clone) << endl;  // true

    // Unary minus (-): converts to lowercase
    Mystring lower_alpha = -alpha;
    lower_alpha.display();  // "alpha"

    // Binary plus (+): concatenation
    Mystring merged = alpha + "Beta";
    merged.display();       // "AlphaBeta"

    // Chaining multiple + operators
    Mystring merged2 = beta + " " + "Alpha";
    merged2.display();      // "Beta Alpha"

    Mystring merged3 = beta + " " + alpha + " " + "Gamma";
    merged3.display();      // "Beta Alpha Gamma"

    return 0;
}

/*
============================ NOTES =============================

Operator Overloading (as Member Methods)
---------------------------------------------------------------
C++ allows you to redefine how operators behave for user-defined types.

Example:
    Mystring a{"Hello"};
    Mystring b{"World"};
    Mystring c = a + b;   // Uses operator+

Unary Operators (one operand):
    - operator-()   → Used here to convert string to lowercase.
    Syntax:   Mystring lower = -a;

Binary Operators (two operands):
    - operator+()   → Used here to concatenate strings.
    - operator==()  → Used here to compare for equality.
    Syntax:   a + b, a == b

Overloading Steps:
---------------------------------------------------------------
1. Define the operator function as a member (or friend/global function).
   Syntax:
       Mystring Mystring::operator+(const Mystring& rhs) const;

2. Implement logic using private data (here, str pointer).

3. Return new Mystring objects for operations that create new strings.

4. For unary operators, no parameters are used.
   For binary operators, pass the right-hand operand.

Important Rules:
---------------------------------------------------------------
- You cannot create new operators in C++.
- Operator precedence and associativity are fixed.
- Return by value for new temporary results.
- Keep operations consistent with expected behavior.

Advantages:
---------------------------------------------------------------
- Makes custom objects intuitive to use (like built-ins).
- Increases code readability and expressiveness.

Example comparisons:
---------------------------------------------------------------
Without operator overloading:
    Mystring result = concat(toLower(a), b);

With operator overloading:
    Mystring result = -a + b;

This makes user-defined types behave naturally and readably.
*/
